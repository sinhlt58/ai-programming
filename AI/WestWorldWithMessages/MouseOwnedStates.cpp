#include "MouseOwnedStates.h"

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
	return false;
}

/*AtHome state*/
AtHome* AtHome::GetInstance() {
	static AtHome instace;
	return &instace;
}

void AtHome::Enter(Mouse *mouse) {

}

void AtHome::Execute(Mouse *mouse) {

}

void AtHome::Exit(Mouse *mouse) {

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

}

void FindingFood::Execute(Mouse *mouse) {

}

void FindingFood::Exit(Mouse *mouse) {

}

bool FindingFood::OnMessage(Mouse *mouse, const Telegram &msg) {
	return false;
}

/*RunningFromCat state*/
RunningFromCat* RunningFromCat::GetInstance() {
	static RunningFromCat instace;
	return &instace;
}

void RunningFromCat::Enter(Mouse *mouse) {

}

void RunningFromCat::Execute(Mouse *mouse) {

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

