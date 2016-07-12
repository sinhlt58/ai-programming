#pragma once
#include "BaseGameEntity.h"
#include "MouseOwnedStates.h"
#include "fsm/StateMachine.h"
#include "fsm/State.h"

class Mouse : public BaseGameEntity
{
private:
	StateMachine<Mouse> *m_pStateMachine;
public:
	int m_iHunger;//hunger high means very hungry.
	int m_iNumItem;
	int m_iMaxHunger;
	int m_iMaxItemInInventory;
	int m_iTmpDistance;

	Mouse(int id) :BaseGameEntity(id), m_iHunger(0), 
									m_iNumItem(0),
									m_iMaxHunger(5),
									m_iMaxItemInInventory(3),
									m_iTmpDistance(4){
		m_pStateMachine = new StateMachine<Mouse>(this);
		m_pStateMachine->SetCurrentState(AtHome::GetInstance());
		m_pStateMachine->SetGlobalState(MouseGlobalState::GetInstance());
	};
	~Mouse();

	virtual void  Update();
	virtual bool  HandleMessage(const Telegram& msg);

	StateMachine<Mouse>* GetFSM() { return m_pStateMachine; }

	bool IsHungry() { return m_iHunger == m_iMaxHunger; }
	bool IsFullInventory() { return m_iNumItem == m_iMaxItemInInventory; }
	bool IsEmptyInventory() { return m_iNumItem == 0; };
};

