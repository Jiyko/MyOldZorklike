#include "Room.h"
Room::Room(string description) 
{
	this->description = description;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) 
{
	if (north != NULL) 
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

string Room::shortDescription() 
{
	return description;
}

string Room::longDescription() 
{
	return "You are in " + description + ".\n"+ exitString();
}

string Room::exitString() 
{
	string returnString = "Exits:";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		
		returnString += " " + i->first;	
	return returnString;
}

Room* Room::nextRoom(string direction) 
{
	map<string, Room*>::iterator next = exits.find(direction); 
	if (next == exits.end())
	{
		return NULL; 
	}
	return next->second; 
}
