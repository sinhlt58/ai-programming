#include "Kitty.h"

Kitty::~Kitty()
{
}

void Kitty::Update() {
	m_pStateMachine->Update();
}
