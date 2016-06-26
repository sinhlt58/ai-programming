#pragma once
#include "State.h"

class Kitty;

class Sleeping : public State<Kitty> {
private:
	Sleeping() {};
	Sleeping(const Sleeping&);
	Sleeping& operator=(const Sleeping&);
public:
	static Sleeping* GetInstance();

	virtual void Enter(Kitty*);
	virtual void Execute(Kitty*);
	virtual void Exit(Kitty*);
};

class Eating : public State<Kitty> {
private:
	Eating() {};
	Eating(const Eating&);
	Eating& operator=(Eating&);
public:
	static Eating* GetInstance();

	virtual void Enter(Kitty*);
	virtual void Execute(Kitty*);
	virtual void Exit(Kitty*);
};


