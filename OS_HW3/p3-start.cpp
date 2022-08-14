/** @file  p3-start.cpp
 *
 * @author Caleb McMillian
 *
 * @assg   Programming Assignment #3
 *
 * @desc Implement the deadlock detection algorithm.  Given a file
 *         that describes the current allocation A of resources in the
 *         system, and the current set of outstanding requests Q in
 *         the system, determine if a deadlock is present or not.  Use
 *         the algorithm given on p.276 in the Stallings textbook.
 *
 * @date   October 19, 2021
 */
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "MCProcessManager.h"

using namespace std;


// global constants
const int MAX_PROCESSES = 10; // I won't test your algorithm with simulations with more than 10 processes
const int MAX_RESOURCES = 10; // nor will I give a simulation to test with more than 10 resources


// simple struct to read in and hold the state of the system
typedef struct
{
	int numResources;
	int numProcesses;
	int available[MAX_RESOURCES]; // V available vector
	int alloc[MAX_PROCESSES][MAX_RESOURCES]; // A allocation matrix
	int request[MAX_PROCESSES][MAX_RESOURCES]; // Q request matrix
} State;


/** Read system state from file.
 * Given a file, read the current system state from the file.
 * The system state file is expected to hold the available vector V
 * the allocation matrix A and the request matrix Q.
 *
 * @param simfilename The name of the file to open and read state & request
 *         from.
 * @return state A new State structure is allocated and filled with the
 *         system state from the file.  A pointer to this allocated system
 *         state structure is returned as a result of calling this function.
 */

State* readSystemState(char* statefilename)
{
	ifstream simstatefile(statefilename);
	State* state;
	int r, p;

	// If we can't open file, abort and let the user know problem
	if (!simstatefile.is_open())
	{
		cout << "Error: could not open system state file: " << statefilename
			<< endl;
		exit(1);
	}

	// dynamically allocate a new State structure, to be filled in and returned
	state = new State;

	// Format of file is this (where m = numResource n = numProcesses
	//                         V = available vector
	//                         A = allocation matrix and
	//                         Q = request matrix)
	// m n
	// V1 V2 V3 ... Vm
	// A11 A12 ... A1m
	// ...
	// An1 An2 ... Anm
	// Q11 Q12 ... Q1m
	// ...
	// Qn1 Qn2 ... Qnm

	// First line, get m (numResources) and n (numProcesses)
	simstatefile >> state->numResources >> state->numProcesses;

	// Next line contains the available vector V
	for (r = 0; r < state->numResources; r++)
	{
		simstatefile >> state->available[r];
	}

	// Next n lines contain the allocation matrix A
	for (p = 0; p < state->numProcesses; p++)
	{
		for (r = 0; r < state->numResources; r++)
		{
			simstatefile >> state->alloc[p][r];
		}
	}

	// Next n lines contain the request matrix Q
	for (p = 0; p < state->numProcesses; p++)
	{
		for (r = 0; r < state->numResources; r++)
		{
			simstatefile >> state->request[p][r];
		}
	}

	// return the newly allocated and filled in system state
	return state;
}

/** Display a vector
 * Display a state vector to standard output
 *
 * @param len The number of items in the vector
 * @param v An array of integers of len items
 */
void displayVector(int len, int v[])
{
	int i;

	// Display a header
	for (i = 0; i < len; i++)
	{
		cout << "R" << i << " ";
	}
	cout << endl;

	// Display values
	for (i = 0; i < len; i++)
	{
		cout << setw(2) << v[i] << " ";
	}
	cout << endl;
}

/** Display a matrix
 * Display a state matrix to standard output
 *
 * @param rows The number of rows in the matrix
 * @param cols The number of cols in the matrix
 * @param m A 2 dimensional array of rows x cols integers
 */
