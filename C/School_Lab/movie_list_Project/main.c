#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 256

typedef struct Movie {
    int id;
    char title[MAXLEN];
    char type;       
    char platform[MAXLEN];
    char status;     
    int rating;      
    char note[MAXLEN];
} MOVIE;

void addtitle(MOVIE **movies, int *movieCount);
void clearInputBuffer(void);
void showList(MOVIE *movies, int movieCount);
void filter(MOVIE *movies, int movieCount);
void SearchTitle(MOVIE *movies, int movieCount);
void ChangeMovie(MOVIE *movies, int movieCount);
void stats(MOVIE *movies, int movieCount);
void Taksinomish(MOVIE *movies, int movieCount);
void saveToFile(MOVIE *movies, int movieCount);
void loadFromFile(MOVIE **movies, int *movieCount);

int main() {
    MOVIE *movies = NULL;
    int movieCount = 0;
    int choice;

    do {
        printf("\n===== MOVIE WATCHLIST MENU =====\n");
        printf("1. Add Title\n");
        printf("2. Show All\n");
        printf("3. Filter by Status/Rating\n");
        printf("4. Search movie by title\n");
        printf("5. Change movie information\n");
        printf("6. Stats for movies\n");
        printf("7. Sort movies\n");
        printf("8. Save to file\n");
        printf("9. Load from file\n");
        printf("10. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1: addtitle(&movies, &movieCount); break;
            case 2: showList(movies, movieCount); break;
            case 3: filter(movies, movieCount); break;
            case 4: SearchTitle(movies, movieCount); break;
            case 5: ChangeMovie(movies, movieCount); break;
            case 6: stats(movies, movieCount); break;
            case 7: Taksinomish(movies, movieCount); break;
            case 8: saveToFile(movies, movieCount); break;
            case 9: loadFromFile(&movies, &movieCount); break;
            case 10: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 10);

    free(movies);
    return 0;
}

void clearInputBuffer(void) {
    while (getchar() != '\n');
}

void addtitle(MOVIE **movies, int *movieCount) {

    *movies = realloc(*movies, (*movieCount + 1) * sizeof(MOVIE));
    if (*movies == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    MOVIE *newMovie = &((*movies)[*movieCount]);

    newMovie->id = *movieCount + 1;

    printf("Enter movie title: ");
    fgets(newMovie->title, MAXLEN, stdin);
    newMovie->title[strcspn(newMovie->title, "\n")] = '\0';

    do{
        printf("Enter movie type (M (MOVIE) or S (SERIES)): ");
        char buffer[10];

        fgets(buffer, sizeof(buffer), stdin);
        newMovie->type = toupper(buffer[0]);
    }while(newMovie->type != 'M' && 
            newMovie->type != 'S');
    printf("Enter movie platform: ");
    fgets(newMovie->platform, MAXLEN, stdin);
    newMovie->platform[strcspn(newMovie->platform, "\n")] = '\0';
    do{
        printf("Enter movie status (W (Watching), F (Finished) or D (Dropped)): ");
        char buffer[10];

        fgets(buffer, sizeof(buffer), stdin);
        newMovie->status = toupper(buffer[0]);
    }while(newMovie->status != 'W' && 
            newMovie->status!= 'F' && 
            newMovie->status != 'D');
    do{
        printf("Enter movie rating 1-10: ");
        scanf("%d", &newMovie->rating);
        clearInputBuffer();
    }while (newMovie->rating < 1 || 
            newMovie->rating > 10);

    printf("Enter movie notes: ");
    fgets(newMovie->note, MAXLEN, stdin);
    newMovie->note[strcspn(newMovie->note, "\n")] = '\0';
    
    (*movieCount)++;
}

void showList(MOVIE *movies, int movieCount){
    if (movieCount == 0) { printf("No movies found.\n"); return; }
    printf("\n=== YOUR WATCHLIST ===\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d | %s | %c | %s | %c | %d | %s\n",
            movies[i].id,
            movies[i].title,
            movies[i].type,
            movies[i].platform,
            movies[i].status,
            movies[i].rating,
            movies[i].note);
        }
}

void filter(MOVIE *movies, int movieCount) {
    if (movieCount == 0) { 
        printf("\nNo movies in your watchlist to filter.\n"); 
        return; 
    }

    char filterChoice;
    char line[10];

    printf("\n--- Filter Menu ---\n");
    printf("T. Filter by Type (M/S)\n");
    printf("S. Filter by Status (W/F/D)\n");
    printf("R. Filter by Rating (1-10)\n");
    printf("Enter choice: ");
    
    fgets(line, sizeof(line), stdin);
    filterChoice = toupper(line[0]);

    int found = 0;

    if (filterChoice == 'T') {
        char target;
        printf("Enter Type to show (M for Movie, S for Series): ");
        fgets(line, sizeof(line), stdin);
        target = toupper(line[0]);

        printf("\n--- Results for Type: %c ---\n", target);
        for (int i = 0; i < movieCount; i++) {
            if (movies[i].type == target) {
                printf("%d. %s [%s]\n", movies[i].id, movies[i].title, movies[i].platform);
                found = 1;
            }
        }
    } 
    else if (filterChoice == 'S') {
        char target;
        printf("Enter Status to show (W: Watching, F: Finished, D: Dropped): ");
        fgets(line, sizeof(line), stdin);
        target = toupper(line[0]);

        printf("\n--- Results for Status: %c ---\n", target);
        for (int i = 0; i < movieCount; i++) {
            if (movies[i].status == target) {
                printf("%d. %s (Rating: %d/10)\n", movies[i].id, movies[i].title, movies[i].rating);
                found = 1;
            }
        }
    } 
    else if (filterChoice == 'R') {
        int targetRating;
        printf("Enter Minimum Rating (1-10): ");
        if (scanf("%d", &targetRating) == 1) {
            clearInputBuffer();
            printf("\n--- Results for Rating %d and above ---\n", targetRating);
            for (int i = 0; i < movieCount; i++) {
                if (movies[i].rating >= targetRating) {
                    printf("%d. %s - %d/10\n", movies[i].id, movies[i].title, movies[i].rating);
                    found = 1;
                }
            }
        }
    } 
    else {
        printf("Invalid filter option.\n");
        return;
    }

    if (!found) {
        printf("No matches found for your criteria.\n");
    }
}

void SearchTitle(MOVIE *movies, int movieCount) {
    if (movieCount == 0) { 
        printf("\nNo movies in your watchlist to search.\n"); 
        return; 
    }

    char searchTerm[MAXLEN];
    printf("\n--- Search Title ---\n");
    printf("Enter the movie title you are searching: ");
    
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';
    for(int i = 0; searchTerm[i]; i++) {
        searchTerm[i] = toupper(searchTerm[i]);
    }

    int found = 0;
    for(int j = 0; j < movieCount; j++) {
        char tempTitle[MAXLEN];
        strcpy(tempTitle, movies[j].title);
        for(int k = 0; tempTitle[k]; k++) tempTitle[k] = toupper(tempTitle[k]);

        if(strstr(tempTitle, searchTerm) != NULL) {
            printf("%d | %s | %c | %s | %c | %d | %s\n",
                movies[j].id, movies[j].title, movies[j].type, 
                movies[j].platform, movies[j].status, 
                movies[j].rating, movies[j].note);
            found = 1;
        }
    }

    if (!found) {
        printf("No movies found matching '%s'.\n", searchTerm);
    }
}

void ChangeMovie(MOVIE *movies, int movieCount){
    if (movieCount == 0) {
        printf("No movies to change.\n");
        return;
    }

    showList(movies, movieCount);
    
    int idInput;
    char line[10];
    char filterChoice;

    printf("\nPlease select the ID of the movie you would like to change: ");
    scanf("%d", &idInput);
    clearInputBuffer();

    int idx = idInput - 1;

    if (idx < 0 || idx >= movieCount) {
        printf("Invalid ID selection.\n");
        return;
    }

    printf("Editing: %s\n", movies[idx].title);
    printf("Please select the type of change you would like to make:\n");
    printf("N. Note\n");
    printf("S. Status (W/F/D)\n");
    printf("R. Rating (1-10)\n");
    printf("Enter choice: ");
    
    fgets(line, sizeof(line), stdin);
    filterChoice = toupper(line[0]);

    if (filterChoice == 'N') {
        printf("Enter new Note: ");
        fgets(movies[idx].note, MAXLEN, stdin);
        movies[idx].note[strcspn(movies[idx].note, "\n")] = '\0';
    } 
    else if (filterChoice == 'S') {
        do {
            printf("Enter Status (W/F/D): ");
            fgets(line, sizeof(line), stdin);
            movies[idx].status = toupper(line[0]);
        } while(movies[idx].status != 'W' && movies[idx].status != 'F' && movies[idx].status != 'D');
    } 
    else if (filterChoice == 'R') {
        do {
            printf("Enter new rating (1-10): ");
            scanf("%d", &movies[idx].rating); 
            clearInputBuffer();
        } while (movies[idx].rating < 1 || movies[idx].rating > 10);
    }
    else {
        printf("Invalid option.\n");
    }
}

void stats(MOVIE *movies, int movieCount) {
    if (movieCount == 0) {
        printf("No movies found to generate statistics.\n");
        return;
    }

    int cnt = 0;
    char line[10];
    char filterChoice;

    printf("\n--- STATS ---\n");
    printf("P. Stats by Platform\n");
    printf("S. Stats by Status Summary\n");
    printf("R. Average Rating of all movies\n");
    printf("Enter choice: ");
    
    fgets(line, sizeof(line), stdin);
    filterChoice = toupper(line[0]);

    if (filterChoice == 'S') {
        int w = 0, f = 0, d = 0;
        for (int i = 0; i < movieCount; i++) {
            if (movies[i].status == 'W') w++;
            else if (movies[i].status == 'F') f++;
            else if (movies[i].status == 'D') d++;
        }
        printf("\nSummary:\n");
        printf("- Watching: %d\n", w);
        printf("- Finished: %d\n", f);
        printf("- Dropped:  %d\n", d);
    } 
    else if (filterChoice == 'P') {
        char searchTerm[MAXLEN];
        printf("Enter the Platform to count: ");
        fgets(searchTerm, sizeof(searchTerm), stdin);
        searchTerm[strcspn(searchTerm, "\n")] = '\0';
        for(int i = 0; searchTerm[i]; i++) searchTerm[i] = toupper(searchTerm[i]);

        cnt = 0;
        for(int j = 0; j < movieCount; j++) {
            char tempPlat[MAXLEN];
            strcpy(tempPlat, movies[j].platform);
            for(int k = 0; tempPlat[k]; k++) tempPlat[k] = toupper(tempPlat[k]);

            if(strstr(tempPlat, searchTerm) != NULL) {
                cnt++;
            }
        }
        printf("The platform matching '%s' appears %d times.\n", searchTerm, cnt);
    } 
    else if (filterChoice == 'R') {
        float sum = 0;
        for (int i = 0; i < movieCount; i++) {
            sum += movies[i].rating;
        }
        printf("The average rating for all movies is: %.2f / 10\n", sum / movieCount);
    } 
    else {
        printf("Invalid option.\n");
    }
}

void Taksinomish(MOVIE *movies, int movieCount) {
    if (movieCount < 2) {
        printf("Not enough movies to sort.\n");
        return;
    }

    int choice;
    printf("\nSort by:\n");
    printf("1. Title (A-Z)\n");
    printf("2. Rating (low to high)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    clearInputBuffer();

    MOVIE temp;

    if (choice == 2) {
        for (int i = 0; i < movieCount - 1; i++) {
            for (int j = 0; j < movieCount - i - 1; j++) {
                if (movies[j].rating > movies[j + 1].rating) {
                    temp = movies[j];
                    movies[j] = movies[j + 1];
                    movies[j + 1] = temp;
                }
            }
        }
        printf("\nSorted by rating!\n");
        showList(movies, movieCount);
    }
     else if (choice == 1) {
        for (int i = 0; i < movieCount - 1; i++) {
            for (int j = 0; j < movieCount - i - 1; j++) {
                if (strcmp(movies[j].title, movies[j + 1].title) > 0) {
                    temp = movies[j];
                    movies[j] = movies[j + 1];
                    movies[j + 1] = temp;
                }
            }
        }
        printf("\nSorted by title (A-Z)!\n");
        showList(movies, movieCount);
    }
    else {
        printf("WRONG CHOICE!\n");
    }
}

void saveToFile(MOVIE *movies, int movieCount) {
    if (movieCount == 0) {
        printf("Nothing to save.\n");
        return;
    }

    FILE *fp = fopen("movies.txt", "w");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < movieCount; i++) {
        fprintf(fp, "%s|%c|%s|%c|%d|%s\n",
            movies[i].title,
            movies[i].type,
            movies[i].platform,
            movies[i].status,
            movies[i].rating,
            movies[i].note);
    }

    fclose(fp);
    printf("Movies saved successfully.\n");
}

void loadFromFile(MOVIE **movies, int *movieCount) {
    FILE *fp = fopen("movies.txt", "r");
    if (!fp) {
        printf("No saved file found.\n");
        return;
    }

    free(*movies);
    *movies = NULL;
    *movieCount = 0;

    MOVIE temp;

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%25[^|]|%c|%25[^|]|%c|%d|%25[^\n]",
            temp.title, &temp.type, temp.platform, &temp.status, &temp.rating, temp.note) == 6) {
            
            *movies = realloc(*movies, (*movieCount + 1) * sizeof(MOVIE));
            temp.id = *movieCount + 1;
            (*movies)[*movieCount] = temp;
            (*movieCount)++;
        }
    }

    fclose(fp);
    printf("Movies loaded successfully.\n");
}
