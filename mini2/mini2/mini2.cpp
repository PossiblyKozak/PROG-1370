/*
*  FILE          : mini2.cpp
*  PROJECT       : PROG1370 - Mini-Assignment #2
*  PROGRAMMER    : Alex Kozak
*  FIRST VERSION : 2018-05-11
*  DESCRIPTION   :
*    The functions in this file are used to take in song and artist names, store them in mallock-ed memory CONTAINED IN A LINKED LIST, display them, then free the memory.
*/
#include <string>
#include <iostream>
#include <iomanip>

#define SONG_COUNT 10

struct songInfo
{
	char* artist;
	char* title;
	songInfo* next;
};

songInfo* getSongInfo(songInfo *head, std::string artist, std::string title)
{
	songInfo* block = NULL;
	songInfo* ptr = NULL;

	block = (songInfo*)malloc(sizeof(songInfo));
	block->artist = (char*)malloc(artist.size() + 1);
	block->title = (char*)malloc(title.size() + 1);
	block->next = NULL;

	if (block->artist != nullptr && block->title != nullptr)
	{
		strcpy(block->artist, artist.c_str());
		strcpy(block->title, title.c_str());
	}

	if (head == NULL)
	{
		head = block;
	}
	else
	{
		ptr = head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = block;
	}
	return head;
}

void printSongInfo(songInfo* si)
{
	while(si != NULL)
	{
		std::cout << std::setw(40) << si->artist << std::setw(40) << si->title << std::endl;
		si = si->next;
	}
}

int main()
{
	songInfo *head = NULL;	

	for (int i = 0; i < SONG_COUNT; i++)
	{
		std::string artist;
		std::string title;
		std::cout << "Please enter the artist name:";
		std::cin >> artist;
		std::cout << "Please enter the title of the song:";
		std::cin >> title;
		head = getSongInfo(head, artist, title);
	}

	printSongInfo(head);
	songInfo *si = head->next;
	
	while (si != NULL)
	{
		free(si->artist);
		free(si->title);
		si = si->next;
	}

	return 0;
}