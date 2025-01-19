#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "access.h"
#include "database.h"


// definitions
int p_new (struct Reader *tab_r, int *n_r) {
  char name[50];

  printf("New\n");
  take_string("Name", name);
  
  if (*n_r > 0) {
    tab_r[*n_r].code = tab_r[*n_r - 1].code + 1;
  } else {
    tab_r[*n_r].code = 1;
  }
  strcpy(tab_r[*n_r].name, name);

  printf("\nReader: %s;%d\n", tab_r[*n_r].name, tab_r[*n_r].code);
  (*n_r)++;

  return 0;
}

int p_add (struct Book *tab_b, int *n_b) {
  char author[26], title[26];

  printf("Add\n");
  take_string("Author", author);
  take_string("Title", title);
  
  strcpy(tab_b[*n_b].author, author);
  strcpy(tab_b[*n_b].title, title);
  tab_b[*n_b].votes = 0;
  tab_b[*n_b].points = 0;
  if (*n_b > 0) {
    tab_b[*n_b].signature = tab_b[*n_b - 1].signature + 1;
  } else {
    tab_b[*n_b].signature = 1;
  }

  printf("\nBook: %s;%s;%d\n", tab_b[*n_b].author, tab_b[*n_b].title, tab_b[*n_b].signature);
  (*n_b)++;

  return 0;
}

int p_vote (struct Book *tab_b, int *n_b) {
  int book_index, book_points;

  printf("Vote\n");
  
  if ((*n_b) == 0) {
    printf("\nNo books yet\n");
    return 0;
  }
  
  book_index = take_int("Book", *n_b) - 1;
  book_points = take_int("Points", 10);

  tab_b[book_index].votes ++;
  tab_b[book_index].points += book_points;
  printf("Registered vote\n");

  return 0;
};

int p_clean (struct Reader *tab_r, int *n_r) {
  printf("Clean\n");

  if (*n_r == 0) {
    printf("\nNo readers yet\n");
    return 0;
  }

  char name[26];
  take_string("Name", name);
  
  int index = -1;
  
  for (int i = 0; i < *n_r; i++) {
    if (strcmp(tab_r[i].name, name) == 0) {
       index = i;
       break;
    }
  }
  
  if (index == -1) {
    printf("\nUnknown reader\n");
    return 0;
  }
  
  for (int i = index + 1; i < *n_r; i++) {  
    tab_r[i - 1] = tab_r[i];
    strcpy(tab_r[i].name, tab_r[i - 1].name);
  }

  (*n_r)--;
  printf("\nCleaned reader\n");
  return 0;
}

int p_init(struct Reader *tab_r, int *n_r, struct Book *tab_b, int *n_b) {
    FILE *file;
    char name[26], author[26], title[26];
    int code, votes, points, signature;
    char line [256];
    
    *n_r = 0;
    *n_b = 0;
    
    file = fopen("readers.txt", "r");
    if (file != NULL) {
        while (fgets(line, sizeof(line), file)) {
            sscanf(line, " %s%d%s", name, &code, line);
            tab_r[*n_r].code = code;
            strcpy(tab_r[*n_r].name, name);
            (*n_r)++;
        }
        fclose(file);
    }

    file = fopen("books.txt", "r");
    if (file != NULL) {
        while (fgets(line, sizeof(line), file)) {
            sscanf(line, " %d%s%s%d%d%s", &signature, author, title, &votes, &points, line);
            tab_b[*n_b].signature = signature;
            strcpy(tab_b[*n_b].author, author);
            strcpy(tab_b[*n_b].title, title);
            tab_b[*n_b].votes = votes;
            tab_b[*n_b].points = points;
            (*n_b)++;
        }
        fclose(file);
    }
    
    return 0;
}

int p_show (struct Reader *tab_r, int n_r, struct Book *tab_b, int n_b) {
    printf("Show\n");

    printf("\nReaders:\n");
    for (int i = 0; i < n_r; i++) {
        printf("%s;%d\n", tab_r[i].name, tab_r[i].code);
    }

    printf("\nBooks:\n");
    for (int i = 0; i < n_b; i++) {
        printf("%d;%s;%s;%d;%d\n", tab_b[i].signature, tab_b[i].author, tab_b[i].title, tab_b[i].votes, tab_b[i].points);
    }
    return 0;
}

int p_fin (struct Reader *tab_r, int n_r, struct Book *tab_b, int n_b) {
    FILE *readers_out_file = fopen("readers.txt", "w");
    FILE *books_out_file = fopen("books.txt", "w");

    for (int i = 0; i < n_r; i++) {
        fprintf(readers_out_file, "%s %d\n", tab_r[i].name, tab_r[i].code);
    }

    for (int i = 0; i < n_b; i++) {
        fprintf(books_out_file, "%d %s %s %d %d\n", tab_b[i].signature, tab_b[i].author, tab_b[i].title, tab_b[i].votes, tab_b[i].points);
    }

    fclose(readers_out_file);
    fclose(books_out_file);

    return 0;
}
