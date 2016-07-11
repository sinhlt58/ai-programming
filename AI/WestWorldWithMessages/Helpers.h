#ifndef HELPER_H
#define HELPER_H
#include <stdlib.h>

class Helpers {
public:
	static int MyRandInt() { return rand() % 10; }
};

#endif