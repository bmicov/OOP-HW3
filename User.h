#pragma once
#include "Post.h"
#include <iostream>
enum Users
{
	SIMPLE_USER,
	MODERATOR,
	ADMINISTRATOR,
	BLOCKED
};
class FBook;
class User
{
public:
	User();
	virtual ~User();
	User(const User & other);
	User & operator=(const User & other);
	//interface functions
	virtual void removePost(unsigned id) = 0;//all
	virtual void addPost(const char * content, Posts postType);//all
	void setData(const char * name, unsigned years, unsigned id, FBook * fbook, Users t);

	virtual void block(const char * name) = 0; //moderator/administrator
	virtual void unblock(const char * name) = 0; //moderator/administrator
	virtual void addUser(const char * name, unsigned years, Users userType) = 0; //administrator
	virtual void removeUser(const char * name) = 0;//admin
	virtual User * getInstance() = 0;
	void changeName(const char * name);//all
	void view(unsigned id) ;//all
	void viewAll(unsigned userId);
	const char * getName() const;
	unsigned getId() const;
	bool getBlocked() const;
	void setBlock(bool blocked); //true-blocked
protected:
	Users blocked;//before blocking
	Users type;
	void CopyFrom(const User & other);
	FBook * fbook; //pointer to fbook
	unsigned id;

private:
	char * name;
	unsigned years;

};

