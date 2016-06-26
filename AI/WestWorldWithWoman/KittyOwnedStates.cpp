#include "KittyOwnedStates.h"
#include "Kitty.h"
#include <iostream>

Sleeping* Sleeping::GetInstance() {
	static Sleeping instance;
	return &instance;
}



Eating* Eating::GetInstance() {
	static Eating instance;
	return &instance;
}








