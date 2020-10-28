#pragma once
#include "Inventory.h"
#include "Legend.h"
#include "Player.h"
#include "Drone.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>  
#include <cstdlib>
using namespace std;
class City
{
private:
	int wit;
	int hig;
	int tim;
	int posh;
	int posw;
	vector<int> backPosh; 
	vector<int> backPosw;
	int map[21][21][3];
	Drone *d1;
	Drone *d2;
	Drone *d3;
	void droneMovement();
	void droneCreation();
	string noun();
	Inventory *cityIn;
	Player *player;
	void cityIntro();
	string getCityName();
	string name;
	void combat();
	void zombie();
	void sleepingVamp();
	string getType();
public:
	City();
	int getHig();
	int getWit();
	int getPosh();
	int getPosw();
	void search();
	void addPosh();
	void addPosw();
	void lessPosh();
	void lessPosw();
	void blockDet();
	void setPosh(int e);
	void setPosw(int h);
	void battleMode();
	void searching(int chance, string ob);
	void setInventory(Inventory *pass);
	void setPlayer(Player *pass);
	void wakeVamp();
	void zombieAnimal();
	void vampAnimal();
};
