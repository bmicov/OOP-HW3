#include "Post.h"
#include <cstring>

Post::Post()
{
	content = new char[1];
	content[0] = '\0';
	id = 0;
	addedBy = 0;
}

Post::~Post()
{
	delete[] content;
}
void Post::CopyFrom(const Post & other)
{
	int len = strlen(other.content) + 1;
	content = new char[len];
	strcpy_s(content, len, other.content);
	id = other.id;
	addedBy = other.addedBy;
}
Post::Post(const Post & other)
{
	CopyFrom(other);
}

Post & Post::operator=(const Post & other)
{
	if (this!=&other)
	{
		delete[] content;
		CopyFrom(other);
	}
	return *this;
}
unsigned Post::getId()
{
	return id;
}
const char * Post:: getContent()
{
	return content;
}
unsigned Post::getAddedBy()
{
	return addedBy;
}
void Post::setContent(const char * cont, unsigned id, unsigned ab)
{
	int len = strlen(cont) + 1;
	content = new char[len];
	strcpy_s(content, len, cont);
	content[len-1] = '\0';
	this->id = id;
	addedBy = ab;
}
