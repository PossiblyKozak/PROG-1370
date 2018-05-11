#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

#define SONG_COUNT 3

struct songInfo 
{
	char* artist;
	char* title;
};

void getSongInfo(songInfo* si, string artist, string title)
{	
	si->artist = (char*)malloc(artist.size() + 1);
	si->title = (char*)malloc(title.size() + 1);
	strcpy(si->artist, artist.c_str());
	strcpy(si->title, title.c_str());
}

void printSongInfo(songInfo* si)
{	
	for (int i = 0; i < SONG_COUNT; i++)
	{		
		cout << setw(40) << si[i].artist << setw(40) << si[i].title << endl;
	}
}

int main()
{
	songInfo si[SONG_COUNT];

	for (int i = 0; i < SONG_COUNT; i++)
	{
		string artist;
		string title;
		cout << "Please enter the artist name:";
		cin >> artist;
		cout << "Please enter the title of the song:";
		cin >> title;
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