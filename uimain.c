#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"


int main() {

  char input[100]; // Buffer to store user input



  // Prompt the user to enter a string

  printf("Enter a string to tokenize: ");

  fgets(input, sizeof(input), stdin); // Read input from user

  input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character



  // Tokenize the string
  char **tokens = tokenize(input);



  // Print original string

  printf("\nInput string: %s\n", input);



  // Print the tokens

  printf("Tokens:\n");

  for (int i = 0; tokens[i] != NULL; i++) {

    printf("%s\n", tokens[i]);

  }



  // Free memory
  free_tokens(tokens);



  return 0;

}
