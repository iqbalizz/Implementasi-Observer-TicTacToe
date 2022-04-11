#pragma once
#include "Player.h"

class InterfaceObserver
{
	public:
		virtual void update(int, Player, Player) = 0;
		virtual void notifwin(Player) = 0;
		virtual void notiflose(Player) = 0;
};

