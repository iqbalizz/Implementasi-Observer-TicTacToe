#pragma once
#include <iostream>
#include "Board.h"

class Interface : public Board
{
protected:
	char It_Board[3][3];

public:
	Interface();
	// full?
	bool is_full();
	bool is_empty();
	void clear_board();
	// setting value
	char get_value_at_index(int, int);
	void set_value_at_index(int, int, char);
	// checking
	char check_similiar_value_vertically();
	char check_similiar_value_horizontally();
	char check_similiar_value_sidely();
	~Interface();
};
