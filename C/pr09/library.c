#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "access.h"
#include "database.h"


int main(void) {
  int exit = 0;
  struct Reader readers[100];
  int numReaders = 0;
  
  p_init(readers, &numReaders);

  boundary('#', 50);
  mark("LIBRARY");
  boundary('#', 50);
  do {
    boundary('-', 50);
    printf(" N) New reader\n");
    printf(" A) Add book\n");
    printf(" V) Submit vote\n");
    printf(" C) Clean reader\n");
    printf(" S) Show readers\n");
    printf(" X) Exit\n");
    boundary('-', 50);

    switch(take_char("Enter operation", "NAVCSX")) {
      case 'N':
        p_new();
        break;
      case 'A':
        p_add();
        break;
      case 'V':
        p_vote();
        break;
      case 'C':
        p_clean();
        break;
      case 'S':
        p_show(readers, numReaders);
        break;
      case 'X':
        exit = 1;
        break;
      default:
        printf("Invalid option\n");
        break;
    }
    if (exit) exit = validate("Confirm Exit");

  } while (exit == 0);

  return 0;
}


