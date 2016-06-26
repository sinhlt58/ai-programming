#pragma once
#include "BaseGameEntity.h"
#include "State.h"
#include "StateMachine.h"

const int maxHunger = 5;

class Kitty : public BaseGameEntity
{
private:
	int m_iHunger;
	StateMachine<Kitty>* m_pStateMachine;
public:
	Kitty(int id) :BaseGameEntity(id), 
		m_iHunger(maxHunger)
	{
		m_pStateMachine = new StateMachine<Kitty>(this);
	};

	void Update();

	StateMachine<Kitty>* GetFSM() { return m_pStateMachine; }

	int GetHunger() { return m_iHunger; };
	void SetHunger(int h) { m_iHunger = h; }

	~Kitty();
};

