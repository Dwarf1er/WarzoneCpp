#pragma once
#include <list>
using namespace std;

// Observer Class 
class Observer
{
public:
	~Observer();
	virtual void Update() = 0;
	virtual void setSwitch(bool) = 0;
	bool _isEnabled;
protected:
	Observer();
};

//Subject Class 
class Subject
{
public:
	virtual void Attach(Observer*);
	virtual void Detach(Observer*);
	virtual void Notify();
	Subject();
	~Subject();
private:
	list<Observer*>* _observers;
};

class PhaseObserver : Observer
{
public:
	PhaseObserver();
	PhaseObserver(Subject*); //parameter: Model Pointer
	~PhaseObserver();
	void Update() override;
	void display();
	void setSwitch(bool) override;
private:
	Subject* _subject; //Model Pointer
};

class StatisticsObserver : Observer
{
public:
	StatisticsObserver();
	StatisticsObserver(Subject*); //parameter: Model Pointer
	~StatisticsObserver();
	void Update() override;
	void display();
	void setSwitch(bool) override;
private:
	Subject* _subject; //Model Pointer
};
