#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main() {
  List *history = init_history();  //initialize history linked lsit
  char input[256];  //buffer size to store user input
  char *token;  //pointer to store tokens

  printf("Enter a string or type 'q' to quit): ");

  while(1) {
    printf("> ");
    fgets(input, sizeof(input), stdin);  //gets user input

    for (int i = 0; i < sizeof(input); i++) {  //removes the newline char if there
      if (input[i] == '\n') {
	input[i] = '\0';  //replaces newline with null terminator
	break;
      }
    }

    if (input[0] == '!' && input[1] >= '1' && input[1] <= '9') {  //checks if input is in history
      int id = input[1] - '0';  //convertsthe second char to int
      char *history_input = get_history(history, id);  //retrieves history item

      if (history_input) {
	printf("%s\n", history_input);
	token = tokenizer(history_input);  //tokenize the recalled input
	print_tokens(token);  //prints the tokens
	free_tokens(token);  //free the tokens
      } else {
	printf("No history item found with id %d. \n", id);
      }
      continue;
    }

    //copies the input string to add to history
    char *input_copy = (char *)malloc((strlen(input) + 1) * sizeof(char));
    strcpy(input_copy, input);  //copies the string
    add_history(history, input_copy);  //adds the copy to history

    token = tokenizer(input);  //tokenize the input
    print_tokens(token);  //printsthe tokens
    free_tokens(token);  //free the tokens

    if (strcmp(input, "q")  == 0) {  //if "q" then break the loop
      break;
    }
  }
  print_history(history);  //prints the entire history
  free_history(history);  //free the history list
  return 0;
}
