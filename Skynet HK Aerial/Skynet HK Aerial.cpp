// Skynet HK Aerial.cpp 
//Jon Ullom
//18-OCT-18
//Assignment: 03
//

#include "pch.h"
#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
		//this seeds the random location for the "bad guys" on the 8x8 grid//
		srand(static_cast<unsigned int>(time(0)));
		//this sets the location//
		int badGuyLocation = rand() % 64 + 1;
		//This keeps track of the searches//
		int searches = 0;
		//This sets the upper limit of the search//
		int searchGridHighNumber = 64;
		//This sets the bottom limit of the search//
		int searchGridLowNumber = 1;
		//This is the storage space for the answer to the algorithm//
		int gridSearch = 0;
		//This is the boolean variable to tell the program to stop running//
		bool targetAcquired = false;

		//This is the initial welcom screen to begin the search//
		cout << "Welcome to SkyNet HK Aerial Drone Search Suite.\n";
		cout << "your search will be done momentarily.\n";
		cout << "\n_______________________________________________________";
		
		//This begins the work of the program//
		do
		{
			//This adds to the number of searches for each iteration//
			++searches;
			//This is the algorithm for the binary search in the do while loop//
			int gridSearch = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
			//This checks if the search grid is correct or not and what to do//
			if (badGuyLocation > gridSearch)
			{
				cout << "\nSearch " << searches << ": Grid " << gridSearch << ": No Joy. Moving to next search.\n";
				cout << "_____________________________________________________________________________________________";
				//This changes the variable searchGridLowNumber if the search is too low//
				searchGridLowNumber= gridSearch+1; 
			}
			//This checks if the search grid is correct or not and what to do//
			else if (badGuyLocation < gridSearch)
			{
				cout << "\nSearch " << searches << ": Grid " << gridSearch << ": No Joy. Moving to next search.\n";
				cout << "_______________________________________________________________________________________________";
				//This changes the searchGridHighNumner if the search is too high//
				searchGridHighNumber= gridSearch-1;
			}
			else
			{
				//This is report for the when its not high or low and what to print//
				cout << "\nTarget aquired. Location: Grid- " << gridSearch << " Target found in " << searches << " searches.\n";
				cout << "_________________________________________________________________________________________________";
				targetAcquired = true;
			}

			//This ends the search//
		} while (!targetAcquired);
		//This is the output once search is complete//
		cout << "\nThank you for using SkyNet for your target hunting needs!";
		cout << "\n_________________________________________________________________\n";

		return 0;
	}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
