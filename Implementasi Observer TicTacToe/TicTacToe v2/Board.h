#pragma once

class Board
{
public:
	virtual bool is_full() = 0;
	virtual bool is_empty() = 0;
	virtual void clear_board() = 0;
	virtual char get_value_at_index(int, int) = 0;
	virtual void set_value_at_index(int, int, char) = 0;
	virtual char check_similiar_value_vertically() = 0;
	virtual char check_similiar_value_horizontally() = 0;
	virtual char check_similiar_value_sidely() = 0;
};