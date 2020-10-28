#include "Legend.h"

int main()
{
	Legend temp;
	temp.play();
}

Legend::Legend()
{
	createHover();
	in = new Inventory();
	player = new Player();
	tim=0;
}

void Legend::createHover()
{
	Room *bed, *cockpit, *kitchen, *workshop;
	bed = new Room("bedroom");
	cockpit = new Room("cockpit");
	kitchen = new Room("kitchen");
	workshop = new Room("workshop");
	bed->setExits(cockpit, NULL, workshop, kitchen);
	cockpit->setExits(NULL, NULL, bed, NULL);
	kitchen->setExits(NULL, bed, NULL, NULL);
	workshop->setExits(bed, NULL, NULL, NULL);
	currentRoom = bed;
}

void Legend::play()
{
	intro();
	while(true)
	{
		check();
		input();
		dostuff();
	}
}


void Legend::dostuff()
{
	
	if(getWord1().compare("help")==0)
	{
		help();
	}
	else if(getWord1().compare("go")==0)
	{
		if(getWord2().compare("north")==0||getWord2().compare("south")==0||getWord2().compare("east")==0||getWord2().compare("west")==0)
		{
			moveIt();
		}
	}
	else if(getWord1().compare("build")==0&& currentRoom->shortDescription().compare("workshop")==0)
	{
		if(getWord3().compare("drone")==0)
		{
			if(in->getScrapMetal()>0&&in->getCpu()>0)
			{
				srand((unsigned)time(0));
				if(rand()%10<player->getTechSkill())
				{
					in->foundDrones();
					in->useScrapMetal();
					in->useCpu();
					cout << "You build a drone. This will be quite useful while searching" << endl;
				}
				else
				{
					in->useScrapMetal();
					in->useCpu();
					cout << "You try but you area just not skilled enough to make a Drone. The raw materials are ruined" << endl;
				}
				player->addTechPoint();
			}
			else
			{
				cout << "You don't have the raw materials to do that" << endl;
			}
		}
		else if(getWord3().compare("shell"))
		{
			if(in->getScrapMetal()>0)
			{
				if(rand()%10<player->getTechSkill())
				{
					in->foundShells();
					in->foundShells();
					in->useScrapMetal();
					cout << "You use the metal to make 2 shells for a shotgun." << endl;
				}
				else
				{
					cout << "You try but you area just not skilled enough to make the shells. The raw materials are ruined" << endl;
				}
			}
			else
			{
				cout << "You don't have the metal to do that" << endl;
			}
		}
	}
	else if(getWord1().compare("land")==0&&currentRoom->shortDescription().compare("cockpit")==0)
	{
		srand(time(0));
		City *here;
		here = new City();
		here->setInventory(in);
		here->setPlayer(player);
		here->battleMode();
		tim++;
		delete here;
	}
	else if(getWord1().compare("check")==0&&getWord2().compare("the")==0&&getWord3().compare("ground")==0)
	{
		lookDownUEjet();
	}
	else if(getWord1().compare("Drop"))
	{
		dropItLikeItsHot();
	}
	else
	{
		cout << "You make no sence"<<endl;
	}
}

void Legend::input()
{
	cout << ">";
	cin >> word1 >> word2 >> word3 ;
	cin.ignore(80, '\n'); 
}

string Legend::getWord1()
{
	return word1;
}

string Legend::getWord2()
{
	return word2;
}

string Legend::getWord3()
{
	return word3;
}

void Legend::intro()
{
	cout << "Welcome, to 2020." << endl;
	cout << "You have not seen another person for 19 months" << endl;
	cout << "AI scans suggest there is no one else to see anyway" << endl;
	cout << "Your hovercraft is the only thing keeping you safe" << endl;
	cout << "during there nightly searchs" << endl;
	cout << endl;
	cout << "Type \"help me please\" for help" << endl;
	cout << "You are in your " << currentRoom->shortDescription() << endl;
	cout << currentRoom->exitString()<<endl;
}

void Legend::help()
{
	cout << " " << endl;
	cout << "I'm helping!!!" << endl;
	cout << "Different possible commans for different locations are:" << endl;
	cout << "go north now" << endl;
	cout << "check the ground" << endl;
	cout << "attack the vamp" << endl;
	cout << "search the area" << endl;
	cout << "return to ship" << endl;
	cout << "set weapon axe" << endl;
	cout << "Note: all comands are 3 words long and in lower case" << endl;
	cout << " " << endl;
}

void Legend::moveIt()
{
	string direction = getWord2();
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
	{
		cout << "Thats a dead end......."<< endl;
	}
	else 
	{
		currentRoom = nextRoom;
		cout << "You are in your " << currentRoom->shortDescription() << endl;
		cout << currentRoom->exitString()<<endl;
	}
}



