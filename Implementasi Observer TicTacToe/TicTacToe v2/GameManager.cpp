#include "GameManager.h"

GameManager::GameManager()
{
	Symbol_1 = 'S';
	Symbol_2 = 'S';
	Match_Count = 0;
}

GameManager::GameManager(Player Player_1, Player Player_2, char Symbol_1, char Symbol_2)
{
	this->Player_1 = Player_1;
	this->Player_2 = Player_2;
	this->Symbol_1 = Symbol_1;
	this->Symbol_2 = Symbol_2;
	Match_Count = 0;
}

void GameManager::initialize()
{
	Symbol_1 = 'X';
	Symbol_2 = 'O';
	Match_Count++;
	Interface_1->clear_board();
}

void GameManager::turn(char Symbol)
{
	int x, y;
	cout << "Beri spasi antara x dan y ";
	cout << "\nMasukkan posisi (x,y) : ";
	cin >> x >> y;

	if (x > 2 || y > 2)
	{
		cout << "Invalid square index input. coba lagi." << endl;
		turn(Symbol);
	}

	if (Interface_1->get_value_at_index(x, y) == '0')
	{
		Interface_1->set_value_at_index(x, y, Symbol);
	}
	else
	{
		cout << "Square is filled. Coba lagi." << endl;
		turn(Symbol);
	}
}

void GameManager::play()
{
	int step = 0;

	while (!Interface_1->is_full() && check_win() == 'F')
	{
		step++;
		// print board
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				if (Interface_1->get_value_at_index(x, y) != '0')
					cout << Interface_1->get_value_at_index(x, y) << "\t";
				else
					cout << "_\t";
			}
			cout << endl << endl;
		}

		if (step % 2 == 1) //player 1 turn
		{
			cout << endl;
			cout << "Giliran " << Player_1.get_username() << endl;
			turn(Symbol_1);
		}
		else //player 2 turn
		{
			cout << endl;
			cout << "Giliran " << Player_2.get_username()  << endl;
			turn(Symbol_2);
		}
		cout << endl;
	}

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (Interface_1->get_value_at_index(x, y) != '0')
				cout << Interface_1->get_value_at_index(x, y) << "\t";
			else
				cout << "_\t";
		}
		cout << endl << endl;
	}

	if (check_win() != 'F')
	{
		if (check_win() == Symbol_1)
		{
			Player_1.set_win_count(Player_1.get_win_count() + 1);
			reguler_observer->notifwin(Player_1);
			reguler_observer->notiflose(Player_2);
		}

		if (check_win() == Symbol_2)
		{
			Player_2.set_win_count(Player_2.get_win_count() + 1);
			reguler_observer->notifwin(Player_2);
			reguler_observer->notiflose(Player_1);
		}
	}
	else
	{
		cout << endl;
		cout << "Seri" << endl;
	}

	reguler_observer->update(Match_Count, Player_1, Player_2);
}

char GameManager::check_win()
{
	if (Interface_1->check_similiar_value_horizontally() != '0')
		return Interface_1->check_similiar_value_horizontally();
	else if (Interface_1->check_similiar_value_vertically() != '0')
		return Interface_1->check_similiar_value_vertically();
	else if (Interface_1->check_similiar_value_sidely() != '0')
		return Interface_1->check_similiar_value_sidely();
	else
		return 'F';
}