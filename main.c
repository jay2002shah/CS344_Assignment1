#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct movie {
	char * title;
	int  year;
	char * language[5];
	float rating;
	struct movie* next;
};


struct movie *createMovie(char *currL){
	
	struct movie *currMv = malloc(sizeof(struct movie));
	char *svptr;

	char *token = strtok_r(currL, ",", &svptr);
	currMv->title = calloc(strlen(token) + 1, sizeof(char));
	strcpy(currMv->title, token);

	// year
	token = strtok_r(NULL, ",", &svptr);
	currMv->year = atoi(token);

	// language
	token = strtok_r(NULL, ",", &svptr);
	char * svptr2;
	char * semitok = strtok_r(token, ";", &svptr2);
	int c = 0;
	while(true){
		currMv->language[c] = calloc(strlen(semitok) + 1, sizeof(char));
		strcpy(currMv->language[c], semitok);
		semitok = strtok_r(NULL, ";", &svptr2);
		if(semitok == NULL){
			break;
		}
		c++;
	}

	// rating
	token = strtok_r(NULL, "\n", &svptr);
	currMv->rating = atof(token);

	currMv->next = NULL;
	
	return currMv;
}

void printMovie(struct movie *movies){
	printf("%s,%d,%s,%f\n",
		movies->title,
		movies->year,
		movies->language,
		movies->rating
	);
}

void show_movie_by_year(struct movie *movies, int year){
	
	int c = 0;
	while(movies != NULL){
		if(movies->year == year) {
			printf("%s\n", movies->title);
			c++;			
		}
		movies = movies->next;
	}
	if(c == 0){
		printf("\n");
		printf("No data about movies relaased in the year %d\n", year);
	}
}

void show_highest_rated(struct movie *movies){
	
	int yearA[2021] = {0};
	float highest_rating_year[2021] = {0};
	char *movie_t[2021] = {0};

	while(movies != NULL) {
		if(highest_rating_year[movies->year] < movies->rating){
			
			highest_rating_year[movies->year] = movies->rating;
			yearA[movies->year] = movies->year;
			movie_t[movies->year] = movies->title;			
		}
		movies = movies->next;
	}
	for(int i = 0; i < 2021; i++){
		
		if(highest_rating_year[i] > 0) {
			printf("%d, %f, %s\n", yearA[i], highest_rating_year[i], movie_t[i]);
		}
	}
	printf("\n");
}

void findMovieInLang(struct movie* movies, char* userInput){
	bool here = false;
	while(movies != NULL){
		for(int i = 0; i < 5; i++){
			if(movies->language[i] != NULL && strstr(movies->language[i], userInput) != NULL){
				printf("%s, %s\n", movies->title, movies->year);
				here = true;				
			}
		}
		movies = movies->next;
	}
	if(!here){
		printf("There were no movies in this language\n");
	}
	printf("\n");
		
}



int main(int argc, char* argv[]){
	if (argc < 2) {
		printf("You must provide the name of the file to process\n");
	} 

	
	FILE *movies = fopen(argv[1], "r");
	if(!movies){
		printf("Failed when opening the file");
	} else {
		printf("File has opened\n");
	}

	char * currLine = NULL;
	size_t l = 0;
	char* token;
	size_t n_read;

	struct movie *head = NULL;
	struct movie *tail = NULL;
	


	int c = 0;
	while((n_read = getline(&currLine, &l, movies)) != -1){
		struct movie *newNode = createMovie(currLine);
		c++;

		if(head == NULL){
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	free(currLine);
	fclose(movies);

	int userInput;
	int year;
	char* userLang = 0;
	while(1){
		printf("1. Show movies released in the specific year\n");
		printf("2. Show highest rated movie for each year\n");
		printf("3. Show the title and year of release of all movies in a specific language\n");
		printf("4. Exit from the program\n");
		printf("\n");
		printf("Enter a choice from 1 to 4: ");
		scanf("%d", &userInput);

		switch(userInput){
			case 1:
				printf("Enter the year for which you want to see the movies: ");
				scanf("%d", &year);
				show_movie_by_year(head,year);
				break;	
			case 2:
				show_highest_rated(head);
				break;
			case 3:
				printf("Please enter the language in which you want to find movies: ");
				scanf("%s", userLang);
				findMovieInLang(head, userLang);
				break;								
			case 4:
				exit(0);
		}
	}
	
	return 0;
}