void displayMatrix(int rows, int cols, int v[MAX_PROCESSES][MAX_RESOURCES])
{
	int r, c;

	// display column headers
	cout << "   "; // extra space over for row labels
	for (c = 0; c < cols; c++)
	{
		cout << "R" << c << " ";
	}
	cout << endl;

	// now display data in matrix
	for (r = 0; r < rows; r++)
	{
		cout << "P" << r << " ";
		for (c = 0; c < cols; c++)
		{
			cout << setw(2) << v[r][c] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/** Display state
 * Display the values of the resource vectors and matrices in the indicated
 * state structure
 *
 * @param state A pointer to a State struct whose info we should display on stdout.
 */
void displayState(State* s)
{
	cout << "numResources (m) = " << s->numResources << " ";
	cout << "numProcesses (n) = " << s->numProcesses << endl << endl;

	cout << "Available vector V:" << endl;
	displayVector(s->numResources, s->available);
	cout << endl;

	cout << "Allocation matrix A: " << endl;
	displayMatrix(s->numProcesses, s->numResources, s->alloc);
	cout << endl;

	cout << "Request matrix Q: " << endl;
	displayMatrix(s->numProcesses, s->numResources, s->request);
	cout << endl;

}

vector<int> getAllocationVector(State* state, int row)
{
	vector<int> allocation;
	for (int resource_index = 0; resource_index < state->numResources; resource_index++)
	{
		allocation.push_back(state->alloc[row][resource_index]);
	}
	return allocation;
}

vector<int> getRequestVector(State* state, int row)
{
	vector<int> requested;
	for (int resource_index = 0; resource_index < state->numResources; resource_index++)
	{
		requested.push_back(state->request[row][resource_index]);
	}
	return requested;
}

void fillProcessManager(MCProcessManager& process_manager, State* state)
{
	// populate availability vector
	for (int resource_index = 0; resource_index < state->numResources; resource_index++)
	{
		int available = (state->available)[resource_index];
		process_manager.pushAvailable(available);
	}

	// populate process vector
	for (int process_index = 0; process_index < state->numProcesses; process_index++)
	{
		vector<int> allocation = getAllocationVector(state, process_index);
		vector<int> requested = getRequestVector(state, process_index);
		process_manager.pushProcess(MCProcess(process_index, allocation, requested));
	}
}


/** The deadlock detector
 * The starting point for implementation of the deadlock detection algorithm.
 * We open and read in the allocation matrices here, then perform the deadlock detection.
 *
 * @ param statefilename A string with the name of the file holding the A and Q system state matrices
 */
void detectDeadlock(char* statefilename)
{
	State* state;

	state = readSystemState(statefilename);

	MCProcessManager process_manager;
	fillProcessManager(process_manager, state);
	
	if (process_manager.checkDeadlockedProcesses())
	{
		cout << "Deadlock: ";
		process_manager.printProcesses();
		cout << std::endl;
	}
	else
	{
		cout << "No Deadlock" << endl;
	}
}


/** Main entry point of deadlock detection.
 * The main entry point of the deadlock detection program.  This function
 * checks the command line arguments, and calls the detection function if correct
 * arguments were supplied.   We expect a single command line argument
 * which is the name of the file holding the allocation and request matrices
 * of the current state of the system.
 *
 * @param argc The argument count
 * @param argv The command line argument values. We expect argv[1] to be the
 *              name of a file in the current directory holding A and Q matrices.
 */
int main(int argc, char** argv)
//int main()
{
	if (argc != 2)
	{
	  cout << "Error: expecting state matrix file as first command line parameter" << endl;
	  cout << "Usage: " << argv[0] << " system-state.sim" << endl;
	  exit(1);
	}

	//char* filename = (char*) "state-01.sim";
	//detectDeadlock(filename);
	detectDeadlock(argv[1]);

	// if don't want to use command line do following. Need to recompile by hand since file
	// name to get simulated events from is hard coded.
	// Make sure you revert back to using command line before submitting your program.
	//detectDeadlock("state-01.sim");
}
