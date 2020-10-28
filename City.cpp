#include "City.h"

City::City()
{	
	srand((unsigned)time(0)); 
	name = getCityName();
	hig = ((rand() % 15)+5);
	wit = ((rand() % 15)+5);
	setPosh(rand() % hig);
	setPosw(rand() % wit);
	backPosh.push_back (getPosh());
	backPosw.push_back (getPosw());
	tim=0;
	for(int i=0;i <= hig;i++) 
	{
		for(int j=0;j <= wit;j++)
		{
			map[i][j][0] =rand()%100;
		}
	}

	for(int i=0; i <= hig ;i++)
	{
		for(int j=0; j <= wit;j++)
		{
			map[i][j][1] = (rand()%2)+1;
		}
	}

	for(int i=0;i <= hig;i++)
	{
		for(int j =0;j <= wit;j++)
		{
			map[i][j][2] = rand()%13;
		}
	}
}

int City::getHig()
{
	return hig;
}

int City::getWit()
{
	return wit;
}	
int City::getPosh()
{
	return posh;
}

int City::getPosw()
{
	return posw;
}
void City::addPosh()
{
	posh++;
}

void City::addPosw()
{
	posw++;
}
void City::lessPosh()
{
	posh--;
}

void City::lessPosw()
{
	posw--;
}
void City::setPosh(int e)
{
	posh = e;
}

void City::setPosw(int h)
{
	posw = h;
}

