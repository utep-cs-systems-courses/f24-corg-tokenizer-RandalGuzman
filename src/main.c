#include <stdio.h>
#include "tokenizer.h"
#define BUFFER_SIZE 1024

int main() {
  char input[BUFFER_SIZE];

  printf("Enter a string to tokenize  or  'q' to quit):\n");

  while (1) {
    printf("> ");
    if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
      break;
    }

    for (int i = 0; input[i]; i++) {
      if (input[i] == '\n') {
	input[i] = '\0';
	break;
      }
    }

    if (input[0] == '\0') {
      continue;
    }

    if (strcmp(input, "q") == 0) {
      break;
    }

    char **tokens = tokenizer(input);
    print_tokens(tokens);
    free_tokens(tokens);
  }
  return 0;
}
  
