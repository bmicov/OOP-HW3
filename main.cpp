#include "Administrator.h"
#include "Post.h"
#include "PostFactory.h"
#include "UserFactory.h"
#include "User.h"
#include "FBook.h"
#include <iomanip>

unsigned makeNumber(const char * ptr)
{
	int i = 0;
	int num = 0;
	while (ptr[i] != ' ' && ptr[i]!='\0')
	{
		i++;
	}
	i--;
	int n = i;
	i = 0;
	while (i<=n)
	{
		num = num + (ptr[i] - '0')*pow(10,n-i);
		i++;
	}
	return num;
}
int main()
{
	std::cout << "";
	FBook * fb = new FBook;
	//User * adminkata = fb->getUser("Admin");
	char input[512];
	int years;
	char * tok = new char;
	char * nextTok = new char;
	
	const char delim = ' ';
	do
	{
		std::cin.getline(input, 512);
		tok = strtok_s(input, &delim, &nextTok); 
		User * us;
		if (strcmp(input, "quit") == 0)
		{
			break;
		}
		if (strcmp(input, "info") == 0)
		{
			fb->printPosts();
			fb->printUsers();
			continue;
		}	
		if ((us = fb->getUser(tok)) == nullptr)
		{
			std::cout << "No such user!" << std::endl;
		}
		else
		{
			
			tok = strtok_s(NULL, &delim, &nextTok);
			if (strcmp(tok, "post") == 0)
			{
				tok = strtok_s(NULL, &delim, &nextTok);
				if (strcmp(tok, "[text]") == 0)
				{
					us->addPost(nextTok, Posts::TEXT_POST);
					continue;
				}
				if (strcmp(tok, "[image]") == 0)
				{
					us->addPost(nextTok, Posts::PIC_POST);
					continue;
				}
				if (strcmp(tok, "[url]") == 0)
				{
					us->addPost(nextTok, Posts::LINK_POST);
					continue;
				}

			}
			if (strcmp(tok, "remove_post") == 0)
			{
				us->removePost(makeNumber(nextTok));
				continue;
			}
			if (strcmp(tok, "add_user") == 0)
			{
				tok = strtok_s(NULL, &delim, &nextTok);
				char * tok2 = strtok_s(NULL, &delim, &nextTok);
				us->addUser(tok, makeNumber(tok2), Users::SIMPLE_USER);
				continue;
			}
			if (strcmp(tok, "add_moderator") == 0)
			{
				tok = strtok_s(NULL, &delim, &nextTok);
				char * tok2 = strtok_s(NULL, &delim, &nextTok);
				us->addUser(tok, makeNumber(tok2), Users::MODERATOR);
				continue;
			}
			if (strcmp(tok, "remove_user") == 0)
			{
				tok = strtok_s(NULL, &delim, &nextTok);
				us->removeUser(tok);
				continue;
			}
			if (strcmp(tok, "block") == 0)
			{
				tok = strtok_s(NULL, &delim, &nextTok);
				us->block(tok);
				continue;
			}
			if (strcmp(tok, "unblock") == 0)
			{
				tok = strtok_s(NULL, &delim, &nextTok);
				us->unblock(tok);
				continue;
			}
			if (strcmp(tok, "view_post") == 0)
			{
				tok = strtok_s(NULL, &delim, &nextTok);
				us->view(makeNumber(tok));
				continue;
			}
			if (strcmp(tok, "view_post") == 0)
			{
				tok = strtok_s(NULL, &delim, &nextTok);
				us->view(makeNumber(tok));
				continue;
			}
			if (strcmp(tok, "view_all_posts") == 0)
			{
				tok = strtok_s(NULL, &delim, &nextTok);
				User * reviewedUser = fb->getUser(tok);
				us->viewAll(reviewedUser->getId());
				continue;
			}
			if (strcmp(tok, "change_name") == 0)
			{
				tok = strtok_s(NULL, &delim, &nextTok);
				us->changeName(tok);
				continue;
			}
		}
	} while (true);
	
}