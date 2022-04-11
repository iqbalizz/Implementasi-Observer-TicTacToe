#pragma once
#include "InterfaceObserver.h"
using namespace std;

class Observer : public InterfaceObserver
{
public:
	void update(int, Player, Player);
	void notifwin(Player);
	void notiflose(Player);
};