void City::battleMode()
{
	string w1,w2,w3;
	droneCreation();
	cityIntro();
	blockDet();
	while(true)
	{
		switch(cityIn->getDrones())
		{
			case 1 : d1->moveDrone(); break;
			case 2 : d1->moveDrone(); d1->moveDrone(); break;
			case 3 : d1->moveDrone(); d1->moveDrone(); d1->moveDrone(); break;
			default: break;
		}
		if(tim==20)
		{
			cout << "It's getting dark. Maybe you should get home." << endl << "You don't want to be outside when it gets dark"<<endl;
		}
		if(tim==25)
		{
			cout << "It's pitch black. Good luck getting home." << endl;
			//night();
		}
		cout << ">";
		cin >> w1 >> w2 >> w3;
		{
			if(w1.compare("go")==0)
			{
				if(w2.compare("north")==0)
				{
					if(hig==getPosh())
					{
						cout << "A long abbanonded police barracade stops you from going any further" << endl;
					}
					else
					{
						addPosh();
						backPosh.push_back (getPosh());
						backPosw.push_back (getPosw());
					}
				}
				else if(w2.compare("south")==0)
				{
					if(0==getPosh())
					{
						cout << "A long abbanonded police barracade stops you from going any further" << endl;
					}
					else
					{
						lessPosh();
						backPosh.push_back (getPosh());
						backPosw.push_back (getPosw());
					}
				}
				else if(w2.compare("east")==0)
				{
					if(wit==getPosw())
					{
						cout << "A long abbanonded police barracade stops you from going any further" << endl;
					}
					else
					{
						addPosw();
						backPosh.push_back (getPosh());
						backPosw.push_back (getPosw());
					}
				}
				else if(w2.compare("west")==0)
				{
					if(0==getPosw())
					{
						cout << "A long abbanonded police barracade stops you from going any further" << endl;
					}
					else
					{
						lessPosw();
						backPosh.push_back (getPosh());
						backPosw.push_back (getPosw());
					}
				}
				else
				{
					cout << "where??" << endl;
				}
			}
			else if(w1.compare("search")==0)
			{
				search();
			}
			else if(w1.compare("return")==0)
			{
				cout << "You make your way back to the hover craft" << endl;
				if(cityIn->getDrones()>0)
				{
					if(d1->findSomething()==true&&d1->areYouDead()==false)
					{
						cout<<"A drone drops something at your feet" << endl;
						searching(100,d1->foundIt());
						if(d1->areYouDead()==true)
						{
							cityIn->useDrones();
						}
					}
					delete d1;
				}
				if(cityIn->getDrones()>1)
				{
					if(d2->findSomething()==true&&d2->areYouDead()==false)
					{
						cout<<"A drone drops something at your feet" << endl;
						searching(100,d2->foundIt());
						if(d2->areYouDead()==true)
						{
							cityIn->useDrones();
						}
					}
					delete d2;
				}
				if(cityIn->getDrones()>2)
				{
					if(d3->findSomething()==true&&d3->areYouDead()==false)
					{
						cout<<"A drone drops something at your feet" << endl;
						searching(100,d3->foundIt());
						if(d3->areYouDead()==true)
						{
							cityIn->useDrones();
						}
					}
					delete d3;
				}
				break; 
			}
			else if(w1.compare("set")==0&&w2.compare("weapon")==0)
			{
				cityIn->setMG(w3);
			}
			else if(w1.compare("back")==0)
			{
				if(((int)backPosw.size())!=0&&((int)backPosh.size())!=0)
				{
					backPosw.pop_back();
					backPosh.pop_back();
					setPosh(backPosh.back());
					setPosw(backPosw.back());
				}
				else
				{
					cout << "You can't go back any further"<< endl;
				}
			}
			if(w1.compare("drop")==0)
			{
				cout << "Why would you want to leave stuff behind!?!?" << endl;
			}
			if(w1.compare("help")==0)
			{
				cout << "I'm helping!!!" << endl;
				cout << "Different possible commans for different locations are:" << endl;
				cout << "go north now" << endl;
				cout << "check the ground" << endl;
				cout << "attack the vamp" << endl;
				cout << "search the area" << endl;
				cout << "return to ship" << endl;
				cout << "set weapon axe" << endl;
				cout << "Note: all comands are 3 words long and in lower case" << endl;
			}
		}
		blockDet();
	}
}
void City::search()
{
	if((map[getPosh()][getPosw()][1])==1)
	{
		combat();
	}
	int curr = map[getPosh()][getPosw()][0];
	if(curr<10)
	{//hopidal
		int pre=cityIn->weight();
		searching(40,"a first aid kit");
		searching(10,"a scapel");
		if(pre==cityIn->weight())
		{
			cout << "Nothing of use is added to your backpack" << endl;
		}
	}
	else if(curr<20)
	{//police Station
		int pre=cityIn->weight();
		searching(40,"a shotgun");
		searching(20,"a pistol");
		searching(60,"a shotgun shell");
		searching(40,"a pistol clip");
		if(pre==cityIn->weight())
		{
			cout << "Nothing of use is added to your backpack" << endl;
		}
	}
	else if(curr<30)
	{//fire station
		int pre=cityIn->weight();
		searching(40,"a fire axe");
		if(pre==cityIn->weight())
		{
			cout << "Nothing of use is added to your backpack" << endl;
		}
		//dog();
	}
	else if(curr<40)
	{//offices
		int pre=cityIn->weight();
		searching(40,"a CPU");
		searching(40,"some scrap metal");
		if(pre==cityIn->weight())
		{
			cout << "Nothing of use is added to your backpack" << endl;
		}
	}
	else if(curr<50)
	{//school
		int pre=cityIn->weight();
		searching(20,"a CPU");
		searching(10,"a pistol");
		searching(10,"a sligshot");
		if(pre==cityIn->weight())
		{
			cout << "Nothing of use is added to your backpack" << endl;
		}
	}
	else if(curr<60)
	{//shop
		int pre=cityIn->weight();
		searching(40,"a CPU");
		searching(15,"a pistol");
		searching(30,"some scrap metal");
		searching(40,"a first aid kit");
		if(pre==cityIn->weight())
		{
			cout << "Nothing of use is added to your backpack" << endl;
		}
	}
	else if(curr<98)
	{//housing
		int pre=cityIn->weight();
		searching(15,"some scrap metal");
		searching(10,"a pistol");
		searching(10,"a pistol clip");
		if(pre==cityIn->weight())
		{
			cout << "Nothing of use is added to your backpack" << endl;
		}
		//dog();
	}
	else if(curr==99)
	{//petrol station
		//TheEndGame();
	}
}
void City::setInventory(Inventory *pass)
{
	cityIn=pass;
}

void City::setPlayer(Player *pass)
{
	player=pass;
}


