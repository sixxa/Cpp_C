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
  char _input[256], _rest[256];

  do {
    printf("%s (1-25 char): ", prompt);
    
    fgets(_input, sizeof(_input), stdin);
    if (sscanf(_input, " %s%s", string, _rest) == 1) {
      if (strlen(string) < 25) return;
    };
  } while (1);
}

int take_int(const char *prompt, int maximum) {
  char _input[256], _rest[256];
  int value;

  do {
    printf("%s [0-%d]: ", prompt, maximum);

    fgets(_input, sizeof(_input), stdin);
    if (sscanf(_input, " %d%s", &value, _rest) == 1) {
      if (0 <= value && value <= maximum) return value;
    };
  } while (1);
}

char take_char(const char *prompt, const char *pattern){
  char _input[256], _rest[256];
  char character;

  do {
    printf("%s (%s): ", prompt, pattern);
    fgets(_input, sizeof(_input), stdin);
    if (sscanf(_input, " %c%s", &character, _rest) == 1) {
      character = toupper(character);      
      if (strchr(pattern, toupper(character)) != NULL) return character;
    };
  } while (1);
}

int validate (const char question[]) {
  char confirm;
  do {
    confirm = take_char(question, "YN");

    if (confirm == 'N') return 0;
    if (confirm == 'Y') return 1;
  } while (1);
}

