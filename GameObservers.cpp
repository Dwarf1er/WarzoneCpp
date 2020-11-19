#include "GameObservers.h"
#include <iostream>
#include "GameEngine.h"

Observer::~Observer() {}

Observer::Observer() {};

Subject::Subject()
{
	_observers = new list<Observer*>;
}

Subject::~Subject()
{
	delete _observers;
}

void Subject::Attach(Observer* o)
{
	_observers->push_back(o);
}

void Subject::Detach(Observer* o)
{
	_observers->remove(o);
}

void Subject::Notify()
{
	list<Observer*>::iterator i = _observers->begin();

	for (; i != _observers->end(); ++i)
	{
		(*i)->Update();
	}
}

PhaseObserver::PhaseObserver() {}

PhaseObserver::PhaseObserver(GameEngine* s)
{
	_subject = s;
	_subject->Attach(this);
}

PhaseObserver::~PhaseObserver()
{
	_subject->Detach(this);
}

void PhaseObserver::Update()
{
	display();
}

void PhaseObserver::display()
{
	if (!_subject->enableObserver) 
		return;

	std::cout << "\n" << "======================================= OBSERVER =======================================" << "\n";
	
	std::map<Player*, int> armiesCountsBasedOnTerritories = _subject->armiesCountsBasedOnTerritories;
	std::map<Player*, int> armiesCountsMinimums = _subject->armiesCountsMinimums;
	std::map<Player*, OrderData> issueOrderDetails = _subject->issueOrderDetails;
	int phaseIndex = _subject->phaseIndex;

	//Reinforcement Phase
	if (phaseIndex == 0)
	{
		std::cout << "Reinforcement Phase" << "\n";
		for (std::map<Player*, int>::value_type& t : armiesCountsBasedOnTerritories)
			std::cout << "Player " << t.first->getPlayerID() << ": " << t.second << " armies based on territory added" << "\n";
		for (std::map<Player*, int>::value_type& t : armiesCountsMinimums)
			std::cout << "Player " << t.first->getPlayerID() << ": " << t.second << " minimum added" << "\n";
	}

	//Issue Order Phase
	if (phaseIndex == 1)
	{
		std::cout << "Issue Order Phase" << "\n";
		for (std::map<Player*, OrderData>::value_type& t : issueOrderDetails)
			std::cout << "Player " << t.first->getPlayerID() << ": "
			<< t.second.armyNum << " armies"
			<< " from " << t.second.sourceID
			<< " to " << t.second.targetID
			<< "\n";
	}

	cout << "========================================================================================" << "\n\n";
}

StatisticsObserver::StatisticsObserver() {}

StatisticsObserver::StatisticsObserver(Subject* s)
{
	_subject = s;
	_subject->Attach(this);
}

StatisticsObserver::~StatisticsObserver()
{
	_subject->Detach(this);
}

void StatisticsObserver::Update()
{
	display();
}

void StatisticsObserver::display()
{
	//get variables from model
	cout << endl; //add variables
}