void City::blockDet()
{
	int curr = map[getPosh()][getPosw()][0];
	cout <<"You are standing next to " << noun();
	if (curr<10)
	{
		cout<<"hospidal"<<endl;
	}
	else if (curr<20)
	{
		cout<<"police Station"<<endl;
	}
	else if (curr<30)
	{
		cout<<"fire Station"<<endl;
	}
	else if (curr<40)
	{
		cout<<"office block"<<endl;
	}
	else if (curr<50)
	{
		cout<<"school"<<endl;
	}
	else if (curr<60)
	{
		cout<<"shop"<<endl;
	}
	else if (curr<99)
	{
		cout<<"housing block"<<endl;
	}
	else if (curr==99)
	{
		cout<<"petrol station"<<endl;
	}
	if(cityIn->getDrones()>0)
	{
		if(d1->getPosh()==posh&&d1->getPosw()==posw)
		{
			if(d1->areYouDead()==true)
			{
				cout << "You come across the ruins of a drone" << endl << "Some creature from the darkness destroyed it" << endl;
			}
			else
			{
				cout<<"You can see one of your drones flooting high in the sky above your head" << endl;
			}
		}
	}
	if(cityIn->getDrones()>1)
	{
		if(d2->getPosh()==posh&&d2->getPosw()==posw)
		{
			if(d2->areYouDead()==true)
			{
				cout << "You come across the ruins of a drone" << endl << "Some creature from the darkness destroyed it" << endl;
			}
			else
			{
				cout<<"You can see one of your drones flooting over the building on your left" << endl;
			}
		}
	}
	if(cityIn->getDrones()>2)
	{
		if(d3->getPosh()==posh&&d3->getPosw()==posw)
		{
			if(d3->areYouDead()==true)
			{
				cout << "You come across the ruins of a drone" << endl << "Some creature from the darkness destroyed it" << endl;
			}
			else
			{
				cout<<"You can see one of your drones through a broken window" << endl;
			}
		}
	}
	tim++;
}

void City::searching(int chance, string ob)
{
	if((rand() % 100)<chance)
	{
		string ans;
		cout << "You have found " << ob << endl; 
		cout << "Would you like to pick it up? [yes or no]" << endl; 
		cin >> ans;
		if(ans.compare("yes")==0)
		{	
			if(ob.compare("a first aid kit")==0)
			{
				cityIn->foundFaks();
			}
			else if(ob.compare("a shotgun shell")==0)
			{
				cityIn->foundShells();
			}
			else if(ob.compare("some scrap metal")==0)
			{
				cityIn->foundScrapMetal();
			}
			else if(ob.compare("a CPU")==0)
			{
				cityIn->foundCpu();
			}
			else if(ob.compare("a pistol clip")==0)
			{
				cityIn->foundClip();
			}
			else if(ob.compare("a shotgun")==0||ob.compare("a pistol")==0||ob.compare("a scapel")==0||ob.compare("a fire axe")==0||ob.compare("a slingshot")==0)
			{
				cityIn->addWep(ob);
			}
			else
			{
				cout << "My code is broke"<<endl;
			}

			if(cityIn->weight()<(player->getStr()*10))
			{
				cout << "You add " << ob << " to your backpack" <<endl;
			}
			else
			{
				cout << "You are not strong enough to carry all your stuff and have to leave it behind" << endl;
				if(ob.compare("a first aid kit")==0)
				{
					cityIn->useFaks();
				}
				else if(ob.compare("a shotgun shell")==0)
				{
					cityIn->useShells();
				}
				else if(ob.compare("some scrap metal")==0)
				{
					cityIn->useScrapMetal();
				}
				else if(ob.compare("a CPU")==0)
				{
					cityIn->useCpu();
				}
				else if(ob.compare("a pistol clip")==0)
				{
					cityIn->useClip();
				}
				else if(ob.compare("a shotgun")==0||ob.compare("a pistol")==0||ob.compare("a scalpel")==0||ob.compare("a fire axe")==0||ob.compare("a slingshot")==0)
				{
					cityIn->reWep(ob);
				}
				else
				{
					cout << "Moose, your code is broke"<<endl;
				}
			}
		}
		else
		{
			cout << "You leave it behind" << endl;
		}
	}
}
string City::noun()
{
	int deal = map[getPosh()][getPosw()][2];
	switch(deal)
	{
		case 0: return "a half burnt down "; break;
		case 1: return "a bady damaged "; break;
		case 2: return "a large "; break;
		case 3: return "a small "; break;
		case 4: return "a graffie covered "; break;
		case 5: return "a old "; break;
		case 6: return "a spooky looking "; break;
		case 7: return "a clean "; break;
		case 8: return "an abandoned "; break;
		case 9: return "a very old "; break;
		case 10: return "a picturesque "; break;
		case 11: return "a plain "; break;
		case 12: return "a normal looking "; break;
		
		default: return "a badass "; break;
	}
}

