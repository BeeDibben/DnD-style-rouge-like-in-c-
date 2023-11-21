#include <iostream>
#include <fstream>
#include <location.h>
#include <vector>



bool gameLoop = true;



std::vector<Location> loadedLocations;

std::vector<Settlement> loadedSettlements;



//Location currentLocation;

//Data management funcions

void cleanUp() {
	std::ofstream checkFile;

	checkFile.open("location.txt", std::ofstream::out | std::ofstream::trunc);

	checkFile.close();
}


void locationFileRead() {

}

void searchFile(int requestedId) {
	
}

void logFileWrite() {

}

void logFileRead() {

}


void initialiseMemoryManagement() {
	cleanUp();
}

void initialiseGameComponents() {
	srand((int)time(0));
}


void buildAdjacentLocations() {
	int selectType = rand() % 2 + 1;

	int idCounter = 0;
	std::ifstream locationFile;
	locationFile.open("Location.txt");

	while (locationFile.good())
	{
		idCounter++;
	}
	locationFile.close();

	if (selectType == 1) {
		Settlement(idCounter);
	}
}
//Gameplay functions



void intoduction() {

}

void setNewLocation() {

}


void describeArea() {
	
}



int main()
{
	initialiseMemoryManagement();

	initialiseGameComponents();

	Settlement mike(1);
	Settlement steve(2);

	mike.printStats();
	steve.printStats();

	mike.saveToLocation();
	steve.saveToLocation();


	//initialiseGameComponents();
	//intoduction();

	//while (gameLoop) {
	//	describeArea();

	//}


	//describeArea();
		//availableOptions();
		//if (quest) {
		//	addToQuestlist()
		//}
		//else (travel)
			//goToNewPlace()


	// intro
		// Start menu
			// Build character
		// Game logic
			// Setting
			// Quest prompts
			// Map additions (Map locations & sublocations)
			// What would you like to do/where would you like to go
				// Go to a new Place
					// Return to setting
				//Engage in quest
					// Attempt quest -- success
						// Return to the settlemt
						// Claim reward
						// Go to a new place
						// return to setting
					// Attempt quest -- Fail
						// Return to the settlement
						// go to a new place 
						// return to setting

}


