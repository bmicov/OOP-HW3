#include "PicPost.h"


PicPost::PicPost()
{
}


PicPost::~PicPost()
{
}

Post * PicPost::getInstance()
{
	return new PicPost();
}
void PicPost::visualize(const char * name)
{
	int len = strlen(name);
	char * fileName = new char[len + 6];
	strcpy_s(fileName, len, name);

	fileName[len] = '.';
	fileName[len + 1] = 'h';
	fileName[len + 2] = 't';
	fileName[len + 3] = 'm';
	fileName[len + 4] = 'l';
	fileName[len + 5] = '\0';
	std::ofstream ofs(fileName);
	ofs << "<img src=" << content << ">";
	ofs.close();
	delete[] fileName;
}