#include "FBook.h"


FBook::FBook()
{

	users = new User*[1];
	users[0] = uFactory.getAdministrator("Admin", 123, this);
	posts = new Post*[1];
	posts[0] = pFactory.getLinkPost("Hello World", users[0]);
	usersCnt = 1;
	usersCpcty = 1;
	postsCnt = 0;
	postsCpcty = 1;
	std::cout << "FBook created!" << std::endl;
}

FBook::~FBook()
{
	for (size_t i = 0; i < usersCnt; i++)
	{
		delete users[i];
	}
	delete[] users;
	for (size_t i = 0; i < postsCnt; i++)
	{
		delete posts[i];
	}
	delete[] posts;
}

FBook::FBook(const FBook & other)
{
	posts = new Post*[other.postsCpcty];
	users = new User*[other.usersCpcty];
	CopyFrom(other);
}

FBook & FBook::operator=(const FBook & other)
{
	if (this != &other)
	{
		for (int i = 0; i < postsCnt; i++)
		{
			delete posts[i];
		}
		delete[] posts;
		for (int i = 0; i < usersCnt; i++)
		{
			delete users[i];
		}
		delete[] users;

		posts = new Post*[other.postsCpcty];
		users = new User*[other.usersCpcty];

		CopyFrom(other);
	}
	return *this;
}

void FBook::CopyFrom(const FBook & other)
{

	for (size_t i = 0; i < other.postsCnt; i++)
	{
		posts[i] = other.posts[i]->getInstance();
		*posts[i] = *other.posts[i];
	}

	for (size_t i = 0; i < other.usersCnt; i++)
	{
		users[i] = other.users[i]->getInstance();
		*users[i] = *other.users[i];
	}
	pFactory = other.pFactory;
	uFactory = other.uFactory;

	usersCnt = other.usersCnt;
	usersCpcty = other.usersCpcty;
	
	postsCnt = other.postsCnt;
	postsCpcty = other.postsCpcty;
}

Post * FBook::getPost(unsigned id)
{
	for (size_t i = 0; i < postsCnt; i++)
	{
		if (posts[i]->getId() == id)
		{
			return posts[i];
		}
	}
	return nullptr;
}
void FBook::printUsers()
{
	std::cout << "Printing users" << std::endl;
	for (size_t i = 0; i < usersCnt; i++)
	{
		std::cout << users[i]->getId() << " ";
		std::cout << users[i]->getName() << " ";
		std::cout << "Blocked: " << users[i]->getBlocked();
		std::cout << std::endl;
	}
}
void FBook::printPosts()
{
	std::cout << "Printing posts" << std::endl;
	for (size_t i = 0; i < postsCnt; i++)
	{
		std::cout << posts[i]->getId() << " Content: " << posts[i]->getContent() <<" AddedBy: "<<posts[i]->getAddedBy()<< std::endl;
	}
}
bool FBook::checkPostId(unsigned id, int & indexInArr)
{
	for (size_t i = 0; i < postsCnt; i++)
	{
		if (posts[i]->getId() == id)
		{
			indexInArr = i;
			return true;
		}
	}
	return false;
}
User * FBook::getUser(const char * name) 
{
	for (int i = 0; i < usersCnt; i++)
	{
		if (strcmp(name, users[i]->getName()) == false)
		{
			return users[i];
		}
	}
	return nullptr;
}

