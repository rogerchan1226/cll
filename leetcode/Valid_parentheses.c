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


bool isValid(char *s) {

    char *q=s;
    
    for (char *p=s; *p; p++) 
        switch(*p) {
            case '(': *q++ = ')'; continue;
            case '{': *q++ = '}'; continue;
            case '[': *q++ = ']'; continue;
            default: if (q==s || *p != *--q) return false;
        }
    
    return q==s;
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
    char input[256]={"(()())"};
    int output;

    output = isValid(input);

    if(output)
        printf("Output = TRUE\n");
    else
        printf("Output = FALSE\n");

}