#include "UserFactory.h"


UserFactory::UserFactory()
{
}


UserFactory::~UserFactory()
{

}
unsigned UserFactory::lastUserId = 0;
User * UserFactory::getAdministrator(const char * name, unsigned years, FBook * fb)
{
	User * admin = new Administrator();
	admin->setData(name, years, UserFactory::lastUserId, fb, Users::ADMINISTRATOR);
	return admin;
}

User * UserFactory::getSimpleUser(const char * name, unsigned years, FBook * fb)
{
	UserFactory::lastUserId++;
	User * su = new SimpleUser();
	su->setData(name, years, UserFactory::lastUserId, fb, Users::SIMPLE_USER);
	return su;
}

User * UserFactory::getModerator(const char * name, unsigned years, FBook * fb)
{
	UserFactory::lastUserId++;
	User * mod = new Moderator();
	mod->setData(name, years, UserFactory::lastUserId, fb, Users::MODERATOR);
	return mod;
}