#pragma once
#include <fstream>
enum Posts
{
	LINK_POST,
	TEXT_POST,
	PIC_POST
};
class Post
{
public:
	Post();
	Post & operator=(const Post & other);
	Post(const Post & other);
	virtual ~Post();
	void setContent(const char * content, unsigned id, unsigned ab);
	unsigned getId();
	const char * getContent();
	unsigned getAddedBy();

	virtual Post * getInstance() = 0;
	virtual void visualize(const char * name) = 0;
protected:
	void CopyFrom(const Post & other);
protected:
	char * content;
	unsigned id;
	unsigned addedBy; //id of user
};
