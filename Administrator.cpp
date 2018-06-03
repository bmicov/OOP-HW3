#include "Administrator.h"
#include "FBook.h"
#include <iostream>

Administrator::Administrator()
{
}



Administrator::~Administrator()
{
}
//void Administrator::removePost(unsigned id)
//{
//	if (fbook->isAllowed(id, type, Actions::REMOVE))
//	{
//			fbook->removePost(id);
//	}
//	else
//	{
//		std::cout << "Sorry, you are not allowed to do this!" << std::endl;
//	}
//}
void Administrator::addUser(const char * name, unsigned years, Users userType)
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
void Administrator::removeUser(const char * name)
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
User * Administrator::getInstance()
{
	return new Administrator();
}
//void Administrator::removePost(unsigned id)
//{	
//	if (fbook->isAllowed(id, Users::ADMINISTRATOR, Actions::REMOVE))// this way we can manage who can remove posts only from fbook
//	{
//		fbook->removePost(id);
//		std::cout << "Administrator::removePost" << std::endl;
//	}
//	else
//	{
//		std::cout << "Sorry, you are not allowed to do this!" << std::endl;
//	}
//}