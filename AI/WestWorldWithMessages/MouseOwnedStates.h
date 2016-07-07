#pragma once
#include "fsm/State.h"

class Mouse;

class MouseGlobalState : public State<Mouse> {
private:
	MouseGlobalState() {}
	MouseGlobalState(const MouseGlobalState&);
	MouseGlobalState& operator=(const MouseGlobalState&);
public:
	static MouseGlobalState* GetInstance();

	virtual void Enter(Mouse*);
	virtual void Execute(Mouse*);
	virtual void Exit(Mouse*);
	virtual bool OnMessage(Mouse*, const Telegram &msg);
};

class AtHome : public State<Mouse> {
private:
	AtHome() {}
	AtHome(const AtHome&);
	AtHome* operator=(const AtHome&);
public:
	static AtHome* GetInstance();

	virtual void Enter(Mouse*);
	virtual void Execute(Mouse*);
	virtual void Exit(Mouse*);
	virtual bool OnMessage(Mouse*, const Telegram &msg);
};

class FindingFood : public State<Mouse> {
private:
	FindingFood() {}
	FindingFood(const FindingFood&);
	FindingFood& operator=(const FindingFood&);
public:
	static FindingFood* GetInstance();

	virtual void Enter(Mouse*);
	virtual void Execute(Mouse*);
	virtual void Exit(Mouse*);
	virtual bool OnMessage(Mouse*, const Telegram &msg);
};

class RunningFromCat : public State<Mouse> {
private:
	RunningFromCat(){}
	RunningFromCat(const RunningFromCat&);
	RunningFromCat* operator=(const RunningFromCat&);
public:
	static RunningFromCat* GetInstance();
	
	virtual void Enter(Mouse*);
	virtual void Execute(Mouse*);
	virtual void Exit(Mouse*);
	virtual bool OnMessage(Mouse*, const Telegram &msg);
};

class DiedByCat : public State<Mouse> {
private:
	DiedByCat() {}
	DiedByCat(const DiedByCat&);
	DiedByCat* operator=(const DiedByCat&);
public:
	static DiedByCat* GetInstance();

	virtual void Enter(Mouse*);
	virtual void Execute(Mouse*);
	virtual void Exit(Mouse*);
	virtual bool OnMessage(Mouse*, const Telegram &msg);
};