void City::droneCreation()
{
	switch(cityIn->getDrones())
	{
		case 1 : d1 = new Drone; break;
		case 2 : d1 = new Drone; d2 = new Drone; break;
		case 3 : d1 = new Drone; d2 = new Drone; d3 = new Drone; break;
		default: break;
	}
	switch(cityIn->getDrones())
	{
		case 1 : d1->passPos(hig,wit,posh,posw); break;
		case 2 : d1->passPos(hig,wit,posh,posw); d1->passPos(hig,wit,posh,posw); break;
		case 3 : d1->passPos(hig,wit,posh,posw); d1->passPos(hig,wit,posh,posw); d1->passPos(hig,wit,posh,posw); break;
		default: break;
	}
}

void City::cityIntro()
{
	cout<<"In the breaking dawn sun you can see " << name <<" clearly"<< endl;
	cout<<"There should be some good loot here"<< endl;
}

string City::getCityName()
{
	srand((unsigned)time(0));
	switch(rand() % 20)
	{
	case 0: return "New York"; break;
	case 1: return "Dublin"; break;
	case 2: return "Moscow"; break;
	case 3: return "London"; break;
	case 4: return "Tokyo"; break;
	case 5: return "Berlin"; break;
	case 6: return "Los Angelus"; break;
	case 7: return "Mexcio"; break;
	case 8: return "Paris"; break;
	case 9: return "Istanbul"; break;
	case 10: return "Cairo"; break;
	case 11: return "Beijing"; break;
	case 12: return "Rio de Janeiro"; break;
	case 13: return "Singapore"; break;
	case 14: return "Saint Petersburg"; break;
	case 15: return "Calcutta"; break;
	case 16: return "Ho Chi Minh City"; break;
	case 17: return "Toronto"; break;
	case 18: return "Casablanca"; break;
	case 19: return "Limerick"; break;
	}
}
void City::combat()
{
	srand((unsigned)time(0)); 
	int working =((rand()%5)+0);
	if(working==0)
	{
		zombie();
	}
	else if(working==1)
	{
		sleepingVamp();
	}
	else if(working==2)
	{
		wakeVamp();
	}
	else if(working==3)
	{
		zombieAnimal();
	}
	
	else if(working==4)
	{
		vampAnimal();
	}
}

void City::zombie()
{
	cout << "You see a Zombie lurching in the distance." << endl;
	cout << "He notices you straight away and has started lurching towards you." << endl;
	int steps=0;
	string w1,w2,w3;
	while(true)
	{
		steps++;
		if(steps>5)
		{
			cout << "The Zombie tries to bite you." <<endl;	
			srand((unsigned)time(0)); 
			if((rand()%10)==0)
			{
				cout << "The bite is deadly" << endl << endl;
				cout << "Game Over";
				while(true){}
			}
			else
			{
				cout << "He misses you"<< endl;
			}
		}
		cout << "   " << endl;
		cout << ">";
		cin >> w1 >> w2 >> w3;
		cin.ignore(80, '\n'); 
		if(w1.compare("attack")==0)
		{
			srand((unsigned)time(0)); 
			bool checker;
			checker = cityIn->checkAmmo();
			if(checker==true)
			{
	  	    	if((player->getWepSkill())<(rand()%10))
	    		{
                     player->addWepPoint();
				     cout<< "You hit the Zombie" <<endl;
				     if((cityIn->getWepStr())<(rand()%10))
				     {
					      cout << "And kill it"<<endl;
					      map[getPosh()][getPosw()][1]=0;
				     }
		             else
		        	 {
				        	cout << "But it just shrugs off the damage" <<endl;
				     }
                }
                else
                {
                    cout << "You try to hit it but miss badly" << endl;    
                }
            }
            else
            {
                cout << "A loud and clear clicking noise comes from your gun." << endl << "You are out of ammo" << endl;    
            }
		}
		else if(w1.compare("set")==0&&w2.compare("weapon")==0)
		{
			cityIn->setMG(w3);
		}
	}
}

