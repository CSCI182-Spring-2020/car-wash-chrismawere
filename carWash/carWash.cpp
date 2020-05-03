#include <time.h>
#include <stdlib.h>

#include <iostream>
#include "../../SimpleListApp/SimpleListApp/SimpleList.h"


using namespace std;

int main()
{
	bool occupied = true; //tests for whether car wash is being used or not
	int carsWashed = 0; //keeps track of the total cars washed
	int tunnelTime = 0; // amount of time in the wash tunnel
	int nWaitTime = 0; //Time the next car in line has to wait
	int simTime = 0; // Total time for the simulation
	int probability = 0; //Probabilty of cars coming in that the user enters
	int carsAddedToQueue = 0; // The number of cars that were added to the queue
	int carsLeftInLine = 0;
	simpleList sl; // uses the simple list queue

	cout << "Enter a simulation time (hours): ";
	cin >> simTime;
	cout << "Enter the probability: ";
	cin >> probability;
	simTime *= 60; // keeps time measurement in minutes
	int totalSimTime = simTime;
	cout << endl;

	while (simTime > 0) // as long as the simulation time is running
	{
		int q = rand() % 100; // give us a random integer and keep it beneath 99

		if (q < probability) // if the rand number is less than probabilty
		{
			sl.QueueItem(simTime); //add a new car into the queue
			carsAddedToQueue++; //adds a car to the queue
		}

		if (tunnelTime > 2) // it takes 3 mintutes for a car to completely wash 
		{
			carsWashed++; //after 3 mintutes add a car to total cars washed
			tunnelTime = 0; // resets the tunnel time
		}
		if (tunnelTime < 1) //if tunnel is open
		{
			try {
				int carInTime = sl.DeQueueItem(); //put a new car in the queue
				nWaitTime += carInTime - simTime; // amount of time to wait before a new car is added
			}
			catch (string & ex)
			{
				cout << ex.c_str() << endl; // Prints out the exception
			}

		}

		simTime--;
		tunnelTime++;
	}
	carsLeftInLine = carsAddedToQueue - carsWashed;

	cout << "The number of cars washed is: " << carsWashed << endl;
	if (carsWashed == 0) {
		cout << "0" << endl;
	}
	else
	{
		cout << "The average wait time was: " << (nWaitTime / carsWashed) << " Minutes" << endl;
	}
	cout << "The number of cars that didn't get washed is : " << carsLeftInLine << endl;

}