#pragma once
#include "Post.h"
#include "Administrator.h"
#include "PostFactory.h"
#include "UserFactory.h"
enum Actions
{
	REMOVE,
	BLOCK,
	UNBLOCK,
	ADD_POST,
	ADD_USER,
	REMOVE_USER,
	VIEW,
	CHANGE_NAME
};
class FBook
{
private:
	User ** users;
	Post ** posts;
	unsigned usersCnt;
	unsigned usersCpcty;
	unsigned postsCnt;
	unsigned postsCpcty;

	PostFactory pFactory;
	UserFactory uFactory;

	void resize(int factor, bool what);

public:
	FBook();
	~FBook();	
	FBook(const FBook& other);
	FBook & operator=(const FBook & other);
	void CopyFrom(const FBook & other);
	void setData(const char * name, unsigned years, FBook * fbook, Users t);
	bool isAllowed(unsigned id, Users userType, Actions action);
	User* getUser(const char * userName);
	Post * getPost(unsigned id);

	void printPosts();
	void printUsers();
	bool isFree(const char * name);
	bool checkPostId(unsigned id, int & indexInArray);

	void removePost(unsigned id);
	void blockUser(const char * name);
	void removePost(unsigned id, User * u);
	void addPost(const char * content, User * addedBy, Posts  type);
	void unblock(const char * name);
	void addUser(const char * name, unsigned years, Users  userType);
	void removeUser(const char * name);
	//void changeName(const char * old, const char * name);
	void view(unsigned id, const char * name);
	void viewAll(unsigned userId, const char* viewer);

};

