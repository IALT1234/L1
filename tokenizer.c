#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdio.h>
#include <stdlib.h>



int space_char(char c){

  if(c == ' '){

    return 1;

  }

  return 0;

}

int non_space_char(char c){

  if(c != ' '){

    return 1;

  }
  return 0;

}
char *token_start(char *str){

  while(space_char(*str))
    str++;
  if (*str == '\0') {
    return NULL;
  }

  return str;
}
char *token_terminator(char *token){

  if(*token == '\0'){
    return NULL;
  }
  while(*token != '\0'){
    token++;
  }
  return token;

}



int count_tokens(char *str){

  if(*str == '\0'){

    return 0;
  }
  int count = 0;

  while(*str != '\0'){
    str++;
    count++;
  }

  return count;

}
char *copy_str(char *inStr, short len){

  char *new_Str = (char *)malloc((len + 1) * sizeof(char));

  if (new_Str == NULL) {

    exit(EXIT_FAILURE);

  }

  for(short i = 0; i < len; i++){

    new_Str[i] = inStr[i];

  }

  new_Str[len] = '\0';

  return new_Str;

}

char **tokenize(char* str){

  int count = count_tokens(str);

  char **string = malloc((count + 1) * sizeof(char *));

  if(string == NULL){

    exit(EXIT_FAILURE);

  }

  char *token_start_ptr = token_start(str);

  for(int i = 0; token_start_ptr != NULL; i++){

    char *token_end_ptr = token_terminator(token_start_ptr);
    int token_len = token_end_ptr - token_start_ptr;
    string[i] = copy_str(token_start_ptr, token_len);
    token_start_ptr = token_start(token_end_ptr);

  }

  return string;

}

void print_tokens(char **tokens){

  for(int i = 0; tokens[i] != NULL; i++){
    printf("%s\n", tokens[i]); // Print token followed by a newline
  }
}

void free_tokens(char  **tokens){

  for(int i = 0; tokens[i] != NULL; i++){
    free(tokens[i]);
  }
  free(tokens);

}
#endif