void FBook::resize(int factor, bool what)
{
	if (what)//posts
	{
		Post ** tmp = posts;
		if (factor < 0)
		{
			factor = factor * (-1);
			posts = new Post*[postsCpcty / factor];
			postsCpcty /= factor;
		}
		else
		{
			posts = new Post*[postsCpcty * factor];
			for (size_t i = 0; i < postsCnt; i++)
			{
				posts[i] = tmp[i]->getInstance();
			}
			postsCpcty *= factor;
		}
		for (int i = 0; i < postsCnt; i++)
		{
			*posts[i] = *tmp[i];
		}
		for (size_t i = 0; i < postsCnt; i++)
		{
			delete tmp[i];
		}
		delete[] tmp;
	}
	else
	{
		User ** utmp = users;
		if (factor < 0)
		{
			factor = factor * (-1);
			users = new User*[usersCpcty / factor];
			usersCpcty /= factor;
		}
		else
		{
			users = new User * [usersCpcty * factor];
			for (size_t i = 0; i < usersCnt; i++)
			{
				users[i] = utmp[i]->getInstance();
			}
			usersCpcty *= factor;
		}

		for (size_t i = 0; i < usersCnt; i++)
		{
			*users[i] = *utmp[i];
		}
		for (size_t i = 0; i < usersCnt; i++)
		{
			delete utmp[i];
		}
		delete[] utmp;

	}
}
void FBook::removePost(unsigned i)
{
	int indexInArr = 0;
	if (checkPostId(i, indexInArr) == false)
	{
		std::cout << "No such id." <<  std::endl;
		return;
	}

	if (postsCnt<=postsCpcty/2)
	{
		resize(-2, true);
	}
	if (postsCnt == 1)
	{
		delete posts[0];
		postsCnt--;
		return;
	}
	if (indexInArr == postsCnt - 1)
	{
		delete posts[indexInArr];
	}
	for (size_t k = indexInArr; k < postsCnt-1; k++)
	{
		delete posts[k];
		posts[k] = posts[k + 1]->getInstance();
		*posts[k] = *posts[k + 1];
	}
	postsCnt--;
	std::cout << "Post " << i << " removed!" << std::endl;
}
void FBook::addPost(const char * content, User * addedBy, Posts type)
{
	Post * p = nullptr;
	
	if (postsCnt>=postsCpcty)
	{
		resize(2, true);
	}
	if (type == Posts::LINK_POST)
	{
		p = pFactory.getLinkPost(content, addedBy);
	}
	if (type == Posts::PIC_POST)
	{
		p = pFactory.getPicPost(content, addedBy);
	}
	if (type == Posts::TEXT_POST)
	{
		p = pFactory.getTextPost(content, addedBy);
	}
	if (p != nullptr)
	{
		posts[postsCnt] = p;
		postsCnt++;
	}
	std::cout << addedBy->getName() << " posted" << std::endl;
}
void FBook::addUser(const char * name, unsigned years, Users  userType)
{
	if (usersCnt >= usersCpcty)
	{
		resize(2, false);
	}
	User * u=nullptr;
	if (userType == Users::ADMINISTRATOR)
	{
		//u = uFactory.getAdministrator(name, years, this);
		std::cout << "Sorry, it is impossible to add administrator" << std::endl;
		return;
	}
	if (userType == Users::MODERATOR)
	{
		u = uFactory.getModerator(name, years, this);
	}
	if (userType == Users::SIMPLE_USER)
	{
		u = uFactory.getSimpleUser(name, years, this);
	}
	if (u != nullptr)
	{
		users[usersCnt] = u;
		usersCnt++;
	}
	std::cout << "User added: " << "Name: " << name << " Years: " << years << std::endl;
}
bool FBook::isAllowed(unsigned id, Users t, Actions a)
{
	//std::cout << "CHECKING IF " << t << "IS ALLOWED TO " << a << std::endl;
	//here only by adding some if we can forbid someone to do something
	if (t == Users::BLOCKED)
	{
		if (a==Actions::VIEW)
		{
			return true;
		}
		return false;
	}
	return true;
}

void FBook::blockUser(const char * name)
{
	User * u = getUser(name);
	if (u==nullptr)
	{
		std::cout << "No such user" << std::endl;
	}
	else
	{
		u->setBlock(true);
		std::cout << name << " blocked." << std::endl;
	}

}

void FBook::unblock(const char * name)
{
	User * u = getUser(name);
	if (u == nullptr)
	{
		std::cout << "No such user" << std::endl;
	}
	else
	{
		u->setBlock(false);
		std::cout << name << " unblocked." << std::endl;
	}
}

//void FBook:: changeName(const char * old, const char * name)
//{
//}

void FBook:: view(unsigned id, const char * name)
{
	Post * p = getPost(id);
	if (p != nullptr)
	{
		p->visualize(name);
		std::cout << "Visualizing post " << id << std::endl;
	}
}
void makeName(const char * viewerName, char *& newName, unsigned postId)
{
	unsigned idCopy = postId;
	int cnt = 0;
	while (idCopy != 0)
	{
		idCopy /= 10;
		cnt++;
	}
	idCopy = postId;
	char * idStr = new char[cnt+1];
	int i = 0;
	//int cntCpy = cnt;
	while (idCopy)
	{
		idStr[i] = idCopy % 10 + '0';
		i++;
		idCopy /= 10;
	}
	idStr[cnt] = '\0';
	newName = new char[strlen(viewerName) + cnt + 1];
	strcpy_s(newName, strlen(viewerName)+1, viewerName);
	strcpy_s(newName + strlen(viewerName), strlen(idStr)+1, idStr);
}
void FBook::viewAll(unsigned userId, const char* viewer)
{
	
	for (size_t i = 0; i < postsCnt; i++)
	{
		char * newName = nullptr;
		if (posts[i]->getAddedBy() == userId)
		{
			makeName(viewer, newName, posts[i]->getId());
			posts[i]->visualize(newName);
			delete[] newName;
		}
	}
	std::cout << "Visualizing posts. " << std::endl;

}

void FBook::removeUser(const char * name)
{
	int indexInArr = 0;
	User * u;
	if ((u = getUser(name)) == nullptr)
	{
		std::cout << "No such user." << std::endl;
		return;
	}
	for (size_t i = 0; i < usersCnt; i++)
	{
		if (strcmp(name, users[i]->getName()) == false)
		{
			indexInArr = i;
		}
	}
	if (usersCnt == 1)
	{
		std::cout << "Cannot delete the Admin. :(" << std::endl;
		return;
	}
	if (usersCnt <= usersCpcty / 2)
	{
		resize(-2, false);
	}
	
	if (indexInArr == usersCnt - 1)
	{
		delete users[indexInArr];
		usersCnt--;
		return;
	}
	for (size_t k = indexInArr; k < usersCnt - 1; k++)
	{
		delete users[k];
		users[k] = users[k + 1]->getInstance();
		*users[k] = *users[k + 1];
	}
	usersCnt--;
}
bool FBook::isFree(const char * name)
{
	for (size_t i = 0; i < usersCnt; i++)
	{
		if (strcmp(users[i]->getName(), name) == false)
		{
			return false;
		}
	}
	return true;
}