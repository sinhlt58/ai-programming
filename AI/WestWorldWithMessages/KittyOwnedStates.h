#pragma once
#include "fsm/State.h"

class Kitty;
struct Telegram;

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
	virtual bool OnMessage(Kitty* agent, const Telegram& msg);
};

class Eating : public State<Kitty> {
private:
	Eating() {};
	Eating(const Eating&);
	Eating& operator=(const Eating&);
public:
	static Eating* GetInstance();

	virtual void Enter(Kitty*);
	virtual void Execute(Kitty*);
	virtual void Exit(Kitty*);
	virtual bool OnMessage(Kitty* agent, const Telegram& msg);
};

class Peeing : public State<Kitty> {
private:
	Peeing() {};
	Peeing(const Peeing&);
	Peeing& operator=(const Peeing&);
public:
	static Peeing* GetInstance();

	virtual void Enter(Kitty*);
	virtual void Execute(Kitty*);
	virtual void Exit(Kitty*);
	virtual bool OnMessage(Kitty* agent, const Telegram& msg);
};

class KittyGolbalState : public State<Kitty> {
private:
	KittyGolbalState() {};
	KittyGolbalState(const KittyGolbalState&);
	KittyGolbalState& operator=(const KittyGolbalState&);
public:
	static KittyGolbalState* GetInstance();

	virtual void Enter(Kitty*);
	virtual void Execute(Kitty*);
	virtual void Exit(Kitty*);
	virtual bool OnMessage(Kitty* agent, const Telegram& msg);
};