void City::sleepingVamp()
{
	cout << "During your search. You have come across a sleeping Vampire" << endl;
	cout << "Would you like to drive a stake into his hearth?[yes or no]"<< endl << ">" ;
	string ans;
	cin >> ans;
	cin.ignore(80, '\n'); 
	if(ans.compare("yes")==0)
	{
		if((cityIn->getStake())==0)
		{
			cout << "You have no stakes and your russeling has awoke the Vampire" << endl;
			wakeVamp();
		}
		else if((cityIn->getStake())>0)
		{
			cityIn->useStake();
			cout << "The Vampire was speared through the hearth." << endl;
			player->addWepPoint();
			map[getPosh()][getPosw()][1]=0;
		}
	}
	else
	{
		cout << "As you walk around you wake the Vampire" << endl;
		wakeVamp();
	}
}

void City::wakeVamp()
{
	cout << "A Vampire rises out of the darkness." << endl;
	cout << "He notices you straight away and flies right at you" << endl;
	int steps=0;
	string w1,w2,w3;
	bool live = true;
	while(live==true)
	{
		steps++;
		if(steps>3)
		{
			cout << "The Vampire tries to bite you." <<endl;	
			srand((unsigned)time(0)); 
			if((rand()%10)==0)
			{
				cout << "The bite is deadly" << endl << endl;
				cout << "Game Over";
				while(true){}
			}
			else
			{
				cout << "He misses you"<< endl;
			}
		}
		cout << "   " << endl;
		cout << ">";
		cin >> w1 >> w2 >> w3;
		cin.ignore(80, '\n'); 
		if(w1.compare("attack")==0)
		{
			srand((unsigned)time(0)); 
			bool checker;
			checker = cityIn->checkAmmo();
			if(checker==true)
			{
		    	if((player->getWepSkill())<(rand()%10))
			    {
			     	player->addWepPoint();
			      	cout<< "You hit the Vampire" <<endl;
			       	if((cityIn->getWepStr())<(rand()%10))
			       	{
			      		cout << "It's knocken down"<<endl;
				    	cout << "Would you like to drive a stake into his hearth?[yes or no]"<< endl << ">" ;
		       			string ans;
		      			cin >> ans;
			     		if(ans.compare("yes")==0)
		       			{	
		           			if((cityIn->getStake())==0)
		    			    {
					        	cout << "You have no stakes the Vampire is too damaged to fight on but if you return he will be waiting for you" << endl;
					        	live = false;
					        }
					        else if((cityIn->getStake())>0)
					        {
					    	     map[getPosh()][getPosw()][1]=0;
					    	     cityIn->useStake();
				    		     cout << "The Vampire was spear through the hearth." << endl;
					    	     player->addWepPoint();
				    		     live = false;
                           }
                        }
			    	}
				    else
				    {
                        cout << "But it just shrugs off the damage" <<endl;
				    }
                }
                else
                {
                    cout << "You try to hit it but miss badly" << endl;    
                }
			}
		}
		else if(w1.compare("set")==0&&w2.compare("weapon")==0)
		{
			cityIn->setMG(w3);
		}
	}
}

