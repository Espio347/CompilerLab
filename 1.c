#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

void main()
{

    int i, ic = 0, m, cc = 0, oc = 0, pc = 0, j, kw = 0, kw_count = 0;
    char b[30], operators[30], punctuators[30],identifiers[30], constants[30], keywords[30][10];
    char keyword_list[][10] = {"int", "char", "float", "double", "if", "else", "for", "while", "do", "switch", "case", "break", "continue", "return"};

    printf("Enter the Expression: ");
    scanf("%[^\n]s", &b);

    for(i = 0; i < strlen(b); i++){

        if(isspace(b[i])){
            continue;
        }
        else if(isalpha(b[i]))
        {
            char token[10];
            int k = 0;
            token[k++] = b[i];
            i++;
            while(isalpha(b[i]) || isdigit(b[i])){
                token[k++] = b[i];
                i++;
            }
            token[k] = '\0';

            // check if token is a keyword
            for(int kw_index = 0; kw_index < 14; kw_index++){
                if(strcmp(token, keyword_list[kw_index]) == 0){
                    kw = 1;
                    strcpy(keywords[kw_count], token); // store the keyword in the array
                    kw_count++;
                    break;
                }
            }

            if(kw == 0){
                identifiers[ic] = b[i-k];
                ic++;
            }
            else{
                kw = 0;
            }
            i--;
        }
        else if(isdigit(b[i]))
        {
            m = (b[i] - '0');
            i++;
            while(isdigit(b[i])){
                m = m * 10 + (b[i] - '0');
                i++;
            }
            i--;
            constants[cc] = m;
            cc++;
        }
        else if(b[i] == '*' || b[i] == '-' || b[i] == '+' || b[i] == '=')
            {
                operators[oc] = b[i];
                oc++;
            }
            //punctuators
        else {
            if (b[i] == '[' || b[i] == ']' || b[i] == '(' || b[i] == ')' || b[i] == '{' || b[i] == '}' ||
                b[i] == '!' || b[i] == ';' || b[i] == '|' || b[i] == '&' || b[i] == ',')
            {
                punctuators[pc] = b[i];
                pc++;
            }
        }
    }

    // printing
    printf("\nidentifiers: ");
    for(j = 0; j < ic; j++){
        printf("%c ", identifiers[j]);
    }
    printf("\nconstants: ");
    for(j = 0; j < cc; j++){
        printf("%d ", constants[j]);
    }
    printf("\noperators: ");
    for(j = 0; j < oc; j++){
        printf("%c ", operators[j]);
    }
    printf("\npunctuators: ");
    for(j = 0; j < pc; j++){
        printf("%c ", punctuators[j]);
    }
    printf("\nkeywords: ");
    for(j = 0; j < kw_count; j++){
        printf("%s ", keywords[j]);
    }
    printf("\n"); 
}
