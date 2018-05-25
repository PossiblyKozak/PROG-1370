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
#include "LinkedList.h"

#define SONG_COUNT 3



struct songInfo
{
	char* artist;
	char* title;
};



songInfo* getSongInfo(std::string artist, std::string title)
{
	songInfo* block = NULL;

	block = (songInfo*)malloc(sizeof(songInfo));
	block->artist = (char*)malloc(artist.size() + 1);
	block->title = (char*)malloc(title.size() + 1);

	if (block->artist != nullptr && block->title != nullptr)
	{
		strcpy(block->artist, artist.c_str());
		strcpy(block->title, title.c_str());
	}
	return block;
}



void freeSongInfo(void* item)
{
	songInfo* si = (songInfo*)item;
	free(si->artist);
	free(si->title);
	free(si);
}



void printSongInfo(void* info)
{
	songInfo* si = (songInfo *)info;
	std::cout << std::left << std::setw(40) << si->artist << std::setw(40) << si->title << std::endl;
}



int main()
{
	LinkedList songInfoList;
	songInfo si;

	for (int i = 0; i < SONG_COUNT; i++)
	{
		std::string artist;
		std::string title;
		std::cout << "Please enter the artist name:";
		std::getline(std::cin, artist);
		std::cout << "Please enter the title of the song:";
		std::getline(std::cin, title);
		songInfoList.AddNode(getSongInfo(artist, title));
	}
	songInfoList.PrintNodes(printSongInfo);
	songInfoList.FreeNodes(freeSongInfo);
	return 0;
}