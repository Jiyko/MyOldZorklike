#include "Player.h"

Player::Player()
{
	wepSkill=2;
	tempWepSkill=0;
	tempTechSkill=0;
	str=5;
	techSkill=2;
} 
int Player::getWepSkill()
{	
	return wepSkill;
}

int Player::getStr()
{	
	return str;
}

int Player::getTechSkill()
{	
	return techSkill;
}

void Player::addWepPoint()
{
	tempWepSkill++;
	if(tempWepSkill%5==0&&wepSkill<8)
	{
		wepSkill+=2;
		cout << "Your skill with weapons has improved. You are now better able to kill stuff" << endl;
	}
}

void Player::addTechPoint()
{
	tempTechSkill++;
	if(tempTechSkill%5==0&&wepSkill<8)
	{
		techSkill+=2;
		cout << "Your technical knowledge has improved. You are now better able to build stuff" << endl;
	}
}