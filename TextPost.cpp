#include "TextPost.h"
#include "User.h"

TextPost::TextPost()
{

}


TextPost::~TextPost()
{
}

Post * TextPost::getInstance()
{
	return new TextPost();
}
void TextPost::visualize(const char * name)
{
	int len = strlen(name);
	char * fileName = new char[len + 6];
	strcpy_s(fileName, len + 6, name);
	fileName[len] = '.';
	fileName[len + 1] = 'h';
	fileName[len + 2] = 't';
	fileName[len + 3] = 'm';
	fileName[len + 4] = 'l';
	fileName[len + 5] = '\0';
	std::ofstream ofs(fileName);
	ofs << "<p>" << content <<"</p>";
	ofs.close();
	delete[] fileName;
}