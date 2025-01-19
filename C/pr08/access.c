#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "access.h"


// definitions
void boundary (const char pattern, const int size) {
  for (int i = 0; i < size; i++) {
    printf("%c", pattern);
  }
  printf("\n");
}

void mark (const char value[]) {
  printf("%s\n", value);
  return;
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

int validate (const char question[]) {
  char confirm;
  do {
    confirm = take_char(question, "YN");

    if (confirm == 'N') return 0;
    if (confirm == 'Y') return 1;
  } while (1);
}

