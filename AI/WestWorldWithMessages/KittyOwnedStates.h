#pragma once
#include "fsm/State.h"
#include "Helpers.h"

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

class ChasingMouse : public State<Kitty> {
private:
	ChasingMouse() {};
	ChasingMouse(const ChasingMouse&);
	ChasingMouse& operator=(const ChasingMouse&);
public:
	static ChasingMouse* GetInstance();

	virtual void Enter(Kitty*);
	virtual void Execute(Kitty*);
	virtual void Exit(Kitty*);
	virtual bool OnMessage(Kitty*, const Telegram &msg);
};

class KillingMouse : public State<Kitty> {
private:
	KillingMouse() {};
	KillingMouse(const KillingMouse&);
	KillingMouse& operator=(const KillingMouse&);
public:
	static KillingMouse* GetInstance();

	virtual void Enter(Kitty*);
	virtual void Execute(Kitty*);
	virtual void Exit(Kitty*);
	virtual bool OnMessage(Kitty*, const Telegram &msg);
};
