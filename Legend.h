#pragma once
#include "Room.h"
#include "Inventory.h"
#include "City.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <ctime>  
#include <cstdlib>
#include <vector>
using namespace std;
class Legend
{
public: 
	Legend();
	void play();
	string getWord1();
	string getWord2();
	string getWord3();
	Room *currentRoom;
	void dropRoomer(string tag);
	Inventory *in;
	Player *player;
private:
	void input();
	void createHover();
	void dropItLikeItsHot();
	void lookDownUEjet();
	void check();
	void endGame();
	vector<string> bed;
	vector<string> cockpit;
	vector<string> kitchen;
	vector<string> workshop;
	void intro();
	void help();
	void dostuff();
	void moveIt();
	int tim;
	string word1;
	string word2;
	string word3;
};
