#include "LinkPost.h"
#include <cstring>

LinkPost::LinkPost()
{
}


LinkPost::~LinkPost()
{
}

Post * LinkPost::getInstance()
{
	return new LinkPost();
}

void LinkPost::visualize(const char * name)
{
	int len = strlen(name);
	char * fileName = new char[len + 6];
	strcpy_s(fileName, len + 6, name);
	fileName[len] = '.';
	fileName[len+1] = 'h';
	fileName[len+2] = 't';
	fileName[len+3] = 'm';
	fileName[len+4] = 'l';
	fileName[len+5] = '\0';

	std::ofstream ofs(fileName);
	ofs << "<a href=" << content << "> click here " << name << "<a/>";
	ofs.close();
	delete[] fileName;
}