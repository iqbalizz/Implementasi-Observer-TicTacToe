#include "GameManager.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	string name;

	cout << "TICTACTOE\n" << endl;

	cout << "Player 1 [X] Masukkan Nama: ";
	cin >> name;
	Player player_1(name);
	cout << "Player 2 [O] Masukkan Nama: ";
	cin >> name;
	Player player_2(name);

	GameManager gamemanager(player_1, player_2, 'X', 'O'); cout << endl;

	gamemanager.initialize(); 
	cout << endl;
	gamemanager.play();

	cin.get();
	return 0;
}