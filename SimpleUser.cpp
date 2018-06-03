#include "SimpleUser.h"
#include "FBook.h"
SimpleUser::SimpleUser()
{
}

SimpleUser::~SimpleUser()
{
}

void SimpleUser::removePost(unsigned id)
{
	if (fbook->isAllowed(id,type, Actions::REMOVE))
	{
		if (fbook->getPost(id)->getAddedBy() == id)
		{
			fbook->removePost(id);
		}
		else
		{
			std::cout << "You don't own this post!" << std::endl;
		}
		std::cout << "SimpleUser::removePost" << std::endl;
	}
	else
	{
		std::cout << "You are blocked" << std::endl;
	}
}
void SimpleUser::block(const char * name)
{
	if (fbook->isAllowed(0, type, Actions::BLOCK))
	{
		std::cout << "Sorry, you do not have permision. You are just an user :(" << std::endl;
	}
	else
	{
		std::cout << "Sorry, probably you are blocked" << std::endl;
	}
}
void SimpleUser::unblock(const char * name)
{
	if (fbook->isAllowed(0, type, Actions::UNBLOCK))
	{
		std::cout << "Sorry, you do not have permision. You are just an user :(" << std::endl;
	}
	else
	{
		std::cout << "Sorry, probably you are blocked" << std::endl;
	}
}
void SimpleUser::addUser(const char * name, unsigned years, Users userType)
{
	if (fbook->isAllowed(0, type, Actions::ADD_USER))
	{
		std::cout << "Sorry, you do not have permision. You are just user :(" << std::endl;
	}
	else
	{
		std::cout << "Sorry, probably you are blocked" << std::endl;
	}
}
void SimpleUser::removeUser(const char * name)
{
	if (fbook->isAllowed(0, type, Actions::REMOVE_USER))
	{
		std::cout << "Sorry, you do not have permision. You are just user :(" << std::endl;
	}
	else
	{
		std::cout << "Sorry, probably you are blocked" << std::endl;
	}
}
User * SimpleUser::getInstance()
{
	return new SimpleUser();
}