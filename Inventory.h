#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Inventory
{
public:
	Inventory();
	void displayWep();
	void addWep(string gun);
	void reWep(string gun);
	void useStake();
	int getStake();
	void foundStake();
	void useShells();
	int getShells();
	void foundShells();
	void useClip();
	int getClip(); 
	void foundClip();
	void useCpu();
	int getCpu();
	void foundCpu();
	void useFaks();
	int getFaks();
	void foundFaks();
	void useDrones();
	int getDrones();
	void foundDrones();
	void useScrapMetal();
	int getScrapMetal();
	void foundDog();
	void deadDog();
	void woundedDog();
	void healedDog();
	void foundScrapMetal();
	void setMG(string gun);
	void nameDog(string name);
	int getWepStr();
	int weight();
    bool checkAmmo();
private:
	vector<string> weapons;
	string mainG;
	string dogName;
	bool slingshot;
	bool shotgun;
	bool pistol;
	bool axe;
	bool scapel;
	int clip;
	int stakes;
	int shells;
	int faks;
	int drones;
	int cpu;
	bool dog;
	bool wDog;
	int scrapMetal;
	int wi;
};
