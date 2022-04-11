#include "Observer.h"

void Observer::update(int match_count, Player player1, Player player2)
{
	cout << "\nList Pemain: " << endl;
	cout << "PLAYER 1 \n" << "Username: " << player1.get_username() << "\n" << "Win: " << player1.get_win_count() << endl << endl;
	cout << "PLAYER 2 \n" << "Username: " << player2.get_username() << "\n" << "Win: " << player2.get_win_count() << endl << endl;
	cout << "TOTAL MATCH: " << match_count << endl;
}

void Observer::notifwin(Player player)
{
	std::cout << std::endl;
	std::cout << player.get_username() << " Anda Menang" << std::endl;
}

void Observer::notiflose(Player player)
{
	std::cout << std::endl;
	std::cout << player.get_username() << "Anda Kalah" << std::endl;
}