void Legend::dropItLikeItsHot()
{
	if(getWord3().compare("fak")==0)
	{
		if((in->getFaks())>0)
		{
			in->useFaks();
			cout << "You leave a first aid kit on the ground" << endl;
			dropRoomer("a first aid kit");
		}
		else
		{
			cout <<"You don't have any of them"<<endl;
		}
	}
	else if(getWord3().compare("stake")==0)
	{
		if((in->getStake())>0)
		{
			in->useStake();
			cout << "You leave a stake on the ground"<< endl;
			dropRoomer("a stake");
		}
		else
		{
			cout <<"You don't have any of them"<<endl;
		}
	}
	else if(getWord3().compare("shell")==0)
	{
		if((in->getShells())>0)
		{
			in->useShells();
			cout << "You leave a shotgun shell on the ground"<< endl;
			dropRoomer("a shotgun shell");
		}
		else
		{
			cout <<"You don't have any of them"<<endl;
		}
	}
	else if(getWord3().compare("metal")==0)
	{
		if((in->getScrapMetal())>0)
		{
			in->useScrapMetal();
			cout << "You leave some scrap metal on the ground"<< endl;
			dropRoomer("some scrap metal");
		}
		else
		{
			cout <<"You don't have any of them"<<endl;
		}
	}
	else if(getWord3().compare("CPU")==0)
	{
		if((in->getCpu())>0)
		{
			in->useCpu();
			cout << "You leave a CPU on the ground"<< endl;
			dropRoomer("a CPU");
		}
		else
		{
			cout <<"You don't have any of them"<<endl;
		}
	}
	else if(getWord3().compare("clip")==0)
	{
		if((in->getClip())>0)
		{
			in->useClip();
			cout << "You leave a pistol clip on the ground"<< endl;
			dropRoomer("a pistol clip");
		}
		else
		{
			cout <<"You don't have any of them"<<endl;
		}
	}
	else if(getWord3().compare("shotgun")==0||getWord3().compare("pistol")==0||getWord3().compare("scalpel")==0||getWord3().compare("axe")==0||getWord3().compare("slingshot")==0)
	{
		string boss;
		if(getWord3().compare("shotgun")==0)
		{
			boss = "a shotgun";
		}
		else if(getWord3().compare("pistol")==0)
		{
			boss = "a pistol";
		}
		else if(getWord3().compare("scalpel")==0)
		{
			boss="a scalpel";
		}
		else if(getWord3().compare("axe")==0)
		{
			boss="a fire axe";
		}
		else if(getWord3().compare("slingshot")==0)
		{
			boss="a slingshot";
		}
		in->reWep(boss);
		dropRoomer(boss);
	}
}

void Legend::dropRoomer(string tag)
{
	if((currentRoom->shortDescription()).compare("bedroom")==0)
	{
		bed.push_back(tag);
	}
	if((currentRoom->shortDescription()).compare("cockpit")==0)
	{
		cockpit.push_back(tag);
	}
	if((currentRoom->shortDescription()).compare("kitchen")==0)
	{
		kitchen.push_back(tag);
	}
	if((currentRoom->shortDescription()).compare("workshop")==0)
	{
		workshop.push_back(tag);
	}
}

void Legend::lookDownUEjet()
{
	if((currentRoom->shortDescription()).compare("bedroom")==0)
	{
		if(bed.size()==0)
		{
			cout<<"There is nothing there"<<endl;
		}
		else
		{
			cout<<"On the ground there is :"<<endl;
			for(int i=0;i<bed.size(); i++)
			{
				string strd = bed.at(i);
				cout<<strd.c_str()<<endl;
			}
		}
	}
	if((currentRoom->shortDescription()).compare("cockpit")==0)
	{
		if(cockpit.size()==0)
		{
			cout<<"There is nothing there"<<endl;
		}
		else
		{
			cout<<"On the ground there is :"<<endl;
			for(int i=0;i<cockpit.size(); i++)
			{
				string strd = cockpit.at(i);
				cout<<strd.c_str()<<endl;
			}
		}
	}
	if((currentRoom->shortDescription()).compare("kitchen")==0)
	{
		if(kitchen.size()==0)
		{
			cout<<"There is nothing there"<<endl;
		}
		else
		{
			cout<<"On the ground there is :"<<endl;
			for(int i=0;i<kitchen.size(); i++)
			{
				string strd = kitchen.at(i);
				cout<<strd.c_str()<<endl;
			}
		}
	}
	if((currentRoom->shortDescription()).compare("workshop")==0)
	{
		if(workshop.size()==0)
		{
			cout<<"There is nothing there"<<endl;
		}
		else
		{
			cout<<"On the ground there is :"<<endl;
			for(int i=0;i<workshop.size(); i++)
			{
				string strd = workshop.at(i);
				cout<<strd.c_str()<<endl;
			}
		}
	}
}

void Legend::check()
{
	if(tim>5)
	{
		endGame();
	}
}

void Legend::endGame()
{
	cout << "You arrive back to your home to discover some thing is off" << endl;
	cout << "Then suddenly"<<endl;
	City *here;
	here = new City();
	here->setInventory(in);
	here->setPlayer(player);
	here->battleMode();
	here->wakeVamp();
	cout << endl;
	cout << "You move slowly into the kitchen" << endl;
	cout << "Spinning around you see somthing dart behind you"<<endl;
	here->vampAnimal();
	here->zombieAnimal();
	cout << "They area all over the place!!!"<<endl;
	cout<<"Your home, your one sancuary has been fouled"<<endl;
	cout <<"You can sort them all!!!"<<endl;
	cout << endl;
	cout << endl;
	cout << "No one was there to watch as you crash your craft into the groud"<<endl;
	cout << endl;
	cout << endl;
	

    cout <<"Thus that which is the most awful of evils, death, is nothing to us, since when we exist there is no death, "<<endl;
	cout <<"and when there is death we do not exist." <<endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout <<"Game Over"<< endl;
}