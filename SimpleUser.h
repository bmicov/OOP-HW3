#pragma once
#include "User.h"
class SimpleUser : public User
{
public:
	void addPost();
	virtual void removePost(unsigned id);
	User * getInstance();

	void block(const char * name); //moderator/administrator
	void unblock(const char * name); //moderator/administrator
	void addUser(const char * name, unsigned years, Users userType); //administrator
	void removeUser(const char * name);//admin


	SimpleUser();
	~SimpleUser();
};

