#include <iostream>
#include <fstream>
#include <location.h>
#include <vector>



bool gameLoop = true;

//std::vector<Location> 

//Location currentLocation;

//Data management funcions

void cleanUp() {
	std::ofstream checkFile;

	checkFile.open("location.txt", std::ofstream::out | std::ofstream::trunc);

	checkFile.close();
}

void locationFileWrite(const Location& givenLocation) {
	



	std::ofstream locationFile;

	Settlement* given = 


	locationFile.open("Location.txt", std::ios::app);
	
	if (givenLocation == "Settlement") {

		//Settlement* settlement = 

		//std::string input = std::to_string((Settlement*) givenLocation.getId()) + "," + (Settlement*)givenLocation.getName() + "," + (Settlement*)givenLocation.getType() + "," + std::to_string((Settlement*)givenLocation.getPopulation()) + "," + std::to_string((Settlement*)givenLocation.getFood()) + "," + std::to_string((Settlement*)givenLocation.getArmedCitizens()) + "," + std::to_string((Settlement*)givenLocation.getWealth()) + ";\n";

		//std::cout << input;

		//locationFile << input;
	}

	locationFile.close();
}

void locationFileRead() {

}

void searchFile(int requestedId) {
	
}

void logFileWrite() {

}

void logFileRead() {

}

//Gameplay functions

void initialiseMemoryManagement() {
	cleanUp();
}

void initialiseGameComponents() {
	srand((int)time(0));


}

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

	locationFileWrite(Settlement(1));
	locationFileWrite(Settlement(2));


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


