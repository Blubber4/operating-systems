/** @file  p1-start.cpp
 *
 * @author 
 * @cwid   
 * @assg   Programming Assignment #1
 * @date   September 24, 2021
 * @ide    Visual Studio 2019
 *
 * @description Example of using the C++ Standard Template Library
 *    (STL) classes to implement solution for assignment 01.
 *    In this assignment, we maintain a stack and a queue,
 *    and demonstrate instantiationg STL data stuctures that
 *    can be used as stacks and queues to simulate items
 *    being added and removed from each data structure as
 *    requested by the simulation.
 */
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "MCStack.h"
#include "MCQueue.h"
using namespace std;

void enqueue(int queueItem, MCQueue& queue)
{
    cout << "Enqueue  : " << queueItem << endl;
    queue.enqueue(queueItem);
}

void dequeue(MCQueue& queue)
{
    try
    {
        cout << "Dequeue  : " << queue.dequeue() << endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
}

void push(std::string stackItem, MCStack& stack)
{
    cout << "Push     : " << stackItem << endl;
    stack.push(stackItem);
}

void pop(MCStack& stack)
{
    try
    {
        cout << "Popped   : " << stack.pop() << endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
}

/** The stack/queue simulator
 * The main loop for running tests of the queue data type.
 * The file contains commands to enqueue and deque items
 * from the queue.
 *
 * @param simfilename The name of the file (e.g. simfile-01.sim) to
 *     open and read commands to test the queue and stack data type
 *     on.
 */
void runSimulation(char* simfilename)
{
    ifstream simfile(simfilename);
    string command;
    int queueItem;
    string stackItem;
    MCStack stack;
    MCQueue queue;

    // open the input simulation file to read and process simulation
    // comands
    cout << "Processing stack/queue simulation file: "
        << simfilename << endl;
    if (!simfile.is_open())
    {
        cout << "Error: could not open simulation file: "
            << simfilename << endl;
        exit(1);
    }

    // read and process stack/queue simulation comands line by line
    while (!simfile.eof())
    {
        simfile >> command;

        if (command == "enqueue")
        {
            simfile >> queueItem;
            enqueue(queueItem, queue);
        }
        else if (command == "dequeue")
        {
            dequeue(queue);
        }
        else if (command == "push")
        {
            simfile >> stackItem;
            push(stackItem, stack);
        }
        else if (command == "pop")
        {
            pop(stack);
        }
        else if (command == "exit") // normal termination of simulation
        {
            cout << "Simulation ends" << endl;
            exit(0);
        }
        else
        {
            cout << "ERROR: unknown command: " << command << endl;
            exit(1);
        }

        // you should display the contents of your stack and queue
        // here, after processing the simulation command
        cout << "Stack    : " << stack << endl;
        cout << "Queue    : " << queue << endl;
        cout << endl;
    }
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
 *
 * @returns int Returns 0 to OS to indicate successful completion, or non zero
 *              value to indicate an error.
 */
int main(int argc, char** argv)
{
    // validate command line arguments
    if (argc != 2)
    {
        cout << "Error: expecting simulation file as first command line parameter" << endl;
        cout << "Usage: " << argv[0] << " simfile.sim" << endl;
        exit(1);
    }

    // Invoke the function to actually run the simulation
    runSimulation(argv[1]);
    //runSimulation((char*)"simfile-01.sim");

    // return status 0 to indicate successful program completion
    return 0;
}
