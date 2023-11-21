#include <iostream>
#include <fstream>
#include <location.h>
#include <vector>



bool gameLoop = true;


int currentLocationID;


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


void buildAdjacentLocations(Location currentLocation) {
	int selectType = rand() % 2 + 1;

	if (currentLocation.getAdjectentIds().empty()) {
		std::ifstream locationFile;
		locationFile.open("Location.txt");

		int newLoactions = 4;

		for (int i = 0; i < newLoactions; i++)
		{
			int idCounter = 0;

			while (locationFile.good())
			{
				idCounter++;
			}
			locationFile.close();

			if (selectType == 1) {
				Settlement newLocation(idCounter);
				newLocation.printStats();

				currentLocation.appenedAdjacent(newLocation.getId());
			}
		}
		currentLocation.printAdjacentTileIDs();
	}
	
}


Location getLocation(int _id) {
	std::ifstream fileSearcher("Location.txt");

	int lineLocation = findIDInFile(_id);
	int onLine = 1;

	if (fileSearcher.is_open()) {
		while (onLine < lineLocation)
		{
			onLine++;
		}
		if (onLine == lineLocation) {
			
		}
	}



}

int findIDInFile(int _ID) {
	std::ifstream fileSearcher("Location.txt");
	std::string toFind = "ID:" + std::to_string(_ID);

	std::string reader;

	int lineCounter = 0;

	while (fileSearcher.good())
	{
		lineCounter++;

		fileSearcher >> reader;

		if (toFind.find(reader)) {
			fileSearcher.close();
			return lineCounter;
		}
	}
	fileSearcher.close();
	return -1;
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

	currentLocationID = mike.getId();

	buildAdjacentLocations();


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


