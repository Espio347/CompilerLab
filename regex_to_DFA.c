#include <stdio.h>
#include <stdbool.h>

bool matchesPattern(char* str) {
    int state = 0;
    int i = 0;

    // Check if the string starts with 'a'
    if (str[0] != 'a') {
        return false;
    }
 
    // Process the remaining characters in the string
    while (str[i] != '\0') {
        if (state == 0 && str[i] == 'a') {
            state = 1;
            printf("State 0, Input 'a' -> State 1\n");
        } else if (state == 1 && str[i] == 'b') {
            state = 2;
            printf("State 1, Input 'b' -> State 2\n");
        } else if (state == 2 && str[i] == 'a') {
            state = 1;
            printf("State 2, Input 'a' -> State 1\n");
        } else if (state == 2 && str[i] == 'b') {
            state = 2;
            printf("State 2, Input 'b' -> State 2\n");
        } else {
            return false;
        }
        i++;
    }

    // Check if the final state is reached
    if (state == 1 || state == 2) {
        printf("Final State Reached with no Errors.\n");
        return true;
    } else {
        printf("Error! No path with current symbol to Final State.\n");
        return false;
    }

while (str[i] != '\0') {
        if (state == 0 && str[i] == 'a') {
            state = 1;
        } else if (state == 1 && str[i] == 'b') {
            state = 2;
        } else if (state == 2 && str[i] == 'a') {
            state = 1;
        } else if (state == 2 && str[i] == 'b') {
            state = 2;
        } else {
            return false;
        }
        i++;
    }

    // Check if the final state is reached
    if (state == 1 || state == 2) {
        return true;
    } else {
        return false;
    }

}

int main() {
    char str[] = "aab";
    if (matchesPattern(str)) {
        printf("The String is Accepted for the Regular Expression a(ab)+.\n");
    } else {
        printf("The string does not follow the Regular Expression a(ab)+ hence not Accepted.\n");
    }
    return 0;
}

