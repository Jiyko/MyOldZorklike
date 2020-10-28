#pragma once
#include <iostream>
using namespace std;
class Player
{
public:
	Player();
	int getWepSkill();
	int getStr();
	int getTechSkill();
	void addWepPoint(); 
	void addTechPoint();
private:
	int tempWepSkill;
	int tempTechSkill;
	int wepSkill;
	int str;
	int techSkill;
};
