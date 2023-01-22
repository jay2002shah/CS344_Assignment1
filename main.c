#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


struct movie {
        char  title[1000];
        int  year;
        char  language[1000];
        float  rating;
        //struct movie* next;
};

/*

struct movie* createMovie(char* currLine) {
        
        struct movie* currMovie = malloc(sizeof(struct movie));
        char * saveptr = NULL;
        char * languageStr = NULL;
        char* ratingStr = NULL;

        char * token = strtok_r(currLine, " ", &saveptr);
	currMovie->title = calloc(strlen(token) + 1, sizeof(char));
        strcpy(currMovie->title, token);

	token = strtok_r(NULL, " ", &saveptr);
	currMovie->year = calloc(strlen(token) + 1, sizeof(char));
	strcpy(currMovie->year, token);
*/	
/*

        token = strtok_r(NULL, ",", &saveptr);
	*(currMovie->year) = atoi(token);

	// The next token is the language
	token = strtok_r(NULL, "]", &saveptr);
	languageStr = calloc(strlen(token) + 1, sizeof(char));
	strcpy(languageStr, token);
	memmove(&languageStr[0], &languageStr[1], strlen(languageStr));	

	token = strtok_r(NULL, " ", &saveptr);
	ratingStr = calloc(strlen(token) + 1, sizeof(char));
	*(currMovie->rating) = atof(token);	

        currMovie->next = NULL;

        
        return currMovie;
}


struct movie* processFile(char* filePath)
{
        FILE * movieFile = fopen(filePath, "r");

        char * currLine = NULL;
        size_t len = 0;
        ssize_t nread;
        int count = 0;

        struct movie* head = NULL;
        struct movie* tail = NULL;

        getline(&currLine, &len, movieFile);

        while ((nread = getline(&currLine, &len, movieFile)) != -1)
        {
                count++;

                struct movie* newNode = createMovie(currLine);

                if (head == NULL)
                {
                        head = newNode;
                        tail = newNode;
                }
                else
                {
                        tail->next = newNode;
                        tail = newNode;
                }
        }
        printf("Parsed data for %d movies\n", count);
        free(currLine);
        fclose(movieFile);
        return head;
}


int userInput(int userValue) {
        int arraySize = 10;
        char strChoice[arraySize];
        memset(strChoice, '\0', arraySize);

        printf("Enter a choice from 1 to 4: ");
        fgets(strChoice, arraySize, stdin);
        userValue = strtol(strChoice, NULL, 0);

        if (userValue >= 1 && userValue <= 4)
                return userValue;

        printf("That was not a valid choice, please try again!\n\n");

        return 0;
}

*/
/*
void dataOutput(int userValue, struct movie* llMovie) {
        if (userValue == 1) { 
                int arraySize = 10;
                char userInput[arraySize];
                memset(userInput, '\0', arraySize);
                int userInt = 0;
                int count = 0;
                int highCount = 0;
                struct movie * temp;

                printf("Enter the year for which you want to see movies: ");
                fgets(userInput, arraySize, stdin);
                userInt = strtol(userInput, NULL, 0);

                temp = llMovie;
                while (temp != NULL) {
                        if (temp->year == userInt) {
                                printf("%s\n", temp->title);
                                count++;
                        }
                        temp = temp->next;
                }

                if (count == 0)
                        printf("No data about movies released in the year %d\n", userInt);
                printf("\n");
        }

        if (userValue == 2) { 
                struct movie* temp;
                int arraySize = 30;
                int yearArray[arraySize];
                int count = 0;
                int arrayCount = 0;
                int movieCount = 0;
                int highCount = 0;
                float highRating = 0.0;

                for (int i = 0; i < arraySize; i++)
                        yearArray[i] = 0;

                temp = llMovie;
                while (temp != NULL) {
                        yearArray[arrayCount] = temp->year;
                        temp = temp->next;
                        arrayCount++;
                        movieCount++;
                }

                for (int i = 0; i < arrayCount; i++) {
                        for (int j = i + 1; j < arrayCount; j++) {
                                if (yearArray[i] == yearArray[j]) {
                                        for (int k = j; k < arrayCount; k++)
                                                yearArray[k] = yearArray[k + 1];
                                        arrayCount--;
                                        j--;
                                }
                        }
                }

                for (int a = 0; a < arrayCount; a++) {
                        count = 0;
                        highCount = 0;
                        highRating = 0;
                        temp = llMovie;
                        for (int b = 0; b < movieCount; b++) {
                                if (yearArray[a] == temp->year) {
                                        if (*(temp->rating) > highRating) {
                                                highRating = *(temp->rating);
                                                highCount = count;
                                        }
                                }
                                count++;
                                temp = temp->next;
                        }
                        temp = llMovie;
                        for (int c = 0; c < highCount; c++) {
                                temp = temp->next;
                        }

                        printf("%d %.1f %s\n", temp->year, *(temp->rating), temp->title);
                }
                printf("\n");
        }

        if (userValue == 3) {
                struct movie* temp;
                int movieSize = 0;
                int count = 0;
                int arraySize = 20;
                char userArray[arraySize];
                memset(userArray, '\0', arraySize);
                char * movieLanguage;
                char * userLanguage;

                temp = llMovie;
                while (temp != NULL) {
                        temp = temp->next;
                        movieSize++;
                }

                printf("Enter the language for which you want to see movies (Capitalize first letter): ");
                scanf("%s", userArray);

                temp = llMovie;
                for (int i = 0; i < movieSize; i++) {
                        for (int j = 0; j < 5; j++) {
                                if (temp->language[j][0] == NULL)
                                        break;
                                movieLanguage = temp->language[j][0];
                                userLanguage = userArray;
                                if (*(userLanguage) == *(movieLanguage)) {
                                        printf("%d %s\n", temp->year, temp->title);
                                        count++;
                                }
                        }
                        temp = temp->next;
                }

                if (count == 0)
                        printf("No movies released in %s\n", userArray);
                printf("\n");

                fgets(userLanguage, arraySize, stdin);
        }
}

*/



