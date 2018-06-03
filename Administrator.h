#pragma once
#include "Moderator.h"
class Administrator :
	public Moderator
{
public:
	Administrator();
	//void removePost(unsigned id);
	void addUser(const char * name, unsigned years, Users userType);//administrator
	void removeUser(const char * name);//admin

	
	User * getInstance();

	~Administrator();
};

