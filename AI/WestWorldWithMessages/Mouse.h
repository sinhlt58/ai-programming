#pragma once
#include "BaseGameEntity.h"
#include "Locations.h"
#include "misc/ConsoleUtils.h"
#include "MinerOwnedStates.h"
#include "fsm/StateMachine.h"
#include "fsm/State.h"

class Mouse : public BaseGameEntity
{
private:
	int m_iHunger;
	StateMachine<Mouse> *m_pStateMachine;
public:
	Mouse(int id) :BaseGameEntity(id), m_iHunger(0){
			
	};
	~Mouse();

	virtual void  Update();
	virtual bool  HandleMessage(const Telegram& msg);
};

