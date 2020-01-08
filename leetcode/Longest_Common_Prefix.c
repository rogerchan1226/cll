/*
 *
 *  Leetcode:
 *      Runtime:  ms
 *      Memory Usage:  MB
 * 
 */ 

#include <stdio.h>
#include <stdlib.h>




char * longestCommonPrefix(char ** strs, int strsSize){
    
    return ;
}

void main(void){
    int i,
        j=2;
    char ** input = (char **)malloc(j * 7);
    char ** temp = input;
    char *output = (char*)calloc(1, 7);

    for(i=0; i<=2; i++){
        *input = (char *)calloc(1, 7);
        *input++;
    }
    
    input = temp;
    *input = "flower";
    *input++;
    *input = "flow";
    *input++;
    *input = "flight";

    input = temp;
    printf("input: %s\n", input[0]);

    output = longestCommonPrefix(input, 3);
    
    printf("output: %s\n", output);
}
