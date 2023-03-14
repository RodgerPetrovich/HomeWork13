#include <iostream>
#include <string>
#include "FB.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	FaceBook x;
	x.addMan("Howard");
	x.addMan("Lisa");
	x.addMan("Rodger");
	x.addMan("Max");
	x.addMan("Victor");
	x.addMan("Anna");
	x.addMan("Bob");
	x.addMan("Casper");
	x.addMan("Terminator");
	x.addMan("Morgan");
	

	x.addToFriend("Howard", "Rodger");
	x.addToFriend("Howard", "Max");
	x.addToFriend("Lisa", "Bob");
	x.addToFriend("Bob", "Anna");
	x.addToFriend("Anna", "Max");
	x.addToFriend("Morgan", "Casper");
	x.addToFriend("Victor", "Terminator");

	cout << "Фейсбук на минималках" << endl;

	x.showAllHandShakeFriends(3);

	
	return 0;
}