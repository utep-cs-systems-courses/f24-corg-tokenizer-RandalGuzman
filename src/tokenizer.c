#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c) {
  return (c == ' ' || c == '\t');  // returns 1 if char is a space or tab
}

int non_space_char(char c) {
  return !space_char(c);  //returns 1 if the char is not a space or tab
}

char *token_start(char *str) {
  while (*str && space_char(*str)) str++;  //skips spaces
  return *str ? str : NULL;  //returns the pointer or NULL
}

char *token_terminator(char *token) {
  while (*token && non_space_char(*token)) token++;  //skips non space chars
  return token;  //returns the end of the token
}

int count_tokens(char *str) {
  int count = 0;
  char *start = token_start(str);  //gets the first token
  while (start) {
    count++;
    start = token_start(token_terminator(start));
  }
  return count;  //returns the total count
}

char *copy_str(char *inStr, short len) {
  char *copy = (char *) malloc((len + 1) * sizeof(char)); //allocates memory for the copy
  if (!copy) return NULL;  //checks for malloc failure
  for (int i = 0; i < len; i++) {
    copy[i] = inStr[i];  //copies the chars
  }
  copy[len] = '\0';  //Null terminates the new string
  return copy;
}

char **tokenizer(char *str) {
  int token_count = count_tokens(str);  //counts tokens
  char **tokens = (char **) malloc((token_count + 1) * sizeof(char *));//allocate memory for tokens
  char *start = token_start(str);  //gets the first token
  
  for (int i = 0; i < token_count; i++) {
    char *end = token_terminator(start);  //gets the end of the token
    tokens[i] = copy_str(start, end - start);  //copies the token
    start = token_start(end);  //moves to the next token
  }
  tokens[token_count] = NULL;  //Null terminates the array
  return tokens;
}

void print_tokens(char **tokens) {
  for (int i = 0; tokens[i]; i++) {
    printf("%d. %s\n", i, tokens[i]);  //prints each token
  }
}

void free_tokens(char **tokens) {
  for (int i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);  //free each token
  }
  free(tokens);  //free the array of tokens
}
