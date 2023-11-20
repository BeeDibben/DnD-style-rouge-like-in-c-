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
	int LocationID;

	std::string subClassType;
};




class Settlement : public Location
{
public:
	Settlement(int passId) : Location(passId, "Settlement") {
		buildSettlement();
	}

	Settlement(int passId, std::string passName, std::string passType, int passPopulation, int passFood, int passArmedCitizens, int passWealth) : Location(passId, "Settlement") {
		name = passName;
		type = passType;
		population = passPopulation;
		food = passFood;
		armedCitizens = passArmedCitizens;
		wealth = passWealth;
	}


	~Settlement() {

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