int main(int argc, char* argv[]) {
        if (argc < 2) {
                printf("You must provide the name of the file to process\n");
                return EXIT_FAILURE;
        } else {
	        //struct movie * list = processFile(argv[1]);
		
		struct movie m[1000];

        	char* filename = argv[1];

        	FILE* file = fopen(filename, "r");

        	if(file == NULL){
            		printf("There is some error in opening file %s", filename);
            		return 0;
        	}
        	char line[4096];

        	int count = 0;
		
        	while (fgets(line, sizeof(line), file))
        	{
            		if(count >= 1){
                		char* tp = strdup(line);
                		char* tok = strtok(tp, ",");
                		int k = 1;
                		while(tok != NULL){
                    			if(k == 1)  strcpy(m[count - 1].title,tok);
                    			if(k == 2)  m[count - 1].rating = atof(tok);
                    			if(k == 3)  m[count - 1].year = atoi(tok);
                    			if(k == 4)  strcpy(m[count - 1].language, tok);
                    			tok = strtok(NULL, ",\n");
                    			k++;
                		}
                		free(tp);
            		}
            		count++;
        	}

        	printf("Processed file %s and parsed data for %d movies\n", filename, count);




		int userInput;
		int year;
		char lang[1000];
	
		while(1) {	
			printf("1. Show movies released in the specified year\n");
			printf("2. Show highest reted movie for each year\n");
			printf("3. Show the title and year of release of all movies in a specific language\n");
			printf("4. Exit from the program\n");
			printf("\nEnter a choice from 1 to 4: ");

			//read the user inpit
			scanf("%d", &userInput);

			if(userInput == 1){
				printf("Enter the year for which you want to see movies: ");
				scanf("%d", &year);
				break;
			} else if(userInput == 2){
				printf("Showing the highest rated movie: ");
				break;
			} else if(userInput == 3) {
				printf("Enter the Language for which you want to see movies: ");
				scanf("%s", lang);
				break;
			} else if(userInput == 4) {
				exit(0);
			}
				
		}

        }

	return 0;
}
