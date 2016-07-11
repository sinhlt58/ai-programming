#include "KittyOwnedStates.h"
#include "Kitty.h"
#include <iostream>
#include "misc/utils.h"
#include "MessageTypes.h"
#include "MessageDispatcher.h"
#include "EntityNames.h"

using namespace std;
/*Sleeping state*/
Sleeping* Sleeping::GetInstance() {
	static Sleeping instance;
	return &instance;
}
void Sleeping::Enter(Kitty* kitty) {
	cout << GetNameOfEntity(kitty->ID()) << " Enter Sleeping state: Meo, so boring let's go to sleep\n";
}
void Sleeping::Execute(Kitty* kitty) {
	cout << GetNameOfEntity(kitty->ID()) << " Execute Sleeping state: Zzz...\n";
	kitty->SetHunger(kitty->GetHunger()+1);
	if (kitty->GetHunger() == maxHunger) {
		kitty->GetFSM()->ChangeState(Eating::GetInstance());
	}
}
void Sleeping::Exit(Kitty* kitty) {
	cout << GetNameOfEntity(kitty->ID()) << " Exit Sleeping state: Meo meo, I had a nightmare.\n";
}

bool Sleeping::OnMessage(Kitty* agent, const Telegram& msg) {
	return false;
}

/*Eating state*/
Eating* Eating::GetInstance() {
	static Eating instance;
	return &instance;
}

void Eating::Enter(Kitty* kitty) {
	cout << GetNameOfEntity(kitty->ID()) << " Enter Eating state: So hungry! Let's it something.\n";
}
void Eating::Execute(Kitty* kitty) {
	cout << GetNameOfEntity(kitty->ID()) << " Execute Eating state: Nhum nhum! the food are so good!!!\n";
	kitty->SetHunger(kitty->GetHunger()-1);
	if (kitty->GetHunger() == 0) {
		kitty->GetFSM()->ChangeState(Sleeping::GetInstance());
	}
}
void Eating::Exit(Kitty* kitty) {
	cout << GetNameOfEntity(kitty->ID()) << " Exit Eating state: Very good meal!!!!\n";
}

bool Eating::OnMessage(Kitty* agent, const Telegram& msg) {
	return false;
}

/*Peeing state*/
Peeing* Peeing::GetInstance() {
	static Peeing instance;
	return &instance;
}

void Peeing::Enter(Kitty* kitty) {
	cout << GetNameOfEntity(kitty->ID()) << " Enter Peeing state: I feel so bad @@ almost get wet all my pants!!\n";
}
void Peeing::Execute(Kitty* kitty) {
	cout << GetNameOfEntity(kitty->ID()) << " Execute Peeing state: I am making water hahaha!!!!\n";
	kitty->GetFSM()->RevertToPreviousState();
}
void Peeing::Exit(Kitty* kitty) {
	cout << GetNameOfEntity(kitty->ID()) << " Exit Peeing state: Finally, losing a lot of weights!!\n";
}

bool Peeing::OnMessage(Kitty* agent, const Telegram& msg) {
	return false;
}

/*Global state*/
KittyGolbalState* KittyGolbalState::GetInstance() {
	static KittyGolbalState instance;
	return &instance;
}

void KittyGolbalState::Enter(Kitty* kitty) {

}
void KittyGolbalState::Execute(Kitty* kitty) {
	if (RandFloat() < 0.1) {
		kitty->GetFSM()->ChangeState(Peeing::GetInstance());
	}
}
void KittyGolbalState::Exit(Kitty* kitty) {

}

bool KittyGolbalState::OnMessage(Kitty* kitty, const Telegram& msg) {
	SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	switch (msg.Msg) {
	case Msg_MouseMakeANoise:
		if (Helpers::MyRandInt() < 2) {
			cout << GetNameOfEntity(kitty->ID()) << ": I heard something or It was my sweet sweet imagination.\n";
		}
		else {
			cout << GetNameOfEntity(kitty->ID()) << ": A hah ! I heard you, here I come.\n";
			kitty->GetFSM()->ChangeState(ChasingMouse::GetInstance());
			Dispatch->DispatchMessage(
				SEND_MSG_IMMEDIATELY,
				kitty->ID(),
				ent_Mouse,
				Msg_CatHeardNoiseFromMouse,
				NO_ADDITIONAL_INFO
			);
		}
		break;
		return true;
	}
	return false;
}

/*Chasing mouse state*/
ChasingMouse* ChasingMouse::GetInstance() {
	static ChasingMouse instance;
	return &instance;
}

void ChasingMouse::Enter(Kitty *kitty) {
	cout << GetNameOfEntity(kitty->ID()) << " Enter Chasing state: Let's catch some mice.\n";
}

void ChasingMouse::Execute(Kitty *kitty) {
	cout << GetNameOfEntity(kitty->ID()) << " Execute Chasing state: Come here little dude, come here ...\n";
}

void ChasingMouse::Exit(Kitty *kitty) {
	cout << GetNameOfEntity(kitty->ID()) << " Exit Chasing state: Not thing to say here.\n";
}

bool ChasingMouse::OnMessage(Kitty *kitty, const Telegram &msg) {
	return false;
}

/*Killing mouse state*/
KillingMouse* KillingMouse::GetInstance() {
	static KillingMouse instance;
	return &instance;
}

void KillingMouse::Enter(Kitty *kitty) {

}

void KillingMouse::Execute(Kitty *kitty) {

}

void KillingMouse::Exit(Kitty *kitty) {

}

bool KillingMouse::OnMessage(Kitty *kitty, const Telegram &msg) {
	return false;
}

