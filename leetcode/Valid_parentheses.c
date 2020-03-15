/*
 *
 *  Leetcode:
 *      Runtime: 16 ms
 *      Memory Usage: 7.5 MB
 * 
 */ 


#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool isValid(char * s){
    int cnt  = 0,
        mark = 0;

    for(cnt = 0; cnt < strlen(s); cnt++){
        if(s[cnt] == 0x20)      /* 0x20 == ' ' */
            continue;
        
        if(mark == 0 && (s[cnt] == ')' || s[cnt] == ']' || s[cnt] == '}'))
            return false;
        else if((mark == 1 || mark == 2 || mark == 3) &&           /* 1 = '(', 2 = '[', 3 = '{' */
                (s[cnt] == '(' || s[cnt] == '[' || s[cnt] == '{'))
            return false;
        else if(mark == 1 && (s[cnt] == ']' || s[cnt] == '}'))
            return false;
        else if(mark == 2 && (s[cnt] == ')' || s[cnt] == '}'))
            return false;
        else if(mark == 3 && (s[cnt] == ')' || s[cnt] == ']'))
            return false;
        else if(mark == 1 && s[cnt] == ')'){
            mark =0;
            continue;
        }
        else if(mark == 2 && s[cnt] == ']'){
            mark =0;
            continue;
        }
        else if(mark == 3 && s[cnt] == '}'){
            mark =0;
            continue;
        }

        switch(s[cnt]){
            case '(':
                mark = 1;
                continue;
            case '[':
                mark = 2;
                continue;
            case '{':
                mark = 3;
                continue;
        }
    }

    return true;
}


void main(){
/*
 * 20. Valid Parentheses
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 *
 * An input string is valid if:
 *      1) Open brackets must be closed by the same type of brackets.
 *      2) Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 * 
 */
    char input[256]={"(){}[]"};
    int output;

    output = isValid(input);

    if(output)
        printf("Output = TRUE\n");
    else
        printf("Output = False\n");

}