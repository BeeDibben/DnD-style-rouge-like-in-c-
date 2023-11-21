#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <cstdlib>

class Location
{
public:
	Location(int id, std::string subClassType){
		this->LocationID = id;
		this->subClassType = subClassType;
	}
	
	~Location() {}
	;


	int getId() {
		return this->LocationID;
	}

	std::string getSubclassType() {
		return this->subClassType;
	}



protected:
	//unique datapoints
	int LocationID;

	std::string subClassType;

	std::vector<int> adjacentTiles;

	//Global constant variables:

	std::string saveLocation = "Location.txt";


};


class Terrain : public Location {
public:
	Terrain(const int Id) : Location(Id, "Terrain") {
		buildType();
		buildStats();
	}

	Terrain(const int Id,const std::string _type,const int _monsters,const int _food,const int _loot) : Location(Id, "Terrain") {
		type = _type;
		monsters = _monsters;
		food = _food;
	}

	~Terrain(){}

	void buildType() {
		int selection = rand() % 7;

		switch (selection)
		{
		case 0:
			type = "Plains";
			break;
		case 1:
			type = "Forest";
			break;
		case 3:
			type = "Mountains";
			break;
		case 4:
			type = "Swamp";
			break;
		case 5:
			type = "Monster_Camp";
		default:
			type = "Plains";
			break;
		}
	}

	void buildStats() {
		if (type == "Plains") {
			monsters = rand() % 4;
			food = rand() % 10 + 10;
			loot = rand() % 9;
		}
		if (type == "Forest") {
			monsters = rand() % 2;
			food = rand() % 25 + 15;
			loot = rand() % 3;
		}
		if (type == "Mountains") {
			monsters = rand() % 4;
			food = rand() % 5;
			loot = rand() % 20;
		}
		if (type == "Swamp") {
			monsters = rand() % 2;
			food = rand() % 10 + 10;
			loot = rand() % 11;
		}
		if (type == "Monster_Camp") {
			monsters = rand() % 8 + 2;
			food = rand() % 30 + 20;
			loot = rand() % 30 + 30;
		}
	
	}

private:
	std::string type;
	
	int monsters;

	int food;
	int loot;
};


class Settlement : public Location
{
public:

	Settlement(const int passId) : Location(passId, "Settlement") {
		buildSettlement();
		saveToLocation();
	}

	Settlement(const int passId, const std::string passName, const std::string passType,const int passPopulation,const int passFood,const int passArmedCitizens,const int passWealth) : Location(passId, "Settlement") {
		name = passName;
		type = passType;
		population = passPopulation;
		food = passFood;
		armedCitizens = passArmedCitizens;
		wealth = passWealth;
	}


	~Settlement() {

	}


	void saveToLocation() {
		std::ofstream locationFile;

		std::string input;

		locationFile.open("Location.txt", std::ios::app);

		input = std::to_string(this->LocationID) + "," + this->subClassType + "," + this->name + "," + this->type + "," + std::to_string(this->population) + "," + std::to_string(this->armedCitizens) + "," + std::to_string(this->wealth) + ";";

		locationFile << input << std::endl;

		locationFile.close();

	}

	

	void buildSettlement() {
		name = buildName();
		type = buildSettlementType();
		population = buildPopulation();
		food = buildFood();
		armedCitizens = buildArmedCitizens();
		wealth = buildWealth();



	}

	void printStats() {
		std::cout << "ID: " << this->LocationID;
		std::cout << "Name: " << name << "\n";
		std::cout << "Settlement Type: " << type << "\n";
		std::cout << "Population count: "  << population << "\n";
		std::cout << "Food count: " << food << "\n";
		std::cout << "Armed citizens: " << armedCitizens << "\n";
		std::cout << "Wealth: " << wealth << "\n";
	}


	std::string buildSettlementType() {
		;

		int type = rand() % 5 + 1;

		switch (type)
		{
		case 1:
			return "Hamlet";
			break;
		case 2:
			return "Village";
			break;
		case 3:
			return "Town";
			break;
		case 4:
			return "Large Town";
			break;
		case 5: 
			return "City";
			break;
		default:
			std::cout << "Error building Settlement\n";
			return "Failiure to build name";
			break;
		}
	}

	int buildPopulation() {
		int givenPopulation;
		;

		if (type == "Hamlet") {
			givenPopulation = rand() % 20 + 5;
			return givenPopulation;
		}

		if (type == "Village") {
			givenPopulation = rand() % 50 + 25;
				return givenPopulation;
		}
		if (type == "Town") {
			givenPopulation = rand() % 125 + 75;
				return givenPopulation;
		}
		if (type == "Large Town") {
			givenPopulation = rand() % 200 + 200;
				return givenPopulation;
		}
		if (type == "City") {
			givenPopulation = rand() % 600 + 400;
				return givenPopulation;
		}
		
		std::cout << "Error building population\n";		
		return -1;
	}

	int buildFood() {
		;
		int calcFood = rand() % population + (int)(ceil(population / 5));
		return calcFood;
	}

	int buildArmedCitizens() {
		int army;
		;

		army = rand() % ((int)ceil(population / 1.8)) + ((int)ceil(population / 10));
		return army;
	}

	int buildWealth() {
		;

		int gold;

		gold = rand() % ((int)ceil(population * 3.5)) + ((int)ceil(population / 8));
		return gold;
	}

	std::string buildName() {
		;
		
		std::string fullName;
		
		std::string prefix;
		std::string suffix;

		std::vector<std::string> prefixes{"Frost","Shadow","Ember","Storm","Star","Iron","Moon","Sun","Thorn","Dragon's","Mist","Silver","Blood","Fire","Sky","Raven's","Crystal","Mystic","Golden","Whisper","Echo","Night","Thunder","Celestial","Winter","Ashen","Lumin","Verdant","Solar","Arcane","Emerald","Amber"};
		std::vector<std::string> suffixes{ "Holm","Vale","Forge","Watch","Haven","Wood","Shadow","Spire","Field","Roost","Peak","Stone","Hold","Reach","Fang","Fall","Water","Nest","Glade","Star","Ember","Frost","Harbor","Citadel","Grove","Crest","Enclave","Barrow","Rest" };

		//"Holm","Vale","Forge","Watch","Haven","Wood","Shadow","Spire","Field","Roost","Peak","Stone","Hold","Reach","Fang","Fall","Water","Nest","Glade","Star","Ember","Frost","Harbor","Citadel","Grove","Crest","Enclave","Barrow","Rest"



		int prefixSelector = rand() % (prefixes.size() - 1);
		int suffixSelector = rand() % (suffixes.size() - 1);


		prefix = prefixes[prefixSelector];


		suffix = suffixes[suffixSelector];



		fullName = prefix + " " + suffix;

		return fullName;

	}

	


	//Utilities

	int getId() {
		return this->LocationID;
	}

	std::string getName() {
		return this->name;
	}

	std::string getType() {
		return this->type;
	}

	int getPopulation() {
		return this->population;
	}

	int getFood() {
		return this->food;
	}

	int getArmedCitizens() {
		return this->armedCitizens;
	}

	int getWealth() {
		return this->wealth;
	}



private:
	std::string name;

	std::string type;

	int population;
	int food;
	int armedCitizens;
	int wealth;
	


};

