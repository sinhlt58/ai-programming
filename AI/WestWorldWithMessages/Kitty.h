#pragma once
#include "BaseGameEntity.h"
#include "fsm/State.h"
#include "fsm/StateMachine.h"
#include "KittyOwnedStates.h"

const int maxHunger = 5;

class Kitty : public BaseGameEntity
{
private:
	StateMachine<Kitty>* m_pStateMachine;
public:
	int m_iHunger;
	Kitty(int id) :BaseGameEntity(id), 
		m_iHunger(0)
	{
		m_pStateMachine = new StateMachine<Kitty>(this);
		m_pStateMachine->SetCurrentState(Sleeping::GetInstance());
		m_pStateMachine->SetGlobalState(KittyGolbalState::GetInstance());
	};

	void Update();

	StateMachine<Kitty>* GetFSM() { return m_pStateMachine; }

	int GetHunger() { return m_iHunger; };
	void SetHunger(int h) { m_iHunger = h; }
	virtual bool  HandleMessage(const Telegram& msg);
	~Kitty();
};

