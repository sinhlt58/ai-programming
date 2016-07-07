#include "Mouse.h"

Mouse::~Mouse()
{
}

void Mouse::Update() {
	m_pStateMachine->Update();
}

bool Mouse::HandleMessage(const Telegram& msg) {
	return false;
}