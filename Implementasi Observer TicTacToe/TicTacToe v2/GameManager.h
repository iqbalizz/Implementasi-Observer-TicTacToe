#pragma once
#include "Player.h"
#include "Interface.h"
#include "Observer.h"

using namespace std;

class GameManager
{
protected:
	Board *Interface_1 = new Interface();
	Observer* reguler_observer = new Observer();
	Player Player_1;
	Player Player_2;
	char Symbol_1;
	char Symbol_2;
	int Match_Count;

public:
	GameManager();
	GameManager(Player, Player, char, char);
	string player1_username();
	string payer2_username();
	int match_count();
	void initialize();
	void turn(char);
	void play();
	char check_win();
};
