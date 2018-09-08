#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	char choice = 'y';
	while (choice == 'y')
	{
		cout << "You've been ambushed by a feral dog!\nDefend yourself!\n";
		this_thread::sleep_for(chrono::milliseconds(2000));
		srand(static_cast<unsigned int>(time(0)));
		int health = 10, damage, defence, turn = 1;
		while(true)
		{
			if(turn >= 5) break;
			if(health <= 0) break;
			turn++;
			damage = rand() % 5;
			defence = rand() % 5;
			if(damage > defence)
			{
				health -= damage;
				cout << "Ouch, you took " << damage << "!\n";
			} else {
				cout << "You blocked the attack.\n";
			}
			this_thread::sleep_for(chrono::milliseconds(500));
		}
		if (health <= 5)
		{
			cout << "You manage to get away, but you need to see a doctor.\n";
		}
		else if (health <= 0)
		{
			cout << "You've met an early grave.\n";
		} 
		else
		{
			cout << "You found an opening and ran away.\n";
		}
		cout << "Want to play again?(y/n)\n";
		cin >> choice;
	}
}