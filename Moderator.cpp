#include "Moderator.h"
#include "FBook.h"

Moderator::Moderator()
{
}


Moderator::~Moderator()
{

}
void Moderator::removePost(unsigned id)
{
	if (fbook->isAllowed(id, type, Actions::REMOVE))
	{
			fbook->removePost(id);
	}
	else
	{
		std::cout << "Sorry, you are not allowed to do this!" << std::endl;
	}
}
void Moderator::block(const char * name)
{
	if (fbook->isAllowed(0, type, Actions::BLOCK))
	{
		fbook->blockUser(name);
	}
	else
	{
		std::cout << "Sorry, you are not allowed to do this!" << std::endl;
	}
}
void Moderator::unblock(const char * name)
{
	if (fbook->isAllowed(0, type, Actions::UNBLOCK))
	{
		fbook->unblock(name);
	}
	else
	{
		std::cout << "Sorry, you are not allowed to do this!" << std::endl;
	}
}
void Moderator::addUser(const char * name, unsigned years, Users userType)
{
	if (fbook->isAllowed(0, type, Actions::ADD_USER))
	{
		if (fbook->isFree(name) == true)
		{
			fbook->addUser(name, years, userType);
		}
		else
		{
			std::cout << "Sorry, this name is not free :(" << std::endl;
		}
	}
	else
	{
		std::cout << "Sorry, you are not allowed to do this!" << std::endl;
	}
}
void Moderator::removeUser(const char * name)
{
	if (fbook->isAllowed(0, type, Actions::REMOVE_USER))
	{
		if (fbook->isFree(name))
		{
			std::cout << "Sorry, there is no such user :(" << std::endl;
			return;
		}
		fbook->removeUser(name);
	}
	else
	{
		std::cout << "Sorry, you are not allowed to do this!" << std::endl;
	}
}
User * Moderator::getInstance()
{
	return new Moderator();
}