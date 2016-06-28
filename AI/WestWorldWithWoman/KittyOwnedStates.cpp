#include "KittyOwnedStates.h"
#include "Kitty.h"
#include <iostream>
#include "misc/utils.h"

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






