#include "Kitty.h"
#include "misc/ConsoleUtils.h"
Kitty::~Kitty()
{
}

void Kitty::Update() {
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	m_pStateMachine->Update();
}

bool Kitty::HandleMessage(const Telegram& msg) {
	return m_pStateMachine->HandleMessage(msg);
}