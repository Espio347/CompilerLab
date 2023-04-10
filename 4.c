#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter the input string: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';  // remove trailing newline character
    
    int length = strlen(input);
    int index = 0;
    while (index < length) {
        char c = input[index];
        
        if (c == '\\') {  // check for escape sequence
            printf("Escape Sequence\t\\%c\n", input[index+1], 2, input+index);
            index += 2;
            continue;
        }

        if (c == '/' && input[index+1] == '/') {  // check for single-line comment
            printf("Comment\t\t//%s\n", input+index+2, length-index-2, input+index);
            break;  // exit loop after comment is found
        }
        
        if (c == '/' && input[index+1] == '*') {  // check for multi-line comment
            index += 2;
            int start = index - 2;
            while (index < length-1) {
                if (input[index] == '*' && input[index+1] == '/') {
                    printf("Comment\t\t%.*s\n", index+2-start, input+start);
                    index += 2;
                    break;  // exit loop after comment is found
                }
                index++;
            }
            if (index == length-1) {
                printf("Error: Unterminated multi-line comment\n");
                break;  // exit loop after error message is printed
            }
            continue;
        }
        index++;
    }
    return 0;
}
