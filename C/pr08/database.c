#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "access.h"
#include "database.h"


// definitions
int p_new () {
  char name[50];

  printf("New\n");
  take_string("Name", name);
  printf("Name is %s\n", name);

  return 0;
}

int p_add () {
  int book;

  printf("Add\n");
  book = take_int("Book", 20);
  printf("Book is %d\n", book);

  return 0;
}

int p_vote () {
  printf("Vote\n");
  return 0;
};

int p_clean () {
  printf("Clean\n");
  return 0;
}

int p_init(struct Reader *tab_r, int *number) {
    int code;
    
    *number = 0;
    code = take_int("Code", 200);  
    while (code > 0) {
        tab_r[*number].code = code;
        take_string("Name", tab_r[*number].name);
        (*number)++;
        code = take_int("Code", 200);
    }
    return 0;
}

int p_show (struct Reader *tab_r, int number) {
    printf("Readers:\n");
    for (int i = 0; i < number; i++) {
        printf("%s;%d\n", tab_r[i].name, tab_r[i].code);
    }
    return 0;
}
