#include "Kitty.h"

Kitty::~Kitty()
{
}

void Kitty::Update() {
	m_pStateMachine->Update();
}

bool Kitty::HandleMessage(const Telegram& msg) {
	return false;
}