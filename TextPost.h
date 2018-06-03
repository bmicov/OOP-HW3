#pragma once
#include "Post.h"
class TextPost :
	public Post
{
public:
	TextPost();
	~TextPost();
	Post * getInstance();
	void visualize(const char * name);
};

