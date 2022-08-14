/**
 * @author 
 * @cwid   
 * @class  CSci 430, Fall 2021
 * @ide    Visual Studio 2019
 * @date   December 11, 2021
 * @assg   prog-05
 *
 * @description This program implements a simulation of process
 *    scheduling policies.  In this program, we implement round-robin
 *    scheduling, where the time slice quantum can be specified as
 *    as a command line parameter.  And we also implement shortest
 *    remaining time (SRT) scheduling policy
 */
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include "MCProcessManager.h"
using namespace std;

MCProcessManager createProcessManager(char* processFilename, int quantum)
{
	ifstream simprocessfile(processFilename);
	MCProcessManager process_manager = MCProcessManager(quantum);
	string processName;
	int arrivalTime;
	int serviceTime;

	// If we can't open file, abort and let the user know problem
	if (!simprocessfile.is_open())
	{
		cout << "Error: could not open process simulation file: "
			<< processFilename << endl;
		exit(1);
	}

	// Format of file is
	// ProcessName1 ArrivalTime1 ServiceTime1
	// ProcessName2 ArrivalTime2 ServiceTime2
	// ...
	// ProcessNameN ArrivalTimeN ServiceTimeN
	//
	// Where the name is any arbitray string identifier, and ArrivalTime
	// and ServiceTime are integer values
	MCProcess process;
	while (simprocessfile >> processName >> arrivalTime >> serviceTime)
	{
		// allocate a new process to hold information
		process = MCProcess(processName, arrivalTime, serviceTime);
		process_manager.push(process);
	}
	return process_manager;
}

MCProcessManager createProcessManager(char* processFilename)
{
	ifstream simprocessfile(processFilename);
	MCProcessManager process_manager = MCProcessManager();
	string processName;
	int arrivalTime;
	int serviceTime;

	// If we can't open file, abort and let the user know problem
	if (!simprocessfile.is_open())
	{
		cout << "Error: could not open process simulation file: "
			<< processFilename << endl;
		exit(1);
	}

	// Format of file is
	// ProcessName1 ArrivalTime1 ServiceTime1
	// ProcessName2 ArrivalTime2 ServiceTime2
	// ...
	// ProcessNameN ArrivalTimeN ServiceTimeN
	//
	// Where the name is any arbitray string identifier, and ArrivalTime
	// and ServiceTime are integer values
	MCProcess process;
	while (simprocessfile >> processName >> arrivalTime >> serviceTime)
	{
		// allocate a new process to hold information
		process = MCProcess(processName, arrivalTime, serviceTime);
		process_manager.push(process);
	}
	return process_manager;
}

/** Round robin scheduler simulator
 * The main routine for performing the round robin preemptive
 * scheduler simulator.  We expect the time quantum to already be
 * specified and given to us as the first parameter.  The file name
 * with the process arrival and service time information is given as
 * the second parameter.  We simulate preemptive round robin
 * scheduling of all of the processes until there are no longer any
 * processes left in the system (all processes have exceeded their
 * service time and have exited).
 *
 * @param processTable A pointer to a ProcessTable structure holding
 *      information about the processes, arrival times and durations
 *      that we are simulating execution of.
 * @param quantum An integer value holding the time slice quantum we
 *      are using for this simulation.
 */
void roundRobinScheduler(char* processFilename, int quantum)
{
	MCProcessManager process_manager = createProcessManager(processFilename, quantum);
	process_manager.start();
	process_manager.printStatistics();
}


/** shortest remaining time simulator
 * The main routine for performing the shortest remaining time
 * preemptive scheduler simulator.  The file name with the process
 * arrival and service time information is given as the first
 * parameter.  We simulate preemptive shortest remaining time
 * scheduling of all of the processes until there are no longer any
 * processes left in the system (all processes have exceeded their
 * service time and have exited).
 *
 * @param processTable A pointer to a ProcessTable structure holding
 *      information about the processes, arrival times and durations
 *      that we are simulating execution of.
 */
void shortestRemainingTime(char* processFileName)
{
	MCProcessManager process_manager = createProcessManager(processFileName);
	process_manager.start();
	process_manager.printStatistics();
}


/** Main entry point of round robin scheduler
 * The main entry point of the round robin scheduler simulator.  The main funciton
 * checks the command line arguments, and calls the simulation function if correct
 * arguments were supplied.   We expect two command line arguments, which are the
 * time slice quantum value we are to use for this preemptive scheduler simulation,
 * and the name of the simulation file holding the process arrival and service
 * time information.
 *
 * @param argc The argument count
 * @param argv The command line argument values. We expect argv[1] to be the
 *              time slice quantum parameter (int format) and argv[2] to be the
 *              name of the process simulation file (charcter string)
 */
int main(int argc, char** argv)
{
	string policy;
	int quantum = 0;

	// If not all parameters provides, abort and let user know of problem
	if (argc < 3 || argc > 4)
	{
		cout << "Error: expecting process simulation file and scheduling policy as command line parameters"
			<< endl;
		cout << "Usage: " << argv[0] << " process-file.sim [rr|srt] [quantum]" << endl;
		exit(1);
	}

	// just to confirm that process table loaded correctly.  You should
	// comment out or remove this as it is not asked for as part of the
	// output for the assignment simulation
	// displayProcessTable(processTable);

	// determine policy to simulate
	policy.assign(argv[2]);

	// perform simulation of indicated scheduling policy
	if (policy == "rr")
	{
		if (argc != 4)
		{
			cout << "Error: time quantum must be provided for round robin `rr` scheduling policy" << endl;
			exit(1);
		}
		quantum = atoi(argv[3]);
		if ((quantum <= 0) || (quantum > 1000))
		{
			cout << "Error: received bad time slice quantum parameter: " << argv[1] << endl;
			cout << "       valid values are integers in range from 1 to 1000" << endl;
			exit(1);
		}
		roundRobinScheduler(argv[1], quantum);
	}
	else if (policy == "srt")
	{
		shortestRemainingTime(argv[1]);
	}
	else
	{
		cout << "Error: unknown process scheduling policy: " << policy << endl;
	}
}
