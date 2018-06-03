#pragma once
#include "Post.h"
#include "PicPost.h"
#include "LinkPost.h"
#include "TextPost.h"
#include "User.h"
class PostFactory
{
public:
	Post * getPicPost(const char * path, User * addedBy);
	Post * getLinkPost(const char * url, User * addedBy);
	Post * getTextPost(const char * text, User * addedBy);

	
	static unsigned lastID;
	PostFactory();
	~PostFactory();
};

