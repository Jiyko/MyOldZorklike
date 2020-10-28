#include "Inventory.h"

Inventory::Inventory()
{
	stakes =1;
	shells =0;
	clip=0;
	faks =0;
	drones =0;
	scrapMetal =0;
	cpu=0;
	dog=false;
	wDog=false;
	wi =0;
	slingshot=false;
	shotgun=false; 
	pistol=false;
	axe=false;
	scapel=false;
}

void Inventory::addWep(string gun)
{
	if(gun.compare("a shotgun")==0)
	{
		if(shotgun==false)
		{
			shotgun=true;
		}
		else
		{
			cout << "You already have one" << endl;
		}
	}
	else if(gun.compare("a pistol")==0)
	{
		if(pistol==false)
		{
			pistol=true;
		}
		else
		{
			cout << "You already have one" << endl;
		}
	}	
	else if(gun.compare("a scapel")==0)
	{
		if(scapel==false)
		{
			scapel=true;
		}
		else
		{
			cout << "You already have one" << endl;
		}
	}
	else if(gun.compare("a fire axe")==0)
	{
		if(axe==false)
		{
			axe=true;
		}
		else
		{
			cout << "You already have one" << endl;
		}
	}
	else if(gun.compare("a slingshot")==0)
	{
		if(slingshot==false)
		{
			slingshot=true;
		}
		else
		{
			cout << "You already have one" << endl;
		}
    }
}


void Inventory::reWep(string gun)
{
	if(gun.compare("shotgun")==0)
	{
		if(shotgun==true)
		{
			shotgun=false;
		}
	}
	else if(gun.compare("pistol")==0)
	{
		if(pistol==true)
		{
			pistol=false;
		}
	}	
	else if(gun.compare("scapel")==0)
	{
		if(scapel==true)
		{
			scapel=false;
		}
	}
	else if(gun.compare("axe")==0)
	{
		if(axe==true)
		{
			axe=false;
		}
	}
	else if(gun.compare("slingshot")==0)
	{
		if(slingshot==true)
		{
			slingshot=false;
		}
    }
}


void Inventory::displayWep()
{
	if(shotgun==true)
	{
		cout <<"a shotgun"<<endl;
	}
	if(pistol==true)
	{
		cout << "a pistol" << endl;
	}
	if(scapel==true)
	{
		cout << "a scapel" << endl;
	}
	if(axe==true)
	{
		cout << "a fire axe"<<endl;
	}
	if(slingshot==true)
	{
		cout << "a slingshot" << endl;
	}
}


void Inventory::setMG(string gun)
{
    if(gun.compare("shotgun")==0&&shotgun==true)
	{
		mainG="a shotgun";
	}
	else if(gun.compare("pistol")==0&&pistol==true)
	{
		mainG="a pistol";
	}	
	else if(gun.compare("scapel")==0&&scapel==true)
	{
		mainG="a scapel";
	}
	else if(gun.compare("axe")==0&&axe==true)
	{
		mainG="a fire axe";
	}	
	else if(gun.compare("slingshot")==0)
	{
		mainG="a slingshot";
	}
	else
	{
		cout << "We don't seem to have than in stock today" << endl;
	}
}

int Inventory::getWepStr()
{
	if(mainG.compare("a shotgun")==0)
	{
		return 8;
	}
	else if(mainG.compare("a pistol")==0)
	{
		return 5;	
	}	
	else if(mainG.compare("a scapel")==0)
	{
		return 3;
	}
	else if(mainG.compare("a fire axe")==0)
	{
		return 6;
	}
	else if(mainG.compare("a slingshot")==0)
	{
		return 4;
	}
	else 
	{
		return 2;
	}
}


void Inventory::foundStake()
{
	stakes++;
}

void Inventory::useStake()
{
	stakes--;
}

int Inventory::getStake()
{
	return stakes;
}

void Inventory::foundCpu()
{
	cpu++;
}

void Inventory::useCpu()
{
	cpu--;
}

int Inventory::getCpu()
{
	return cpu;
}

void Inventory::foundShells()
{
	shells++;
}

void Inventory::useShells()
{
	shells--;
}

int Inventory::getShells()
{
	return shells;
}
void Inventory::foundClip()
{
	clip++;
}

void Inventory::useClip()
{
	clip--;
}

int Inventory::getClip()
{
	return clip;
}

void Inventory::foundFaks()
{
	faks++;
}

void Inventory::useFaks()
{
	faks--;
}

int Inventory::getFaks()
{
	return faks;
}

void Inventory::foundDrones()
{
	drones++;
}

void Inventory::useDrones()
{
	drones--;
}

int Inventory::getDrones()
{
	return drones;
}

void Inventory::foundScrapMetal()
{
	scrapMetal++;
}

void Inventory::useScrapMetal()
{
	scrapMetal--;
}

int Inventory::getScrapMetal()
{
	return scrapMetal;
}

void Inventory::foundDog()
{
	dog=true;
}
void Inventory::deadDog()
{
	dog=false;
}
void Inventory::woundedDog()
{
	wDog=true;
}
void Inventory::healedDog()
{
	wDog=false;
}

void Inventory::nameDog(string name)
{
	dogName=name;
}


int Inventory::weight()
{
	int wei =0;
	wei=wei+(wi*5);
	wei=wei+(getStake()*2);
	wei=wei+(getShells());
	wei=wei+(getClip());
	wei=wei+(getFaks()*4);
	wei=wei+(getScrapMetal()*6);
	wei=wei+(getCpu()*4);
	return wei;
}






bool Inventory::checkAmmo()
{
    if(mainG.compare("a shotgun")==0)
	{
		if(shells==0)
        {
            return false;
            cout << "You are out of shells for your shotgun" << endl;
        }
        else
        {
             return true;    
        }
    }    
    else if(mainG.compare("a pistol")==0)
	{
		if(clip==0)
        {
            return false;
            cout << "You are out of bullets for your pistol" << endl;             
        }
        else
        {
             return true; 
        }
    }    
    else
    {
        return true;    
    }
}





