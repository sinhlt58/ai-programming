#include "KittyOwnedStates.h"
#include "Kitty.h"
#include <iostream>
#include "misc/utils.h"

/*Sleeping state*/
Sleeping* Sleeping::GetInstance() {
	static Sleeping instance;
	return &instance;
}
void Sleeping::Enter(Kitty* kitty) {
	std::cout << "Meo, so boring let's go to sleep\n";
}
void Sleeping::Execute(Kitty* kitty) {
	std::cout << "Zzz...\n";
	kitty->SetHunger(kitty->GetHunger()+1);
	if (kitty->GetHunger() == maxHunger) {
		kitty->GetFSM()->ChangeState(Eating::GetInstance());
	}
}
void Sleeping::Exit(Kitty* kitty) {
	std::cout << "Meo meo, I had a nightmare.\n";
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
	std::cout << "So hungry! Let's it something.\n";
}
void Eating::Execute(Kitty* kitty) {
	std::cout << "Nhum nhum! the food are so good!!!\n";
	kitty->SetHunger(kitty->GetHunger()-1);
	if (kitty->GetHunger() == 0) {
		kitty->GetFSM()->ChangeState(Sleeping::GetInstance());
	}
}
void Eating::Exit(Kitty* kitty) {
	std::cout << "Very good meal!!!!\n";
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
	std::cout << "I feel so bad @@ almost get wet all my pants!!\n";
}
void Peeing::Execute(Kitty* kitty) {
	std::cout << "I am making water hahaha!!!!\n";
	kitty->GetFSM()->RevertToPreviousState();
}
void Peeing::Exit(Kitty* kitty) {
	std::cout << "Finally, losing a lot of weights!!\n";
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

bool KittyGolbalState::OnMessage(Kitty* agent, const Telegram& msg) {
	return false;
}

/*Chasing mouse state*/
ChasingMouse* ChasingMouse::GetInstance() {
	static ChasingMouse instance;
	return &instance;
}

void ChasingMouse::Enter(Kitty *kitty) {

}

void ChasingMouse::Execute(Kitty *kitty) {

}

void ChasingMouse::Exit(Kitty *kitty) {

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

