#include "User.h"
#include <cstring>
#include "FBook.h"
User::User()
{
	name = new char[1];
	name[0] = '\0';
	years = 0;
	fbook = nullptr;
	id = 0;
}

User::~User()
{
	delete[] name;
}

User::User(const User & other)
{
	CopyFrom(other);
}
User & User::operator=(const User & other)
{
	if (this != &other)
	{
		delete[] name;
		CopyFrom(other);
	}
	return *this;
}
void User::CopyFrom(const User & other)
{
	int nameLen = strlen(other.name) + 1;
	name = new char[nameLen];
	strcpy_s(name, nameLen, other.name);
	years = other.years;
	fbook = other.fbook;
	type = other.type;
	blocked = other.blocked;
	id = other.id;
}


void User::setData(const char * n, unsigned y, unsigned id, FBook * fb, Users t)
{
	delete[] name;
	int len = strlen(n)+1;
	name = new char[len];
	strcpy_s(name, len, n);
	name[len - 1] = '\0';
	years = y;
	fbook = fb;
	type = t;
	this->id = id;
	blocked = t;
}

const char * User::getName() const
{
	return name;
}

unsigned User::getId() const
{
	return id;
}
bool User::getBlocked() const
{
	if (type==Users::BLOCKED)
	{
		return true;
	}
	return false;
}
void User::addPost(const char * content, Posts postType)
{
	if (fbook->isAllowed(0, type, Actions::ADD_POST))
	{
		fbook->addPost(content, this, postType);
	}
	else
	{
		std::cout << "Sorry you are not allowed to do this" << std::endl;
	}
}

void User::removePost(unsigned id)
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




void User::changeName(const char * name)
{
	if (fbook->isAllowed(0, type, Actions::CHANGE_NAME))
	{
		if (fbook->isFree(name))
		{
			delete[] this->name;
			int len = strlen(name);
			this->name = new char[len + 1];
			strcpy_s(this->name, len+1, name);
		}
		else
		{
			std::cout << "Sorry, this name is not free :( " << std::endl;
		}
	}
	else
	{
		std::cout << "Sorry, you are not allowed to do this!" << std::endl;
	}
}
void User::view(unsigned id)
{
	if (fbook->isAllowed(0, type, Actions::VIEW))
	{
		std::cout << "viewing--------" << std::endl;
		fbook->view(id, name);
	}
	else
	{
		std::cout << "Sorry, you are not allowed to do this!" << std::endl;
	}
}
void User::viewAll(unsigned userId)
{
	if (fbook->isAllowed(0, type, Actions::VIEW))
	{
		std::cout << "viewing--------" << std::endl;
		fbook->viewAll(userId, name);
	}
	else
	{
		std::cout << "Sorry, you are not allowed to do this!" << std::endl;
	}
}

void User::setBlock(bool blocked)
{
	if (blocked)
	{
		if (type != Users::BLOCKED)
		{
			//this->blocked = type;//hold type before blocking
			type = Users::BLOCKED;
		}
		else
		{
			std::cout << "This user is already blocked";
		}
	}
	else
	{
		type = this->blocked;
	}
}