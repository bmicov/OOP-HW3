#pragma once
#include "SimpleUser.h"
class Moderator :
	public SimpleUser
{
public:

	Moderator();
	~Moderator();
	void removePost(unsigned id);
	void block(const char * name); //moderator/administrator
	void unblock(const char * name); //moderator/administrator
	void addUser(const char * name, unsigned years, Users userType); //administrator
	void removeUser(const char * name);//admin
	User * getInstance();

};

