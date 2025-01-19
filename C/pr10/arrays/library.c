#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "access.h"
#include "database.h"


int main(void) {
  int exit = 0;
  struct Reader readers[100];
  struct Book books[100];
  int numReaders, numBooks;
  
  p_init(readers, &numReaders, books, &numBooks);

  boundary('-', 50);
  mark("LIBRARY");
  boundary('-', 50);
  do {
    boundary(' ', 50);
    printf(" N) New reader\n");
    printf(" A) Add book\n");
    printf(" V) Submit vote\n");
    printf(" C) Clean reader\n");
    printf(" S) Show info\n");
    printf(" X) Exit\n");
    boundary(' ', 50);

    switch(take_char("Enter operation", "NAVCSX")) {
      case 'N':
        p_new(readers, &numReaders);
        break;
      case 'A':
        p_add(books, &numBooks);
        break;
      case 'V':
        p_vote(books, &numBooks);
        break;
      case 'C':
        p_clean(readers, &numReaders);
        break;
      case 'S':
        p_show(readers, numReaders, books, numBooks);
        break;
      case 'X':
        exit = 1;
        break;
      default:
        printf("Invalid option\n");
        break;
    }
    if (exit) exit = validate("Confirm exit?");

  } while (exit == 0);

  p_fin(readers, numReaders, books, numBooks);

  return 0;
}


