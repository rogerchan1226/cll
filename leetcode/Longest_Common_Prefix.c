/*
 *
 *  Leetcode:
 *      Runtime:  ms
 *      Memory Usage:  MB
 * 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




char * longestCommonPrefix(char ** strs, int strsSize){
    int k = 0, l = 0;
    char ** ptr = strs;     // set as pointer strs's initialization address
    char *lock = NULL;
    char result;

    while(k < strsSize){    // pick up smallest strs address
        if(lock == NULL){
            if(strlen(strs[k]) <= strlen(strs[k+1]))
                lock = strs[k];
        }else{
            if(strlen(lock) >= strlen(strs[k]))
                lock = strs[k];
        }
        k++;
    }
    k = strlen(lock) -1;

    while(l <= k){
        do{
            if(*strs[l] != *strs[l+1])
                break;
            else{
                while()
            }
                
        }while(l < strsSize);
    }
    
    return ;
}

 /**
  * Question's Input & Output. 
  *     You may setup any question detail by 
  *     modify "input" value.
  **/
void freeAllMemory(){
    
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
    printf("input: %s, %s, %s\n", input[0], input[1], input[2]);

    output = longestCommonPrefix(input, 3);
    
    printf("output: %s\n", output);
    freeAllMemory();
}
