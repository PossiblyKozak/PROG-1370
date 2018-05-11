/*
*  FILE          : mini1.cpp
*  PROJECT       : PROG1370 - Mini-Assignment #1
*  PROGRAMMER    : Alex Kozak
*  FIRST VERSION : 2018-05-11
*  DESCRIPTION   :
*    The functions in this file are used to take in song and artist names, store them in mallock-ed memory, display them, then free the memory.
*/
#include <string>
#include <iostream>
#include <iomanip>

#define SONG_COUNT 10

struct songInfo 
{
	char* artist;
	char* title;
};

void getSongInfo(songInfo* si, std::string artist, std::string title)
{	
	si->artist = (char*)malloc(artist.size() + 1);
	si->title = (char*)malloc(title.size() + 1);
	if (si->artist != nullptr && si->title != nullptr)
	{
		strcpy(si->artist, artist.c_str());
		strcpy(si->title, title.c_str());
	}
}

void printSongInfo(songInfo* si)
{	
	for (int i = 0; i < SONG_COUNT; i++)
	{		
		std::cout << std::left << std::setw(40) << si[i].artist << std::setw(40) << si[i].title << std::endl;
	}
}

int main(void)
{
	songInfo si[SONG_COUNT];

	for (int i = 0; i < SONG_COUNT; i++)
	{
		std::string artist;
		std::string title;
		std::cout << "Please enter the artist name:";
		std::cin >> artist;
		std::cout << "Please enter the title of the song:";
		std::cin >> title;
		getSongInfo(&si[i], artist, title);
	}

	printSongInfo(si);

	for (int i = 0; i < SONG_COUNT; i++)
	{
		free(si[i].artist);
		free(si[i].title);
	}
	return 0;
}