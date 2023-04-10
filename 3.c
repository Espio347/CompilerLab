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
      printf("Open Parenthesis\t%c\n", c);
      index++;
      continue;
    }
    if (c == ')') {
      printf("Close Parenthesis\t%c\n", c);
      index++;
      continue;
    }
    if (c == '+') {
      printf("Addition Operator\t%c\n", c);
      index++;
      continue;
    }
    if (c == '-') {
      printf("Subtraction Operator\t%c\n", c);
      index++;
      continue;
    }
    if (c == '*') {
      printf("Multiplication Operator\t%c\n", c);
      index++;
      continue;
    }
    if (c == '/') {
      printf("Division Operator\t%c\n", c);
      index++;
      continue;
    }
    if (c == ';') {
      printf("Semicolon\t%c\n", c);
      index++;
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
      printf("Number\t\t\t%s\n", token);
      continue;
    }
    printf("Invalid Token\n");
    index++;
  }

  return 0;
}
