#include "MouseOwnedStates.h"
#include <iostream>
#include "EntityNames.h"
#include "Mouse.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
using namespace std;

/*Mouse global state*/
MouseGlobalState* MouseGlobalState::GetInstance() {
	static MouseGlobalState instace;
	return &instace;
}

void MouseGlobalState::Enter(Mouse *mouse) {

}

void MouseGlobalState::Execute(Mouse *mouse) {

}

void MouseGlobalState::Exit(Mouse *mouse) {

}

bool MouseGlobalState::OnMessage(Mouse *mouse, const Telegram &msg) {
	switch (msg.Msg) {
		case Msg_CatHeardNoiseFromMouse:
			mouse->GetFSM()->ChangeState(RunningFromCat::GetInstance());
		break;
	}
	return false;
}

/*AtHome state*/
AtHome* AtHome::GetInstance() {
	static AtHome instace;
	return &instace;
}

void AtHome::Enter(Mouse *mouse) {
	cout << GetNameOfEntity(mouse->ID()) << " Enter At Home state: I feel so good when I am at home \n";
}

void AtHome::Execute(Mouse *mouse) {
	mouse->m_iHunger++;
	cout << GetNameOfEntity(mouse->ID()) << " Execute At Home state: My current hunger is "
		<< mouse->m_iHunger << endl;
	if (!mouse->IsEmptyInventory()) {
		mouse->m_iHunger--;
		mouse->m_iNumItem--;
	}
	if (mouse->IsHungry() && mouse->IsEmptyInventory()) {
		mouse->GetFSM()->ChangeState(FindingFood::GetInstance());
	}
}

void AtHome::Exit(Mouse *mouse) {
	cout << GetNameOfEntity(mouse->ID()) << " Exit At Home state: "
		<< "So hungry! Need to find something to eat.\n";
}

bool AtHome::OnMessage(Mouse *mouse, const Telegram &msg) {
	return false;
}

/*FindingFood state*/
FindingFood* FindingFood::GetInstance() {
	static FindingFood instace;
	return &instace;
}

void FindingFood::Enter(Mouse *mouse) {
	cout << GetNameOfEntity(mouse->ID()) << " Enter Finding Food state: Let's find food in the fringe.\n";
}

void FindingFood::Execute(Mouse *mouse) {
	cout << GetNameOfEntity(mouse->ID()) << " Execute Finding Food state: I have to be careful, can\'t make noise here.\n";
	
	if (Helpers::MyRandInt() < 2) {
		cout << GetNameOfEntity(mouse->ID()) << " Execute Finding Food state: Whoop!! I made a noise @@.\n";
		Dispatch->DispatchMessage(
			SEND_MSG_IMMEDIATELY,
			mouse->ID(),
			ent_Cute_Kitty,
			Msg_MouseMakeANoise,
			NO_ADDITIONAL_INFO
		);
	}

	if (Helpers::MyRandInt() < 5) {
		mouse->m_iNumItem++;
		cout << "I found a sweet cheese.\n";
	}

	if (mouse->IsFullInventory()) {
		cout << "Too much food now! I need to go back home.\n";
		mouse->GetFSM()->ChangeState(GoingHome::GetInstance());
	}
}

void FindingFood::Exit(Mouse *mouse) {
	cout << GetNameOfEntity(mouse->ID()) << " Exit Finding Food state: Nothing to say here.\n";
}

bool FindingFood::OnMessage(Mouse *mouse, const Telegram &msg) {
	return false;
}

/*GoingHome state*/
GoingHome* GoingHome::GetInstance() {
	static GoingHome instace;
	return &instace;
}

void GoingHome::Enter(Mouse *mouse) {
	cout << GetNameOfEntity(mouse->ID()) << " Enter Going Home state: Let's go home.\n";
}

void GoingHome::Execute(Mouse *mouse) {
	cout << GetNameOfEntity(mouse->ID()) << " Execute Going Home state: I'm goin home lalala.\n";
	mouse->GetFSM()->ChangeState(AtHome::GetInstance());
}

void GoingHome::Exit(Mouse *mouse) {
	cout << GetNameOfEntity(mouse->ID()) << " Exit Going Home state: It was long trip.\n";
}

bool GoingHome::OnMessage(Mouse *mouse, const Telegram &msg) {
	return false;
}

/*RunningFromCat state*/
RunningFromCat* RunningFromCat::GetInstance() {
	static RunningFromCat instace;
	return &instace;
}

void RunningFromCat::Enter(Mouse *mouse) {
	cout << GetNameOfEntity(mouse->ID()) << " Oh GOD! He heard me. Let's get the heck out of here.\n";
}

void RunningFromCat::Execute(Mouse *mouse) {
	cout << GetNameOfEntity(mouse->ID()) << " Get away from me you stupid cat...\n";
}

void RunningFromCat::Exit(Mouse *mouse) {

}

bool RunningFromCat::OnMessage(Mouse *mouse, const Telegram &msg) {
	return false;
}

/*DiedByCat state*/
DiedByCat* DiedByCat::GetInstance() {
	static DiedByCat instace;
	return &instace;
}

void DiedByCat::Enter(Mouse *mouse) {

}

void DiedByCat::Execute(Mouse *mouse) {

}

void DiedByCat::Exit(Mouse *mouse) {

}

bool DiedByCat::OnMessage(Mouse *mouse, const Telegram &msg) {
	return false;
}

