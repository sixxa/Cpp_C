#include <stdio.h>
#include <ctype.h>
#include <string.h>

void boundary (const char pattern);
void mark (const char value[]);
int validate (const char question[]);
int p_new ();
int p_add ();
int p_vote ();
int p_clean ();
void take_string(const char *prompt, char *string);
int take_int(const char *prompt, int maximum);
char take_char(const char *prompt, const char *pattern);

struct Reader {
    char name[50];
    int code;
};

int p_init(struct Reader *tab_r, int *number);
int p_show (struct Reader *tab_r, int number);


int main(void) {
  int exit = 0;
  struct Reader readers[100];
  int numReaders = 0;
  
  p_init(readers, &numReaders);

  boundary('#');
  mark("LIBRARY");
  boundary('#');
  do {
    boundary('-');
    printf(" N) New reader\n");
    printf(" A) Add book\n");
    printf(" V) Submit vote\n");
    printf(" C) Clean reader\n");
    printf(" S) Show readers\n");
    printf(" X) Exit\n");
    boundary('-');

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

void boundary (const char pattern) {
  for (int i = 0; i < 50; i++) {
    printf("%c", pattern);
  }
  printf("\n");
}

void mark (const char value[]) {
  printf("%s\n", value);
  return;
}

int validate (const char question[]) {
  char confirm;
  do {
    confirm = take_char(question, "YN");

    if (confirm == 'N') return 0;
    if (confirm == 'Y') return 1;
  } while (1);
}

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

void take_string(const char *prompt, char *string) {
  do {
    printf("%s (1-25 char): ", prompt);
    scanf(" %s", string);
  } while (strlen(string) > 24);

  return;
}

int take_int(const char *prompt, int maximum) {
  int value;

  do {
    printf("%s [0-%d]: ", prompt, maximum);
    scanf("%d", &value);
  } while(value < 0 || value > maximum);

  return value;
}

char take_char(const char *prompt, const char *pattern){
  char character;

  do {
    printf("%s (%s): ", prompt, pattern);
    scanf(" %c", &character);
    while (fgetc(stdin) != '\n');
  } while (strchr(pattern, toupper(character)) == NULL);
  
  return toupper(character);
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

