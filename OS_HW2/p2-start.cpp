/**
 * @author
 * @cwid  
 * @class  CSci 430, Fall 2021
 * @ide    Visual Studio 2019
 * @date   October 8, 2021
 * @assg   Programming Assignment #2
 *
 * @description Implement a simulation of a basic 3 process state system
 *    Ready, Running, Blocked.  Simulation includes a round-robin scheduler
 *    with time slice scheduling.  Need to implement a basic Process
 *    Control Block (PCB) in order to implement the round robin scheduler.
 *    Program will also have ready queues, and possible queues or other
 *    structures to keep track of blocked processes and the events they
 *    are waiting on.
 *
 */
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "ProcessManager.h"
using namespace std;

/** The process simulator.
 * The main loop for running a simulation.  We read simulation
 * events from a file
 *
 * @param simfilename The name of the file (e.g. simulaiton-01.sim) to open
 *     and read simulated event sequence from.
 * @param timeSliceQuantum The value to be used for system time slicing preemption
 *     for this simulation.
 */
//void runSimulation(string simfilename, int timeSliceQuantum)
void runSimulation(char* simfilename, int timeSliceQuantum)
{
	ifstream simeventsfile(simfilename);
	string command;
	int eventnum;
	ProcessManager process_manager = ProcessManager(timeSliceQuantum);
	ProcessManager::Command os_command;

	if (!simeventsfile.is_open())
	{
		cout << "Error: could not open simulator events file: " << simfilename << endl;
		exit(1);
	}

	while (!simeventsfile.eof())
	{
		simeventsfile >> command;
		eventnum = -1;
		// Handle the next simulated event we just read from the
		// simulation event file
		if (command == "cpu")
		{
			os_command = ProcessManager::Command::CPU;
			process_manager.update(os_command);
		}
		else if (command == "new")
		{
			os_command = ProcessManager::Command::NEW;
			process_manager.update(os_command);
		}
		else if (command == "done")
		{
			os_command = ProcessManager::Command::DONE;
			process_manager.update(os_command);
		}
		else if (command == "wait")
		{
			simeventsfile >> eventnum;
			os_command = ProcessManager::Command::WAIT;
			process_manager.update(os_command, eventnum);
		}
		else if (command == "event")
		{
			simeventsfile >> eventnum;
			os_command = ProcessManager::Command::EVENT;
			process_manager.update(os_command, eventnum);
		}
		else if (command == "exit")
		{
			// we use an explicit indicator to ensure simulation exits correctly
			os_command = ProcessManager::Command::EXIT;
			process_manager.update(os_command);
			break;
		}
		else
		{
			cout << "    ERROR: unknown command: " << command << endl;
			exit(0);
		}
	}

	simeventsfile.close();
}

/** Main entry point of simulator
 *  The main entry point of the process simulator.  We simply set up
 *  and initialize the environment, then call the appropriate function
 *  to begin the simulation.  We expect a single command line argument
 *  which is the name of the simulation event file to process.
 *
 * @param argc The argument count
 * @param argv The command line argument values. We expect argv[1] to be the
 *              name of a file in the current directory holding process events
 *              to simulate.
 */
int main(int argc, char** argv)
{
	int timeSliceQuantum = 0;
	
	// validate command line arguments
	if (argc != 3)
	{
		cout << "Error: expecting event file as first command line parameter and time slice quantum as second" << endl;
		cout << "Usage: " << argv[0] << " simeventfile.sim time_slice" << endl;
		exit(1);
	}

	// Assume second command line argument is the time slice quantum and parse it
	timeSliceQuantum = atoi(argv[2]);
	if (timeSliceQuantum <= 0)
	{
		cout << "Error: invalid time slice quantum received: " << timeSliceQuantum << endl;
		exit(1);
	}
	
	// Invoke the function to actually run the simulation
	runSimulation(argv[1], timeSliceQuantum);

	// if don't want to use command line do following.
	// need to recompile by hand since file 
	// name to get simulated events from is hard coded
	//std::string path = "simulation-01.sim";
	//runSimulation(path, 5);

	return 0;
}
