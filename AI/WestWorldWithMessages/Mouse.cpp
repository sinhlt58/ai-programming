#include "Mouse.h"
#include "misc/ConsoleUtils.h"

Mouse::~Mouse()
{
}

void Mouse::Update() {
	SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	m_pStateMachine->Update();
}

bool Mouse::HandleMessage(const Telegram& msg) {
	return m_pStateMachine->HandleMessage(msg);
}