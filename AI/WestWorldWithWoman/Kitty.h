#pragma once
#include "BaseGameEntity.h"
#include "State.h"
#include "StateMachine.h"

class Kitty : public BaseGameEntity
{
private:
	int hunger;
	StateMachine<Kitty>* m_pStateMachine;
public:
	Kitty(int id) :BaseGameEntity(id), 
				  hunger(0) 
	{
		m_pStateMachine = new StateMachine<Kitty>(this);
	};
	~Kitty();
};

