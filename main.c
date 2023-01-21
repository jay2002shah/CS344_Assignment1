/* This is assignment1 for Operating Systems 1 which is using a CVS file that has many names of movies. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// This is a struct for the movies
struct movie{
	char title[1000];
	float rating;
	int year;
	char language[1000];
};

struct movie *processFile(char *fileName) {
	
	struct movie mv[1000];
	
	// opening the csv file in read mode
	FILE *movieFile = fopen(fileName, "r");
	
	// The file not opening error handling
	if(!movieFile) {
		printf("unable to open file\n");
		return 0;
	}else{
		printf("File is being read by the system\n");
	}

	char mvLine[4096];
	int c = 0;
	char *saveptr1;
	while(fgets(mvLine, sizeof(mvLine), movieFile)) {
		if(c >= 1){
			char* dupLine = strdup(mvLine);
			char* token = strtok_r(dupLine,",", &saveptr1);
			int i = 1;
			while(token != NULL){
				// getting all the fields from the movie line to line
				if(i == 1) strcpy(mv[c - 1].title,token);
				if(i == 2) mv[c - 1].rating = atof(token);
				if(i == 3) mv[c - 1].year = atoi(token);
				if(i == 4) strcpy(mv[c - 1].language,token);
				token = strtok_r(NULL, ",\n");
				i++;
			}
			free(dupLine);						
		}
		c++;
	}	
	
};

void printMovieList(struct movie *list){

}

int main(int argc, char** argv){
	
	// if file name was not given in the command line
	if(argc < 2 ) {
		printf("Movie file not specified!\n");
	} else {
		
		char* fileName = argv[1];
		struct movie *list = processFile(fileName);
		//printMovieList(list);

		int user_choice;
		int user_year;
		char user_lang[1000];
		while(1) {
 			printf("1. Show the movies released in the specified year\n");
			printf("2. Show highest rated movie for each year\n");
			printf("3. Show the title and year of release of all movies in a specific language\n");
			printf("4. Exit from the program\n");

			// Ask user for a choice
			printf("Enter a choice from 1 to 4: ");
			scanf("%d", &user_choice);

			switch(user_choice){
				case 1:
					// User chooses the first option
					printf("Enter the year for which you want to see the movies: ");
					scanf("%d", &user_year);
					break;
				case 2:
					// User chooses the second option
				case 3: 
					// User choosed the third option
					printf("Enter the language for which you want to see movies: ");
					scanf("%s", &user_lang);
					break;
				case 4: 
					// User chooses the fourth option
					exit(0);
			}		
		
		}
	}
	return 0;
}


