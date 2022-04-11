#pragma once
#include <iostream>
using namespace std;

class Player
{
protected:
	string Name;
	int Win_Count;

public:
	Player();
	Player(string);
	// setting username
	void set_username(string);
	string get_username();
	// setting win
	void set_win_count(int);
	int get_win_count();
};
