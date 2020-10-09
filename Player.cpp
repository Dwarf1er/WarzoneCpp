#pragma once
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

//constructors
	//default constructor
Player::Player() : playerTerritories(), playerCards(nullptr), playerOrders(nullptr), playerArmies(0), playerID(0) {
}

//parametrized constructor
Player::Player(vector<Territory*> playerTerritories_, Hand* playerCards_, Order* playerOrders_, int playerArmies_, int playerID_) : playerTerritories(playerTerritories_), playerCards(playerCards_), playerOrders(playerOrders_), playerArmies(playerArmies_), playerID(playerID_) {
	//remove territories from the global list!!!!
}
//copy constructor
Player::Player(const Player& p) : playerTerritories(p.playerTerritories), playerCards(new Hand(*(p.playerCards))), playerOrders(new Order(*(p.playerOrders))), playerArmies(p.playerArmies), playerID(p.playerID) {
}

//destructor
Player::~Player() {
	for (Territory* t : playerTerritories) {
		delete t;
		t = nullptr;
	}

	delete playerCards;
	playerCards = nullptr;
	delete playerOrders;
	playerOrders = nullptr;

	playerArmies = 0;
	playerID = 0;
}

//accessors
vector<Territory*> Player::getPlayerTerritories() {
	return playerTerritories;
}

Hand* Player::getPlayerCards() {
	return playerCards;
}

Order* Player::getPlayerOrders() {
	return playerOrders;
}

int Player::getPlayerArmies() {
	return playerArmies;
}

//mutators
void Player::setPlayerTerritories(vector<Territory*> playerTerritories_) {
	for (Territory* t : playerTerritories_) {
		this->playerTerritories.push_back(t);
	}
}

void Player::setPlayerCards(Hand* playerCards_) {
	playerCards = playerCards_;
}

void Player::setPlayerOrders(Order* playerOrders_) {
	playerOrders = playerOrders_;
}

void Player::setPlayerArmies(int playerArmies_) {
	playerArmies = playerArmies_;
}

//operator overloading
	//assignment operator overloading
void Player::operator=(const Player& p) {
	playerTerritories = p.playerTerritories;
	playerCards = new Hand(*(p.playerCards));
	playerOrders = new Order(*(p.playerOrders));
	playerArmies = p.playerArmies;
	playerID = p.playerID;
}

//stream insertion operator overloading
ostream& operator<<(ostream& out, const Player& p) {
	out << "Player ID: " << p.playerID << endl;
	for (Territory* t : p.playerTerritories) {
		out << "Territories: " << *t << endl;
	}
	//out << "Player Hand: " << p.playerCards << endl;
	//out << "Player Orders" << p.playerOrders << endl;
	return out;
}

istream& operator>>(istream& in, Player& p) {
	//in >> p.playerTerritories;
	//in >> p.playerCards;
	//in >> p.playerOrders;
	in >> p.playerID;
	return in;
}

//required methods
void Player::issueOrder(Order* order) {
	this->setPlayerOrders(order);
}

vector<Territory*> Player::toDefend() {
	return this->getPlayerTerritories();
}

//vector<Territory*> Player::toAttack() {
	//return some random territories that are available
//}