void City::zombieAnimal()
{
	string type = getType();
	cout << "You see a Zombie " <<type<<" lurching in the distance." << endl;
	cout << "He notices you straight away and has started lurching towards you." << endl;
	int steps=0;
	string w1,w2,w3;
	bool live = true;
	while(live==true)
	{
		steps++;
		if(steps>5)
		{
			cout << "The Zombie "<<type<< " tries to bite you." <<endl;	
			srand((unsigned)time(0)); 
			if((rand()%10)==0)
			{
				cout << "The bite is deadly" << endl << endl;
				cout << "Game Over";
				while(true){}
			}
			else
			{
				cout << "He misses you"<< endl;
			}
		}
		cout << "   " << endl;
		cout << ">";
		cin >> w1 >> w2 >> w3;
		cin.ignore(80, '\n'); 
		if(w1.compare("attack")==0)
		{
			bool checker;
            checker = cityIn->checkAmmo();
			if(checker==true)
			{
               srand((unsigned)time(0)); 
			   if((player->getWepSkill())<(rand()%10))
			   {
			    	player->addWepPoint();
				    cout<< "You hit the Zombie "<<type <<endl;
				    if((cityIn->getWepStr())<(rand()%10))
				    {
				    	cout << "And kill it"<<endl;
				     	map[getPosh()][getPosw()][1]=0;
						live = false;
					}
			        else
				    {
						cout << "But it just shrugs off the damage" <<endl;
                    }
			    }
                else
                {
                    cout << "You try to hit it but miss badly" << endl;    
                }
            }
		}
		else if(w1.compare("set")==0&&w2.compare("weapon")==0)
		{
			cityIn->setMG(w3);
		}
	}
}

void City::vampAnimal()
{
    string type = getType();
	cout << "A Vampire " << type << " rises out of the darkness." << endl;
	cout << "He notices you straight away and flies right at you" << endl;
	int steps=0;
	string w1,w2,w3;
	bool live = true;
	while(live==true)
	{
		steps++;
		if(steps>3)
		{
			cout << "The Vampire " << type << " tries to bite you." <<endl;	
			srand((unsigned)time(0)); 
			if((rand()%10)==0)
			{
				cout << "The bite is deadly" << endl << endl;
				cout << "Game Over";
				while(true){}
			}
			else
			{
				cout << "He misses you"<< endl;
			}
		}
		cout << "   " << endl;
		cout << ">";
		cin >> w1 >> w2 >> w3;
		cin.ignore(80, '\n'); 
		if(w1.compare("attack")==0)
		{
			srand((unsigned)time(0)); 
			bool checker;
			checker = cityIn->checkAmmo();
			if(checker==true)
			{
		    	if((player->getWepSkill())<(rand()%10))
			    {
			     	player->addWepPoint();
			      	cout<< "You hit the Vampire " << type <<endl;
			       	if((cityIn->getWepStr())<(rand()%10))
			       	{
			      		cout << "It's knocken down"<<endl;
				    	cout << "Would you like to drive a stake into his hearth?[yes or no]"<< endl << ">" ;
		       			string ans;
		      			cin >> ans;
			     		if(ans.compare("yes")==0)
		       			{	
		           			if((cityIn->getStake())==0)
		    			    {
					        	cout << "You have no stakes the Vampire " << type << " is too damaged to fight on but if you return he will be waiting for you" << endl;
					        	live = false;
					        }
					        else if((cityIn->getStake())>0)
					        {
					    	     map[getPosh()][getPosw()][1]=0;
					    	     cityIn->useStake();
				    		     cout << "The Vampire was speared through the hearth." << endl;
					    	     player->addWepPoint();
				    		     live = false;
                           }
                        }
			    	}
				    else
				    {
                        cout << "But it just shrugs off the damage" <<endl;
				    }
                }
                else
                {
                    cout << "You try to hit it but miss badly" << endl;    
                }
			}
		}
		else if(w1.compare("set")==0&&w2.compare("weapon")==0)
		{
			cityIn->setMG(w3);
		}
	}
}


string City::getType()
{
	srand((unsigned)time(0));
	switch(rand() % 20)
	{
	case 0: return "Pig"; break;
	case 1: return "Cow"; break;
	case 2: return "Dog"; break;
	case 3: return "Cat"; break;
	case 4: return "Snake"; break;
	case 5: return "Bear"; break;
	case 6: return "Duck"; break;
	case 7: return "Horse"; break;
	case 8: return "Ninja"; break;
	case 9: return "Pirate"; break;
	case 10: return "Puppy"; break;
	case 11: return "Crow"; break;
	case 12: return "Zebra"; break;
	case 13: return "Elephant"; break;
	case 14: return "Babby"; break;
	case 15: return "Clown"; break;
	case 16: return "Lion"; break;
	case 17: return "Tiger"; break;
	case 18: return "Kitten"; break;
	case 19: return "Ninja Robot Pirate on Crack"; break;// This was Seans idea
	}
}
