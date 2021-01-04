#include<stdio.h>

struct Artists
{
	char *ArtistName;
	char *Gender;
	char *Genre;
	int Age;
	int NoOfAlbums;
};

int main()
{
	struct Artists taylor;
	
	taylor.ArtistName = "Taylor Swift";
	taylor.Gender = "Female";
	taylor.Genre = "Country and Pop";
	taylor.Age = 29;
	taylor.NoOfAlbums = 7;
	
	printf("ARTIST'S NAME:\t\t%s\nGENDER:\t\t\t%s\nGENRE:\t\t\t%s\nAGE:\t\t\t%d\nNO. OF ALBUMS RELEASED: %d\n", taylor.ArtistName, taylor.Gender, taylor.Genre, taylor.Age, taylor.NoOfAlbums);
	
	return 0;
}

