#pragma once

#include <iostream>
#include <string>
#include <vector>

class Entity
{
public:
	Entity();
	~Entity();

	int attack(Entity attackedEntity) {

		int totalDamage = 0;

		for (int i = 0; i < this->numberOfAttacks; i++)
		{
			totalDamage += rand() % attackDamage + 1;
		}
		attackedEntity.takeDamage(attackDamage);
	}

	void takeDamage(int damageTaken) {
		health = health - damageTaken;
		if (health <= 0) {
			std::cout << this->name + " has died.";
			this->isAlive = false;
		}
	}

	void printHealth() {
		std::cout << this->name + "'s health is: " << this->health;
	}

private:
	std::string name;
	int health;
	int attackDamage;
	int numberOfAttacks;
	bool isAlive;
};

Entity::Entity()
{
}

Entity::~Entity()
{
}

class Player : public Entity
{
public:
	Player() : Entity() {
	}
	~Player() {}

private:
	
};

class Enemies : public Entity
{
public:
	Enemies() : Entity() {

	}
	~Enemies() {

	}

private:

};

