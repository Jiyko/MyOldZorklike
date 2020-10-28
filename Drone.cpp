#include "Drone.h"

Drone::Drone()
{
	posh=0;
	posw=0;
	fon="";
	find=false;
	destroyed=false;
} 

void Drone::moveDrone()
{
	srand((unsigned)time(0)); 
	while(true)
	{
		int dir;
		dir = rand()%4;
		if(dir==0&&posh!=hig)
		{
			posh++;
			break;
		}
		if(dir==1&&posw!=wit)
		{
			posw++;
			break;
		}
		if(dir==2&&posh!=0)
		{
			posh--;
			break;
		}
		if(dir==3&&posw!=0)
		{
			posw--;
			break;
		}
	}
	searchIt();
	damage();
}

void Drone::passPos(int hiG, int wiT, int posH, int posW)
{
	hig=hiG;
	wit=wiT;
	posh=posH;
	posw=posW;
}

void Drone::searchIt()
{
	srand((unsigned)time(0));
	if(rand()%100<10&&find==false)
	{
		switch(rand()%5)
		{
			case 0: fon = "a CPU"; break;
			case 1: fon = "some scrap metal"; break;
			case 2: fon = "a shotgun shell"; break;
			case 3: fon = "a pistol clip"; break;
		}
		find = true;
	}
}

int Drone::getPosh()
{
	return posh;
}

int Drone::getPosw()
{
	return posw;
}

string Drone::foundIt()
{
	return fon;
}

bool Drone::findSomething()
{
	return find;
}

void Drone::damage()
{
	srand((unsigned)time(0));
	if(rand()%100<5)
	{
		destroyed=true;
	}
}


bool Drone::areYouDead()
{
	return destroyed;
}