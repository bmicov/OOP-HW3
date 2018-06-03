#include "PostFactory.h"

unsigned PostFactory::lastID = 0;
PostFactory::PostFactory()
{
}
PostFactory::~PostFactory()
{
}
Post * PostFactory::getLinkPost(const char * url, User * addedBy)
{	
	LinkPost * lp = new LinkPost();
	PostFactory::lastID++;
	lp->setContent(url, PostFactory::lastID, addedBy->getId());
	return lp;
}

Post * PostFactory::getPicPost(const char * path, User * addedBy)
{
	PicPost * pp = new PicPost();
	PostFactory::lastID++;
	pp->setContent(path, PostFactory::lastID, addedBy->getId());
	return pp;
}

Post * PostFactory::getTextPost(const char * text, User * addedBy)
{
	TextPost * tp = new TextPost();
	PostFactory::lastID++;
	tp->setContent(text, PostFactory::lastID, addedBy->getId());
	return tp;
}