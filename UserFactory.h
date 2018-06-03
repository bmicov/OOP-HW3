#pragma once
#include "Administrator.h"
class UserFactory
{
public:
	UserFactory();
	~UserFactory();
	User * getSimpleUser(const char * name, unsigned years, FBook * fb);
	User * getAdministrator(const char * name, unsigned years, FBook * fb);
	User * getModerator(const char * name, unsigned years, FBook * fb);
	unsigned static lastUserId;


};

