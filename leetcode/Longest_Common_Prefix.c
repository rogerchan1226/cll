/*
 *  Question:
 *      Write a function to find the longest common prefix string amongst an array of strings.
 *      If there is no common prefix, return an empty string "".
 *          Example 1:
 *              Input: ["flower","flow","flight"]
 *              Output: "fl"
 *          Example 2:
 *              Input: ["dog","racecar","car"]
 *              Output: ""
 *              Explanation: There is no common prefix among the input strings.
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
    int k = 1, l = 0, m = 0;
    char ** ptr = strs;                     // set as pointer strs's initialization address
    char *lock = strs[0];

    if(strsSize < 1)
        return "";

    while(k < strsSize){                    // pick up smallest strs address
        if(strlen(lock) > strlen(ptr[k]))
            lock = strs[k];
        k++;
    }
    
    if(strlen(lock) == 0)
        return "";

    k = strlen(lock);                       // set k as smallest strs's string length

    char *result = (char*)malloc(1*strlen(lock)+1);

    do{                                     // compare and set the same field of strs[l] & strs[l+1] as result
        if(ptr[l][m] != ptr[l+1][m])
            break;
        else{
            result[m] = ptr[l][m];
            m++;
        }
            
    }while(m < k);

    k = m;                                  // set k as result string length
    l = l+2;

    while(strsSize - l){
        for(m = 0; m < k; m++){             // compare and set the same field of result & strs[l+2] as new result
            if(result[m] != ptr[l][m])
                break;
            else
                result[m] = ptr[l][m];
        }

        l++;
    }

    result[m] = '\0';                       // reset surplus fields
    
    return result;
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
    *input = "a";
    *input++;
    *input = "b";
    *input++;
    *input = "c";

    input = temp;
    printf("input: %s, %s, %s\n", input[0], input[1], input[2]);

    input = temp;
    output = longestCommonPrefix(input, 3);
    
    printf("output: %s\n", output);
    freeAllMemory();
}
