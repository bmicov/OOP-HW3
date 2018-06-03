#pragma once
#include "Post.h"
class PicPost : public Post
{
public:
	PicPost();
	~PicPost();
	Post * getInstance();
	void visualize(const char * name);

};

