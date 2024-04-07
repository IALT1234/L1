#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdio.h>
#include <stdlib.h>




/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */

int space_char(char c){
  if(c=' '){
    return 1;
  }
  return 0;
}



/* Return true (non-zero) if c is a non-whitespace 

   character (not tab or space).  

   Zero terminators are not printable (therefore false) */

int non_space_char(char c){
  if(c=' '){
    return 0;
  }
  return 1;

}


/* Returns a pointer to the first character of the next 

   space-separated token in zero-terminated str.  Return a zero pointer if 

   str does not contain any tokens. */

char *token_start(char *str){

  while(space_char(*str))

    str++;

  if (*str == '\0') {

    return NULL;

  }
  return str; 

}

/* Returns a pointer terminator char following *token */

char *token_terminator(char *token){
  if(*token=='\0'){
    return 0;
  }
  while(*token!='\0'){
    *token++;
  }
  return token;
}


/* Counts the number of tokens in the string argument. */

int count_tokens(char *str){
  if(*str=='\0'){
    return 0;
  }
  int count = 0;
  while(*str!='\0'){
    *str++;
    count++;
  }
  return count;
}


/* Returns a fresly allocated new zero-terminated string 

   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len){
  char *new_Str = (char *)malloc(len * sizeof(char));

  for(short i = 0; i<len;i++){
    new_Str[i]=inStr[i];
  }
  return new_Str;
}



/* Returns a freshly allocated zero-terminated vector of freshly allocated 

   space-separated tokens from zero-terminated str.



   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string" 

     tokens[3] = 0

*/

char **tokenize(char* str){
  int count = count_tokens(str);
  char **string = malloc((count+1) * sizeof(char *));
  if(string==NULL){
    exit(EXIT_FAILURE);
  }
  char *token_start_ptr = token_start(str);

  for(int i = 0; i<count; i++){
    char *token_end_ptr = token_terminator(token_start_ptr);
    int token_len = token_end_ptr - token_start_ptr;
    string[i] = copy_str(token_start_ptr, token_len);
    token_start_ptr = token_start(token_end_ptr);
  }

  return string;
}



/* Prints all tokens. */

void print_tokens(char **tokens){
  for(int i = 0; tokens[i]!=NULL; i++){
    printf("%s\n", tokens[i]);
  }
}


/* Frees all tokens and the vector containing themx. */

void free_tokens(char  **tokens){
   for(int i = 0; tokens[i]!=NULL;i++){
     free(tokens[i]);
   }
   free(tokens);
}

#endif
