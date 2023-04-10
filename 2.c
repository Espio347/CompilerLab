#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
  char input[100], c;
  printf("Enter the Input String: ");
  scanf("%[^\n]s", input);

  int length = strlen(input);
  int index = 0;
  while (index < length) {
    c = input[index];
    if (isspace(c)) {
      index++;
      continue;
    }
    if (c == '(') {
      printf("Opening Parenthesis\t%c\n", c);
      index++;
      continue;
    }
    if (c == ')') {
      printf("Closing Parenthesis\t%c\n", c);
      index++;
      continue;
    }
    if (c == ';') {
      printf("Semicolon\t\t%c\n", c);
      index++;
      continue;
    }
    if (c == '>' || c == '<' || c == '=' || c == '!') {
      char token[10];
      int tlen = 0;
      token[tlen++] = c;
      index++;
      c = input[index];
      if (c == '=') {
        token[tlen++] = c;
      }
      token[tlen] = '\0';
      printf("Relational Operator\t%s\n", token);
      index++;
      continue;
    }
    if (isalpha(c)) {
      char token[50];
      int tlen = 0;
      while (isalnum(c) || c == '_') {
        token[tlen++] = c;
        index++;
        c = input[index];
      }
      token[tlen] = '\0';
      if (strcmp(token, "if") == 0) {
        printf("Keyword\t\tif\n");
      }
      else {
        printf("Identifier\t\t%s\n", token);
      }
      continue;
    }
    if (isdigit(c)) {
      char token[10];
      int tlen = 0;
      while (isdigit(c)) {
        token[tlen++] = c;
        index++;
        c = input[index];
      }
      token[tlen] = '\0';
      printf("Literal\t\t\t%s\n", token);
      continue;
    }
    index++;
  }
  return 0;
}
