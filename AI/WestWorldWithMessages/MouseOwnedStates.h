#pragma once
#include "fsm/State.h"

class Mouse;

class AtHome : public State<Mouse> {

};

class MouseGlobalState : public State<Mouse>{

};

class FindingFood : public State<Mouse> {

};

class RunningFromCat : public State<Mouse> {

};

class DiedByCat : public State<Mouse> {

};
