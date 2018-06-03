#pragma once
#include "Post.h"
class LinkPost :
	public Post
{
public:
	LinkPost();
	~LinkPost();
	Post * getInstance();
	void visualize(const char * name);

};

