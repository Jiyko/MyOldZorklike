#pragma once
#include <map>
#include <string>
using namespace std;
 
class Room 
{
private:
	string description;
	map<string, Room*> exits;

public:
	Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	string exitString();
	Room* nextRoom(string direction);
};
