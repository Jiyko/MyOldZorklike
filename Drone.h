#pragma once
#include <iostream>
#include <string>
#include <ctime>  
#include <cstdlib>
using namespace std;
class Drone
{
public:
	Drone(); 
	void moveDrone();
	void passPos(int hiG, int wiT, int posH, int posW);
	int getPosh();
	int getPosw();
	string foundIt();
	bool findSomething();
	bool areYouDead();
private:
	int posh;
	int posw;
	int hig;
	int wit;
	void searchIt();
	void damage();
	bool find;
	bool destroyed;
	string fon;
};
