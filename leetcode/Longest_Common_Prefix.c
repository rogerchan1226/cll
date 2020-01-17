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
 *      Runtime: 0 ms
 *      Memory Usage: 7 MB
 * 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




char * longestCommonPrefix(char ** strs, int strsSize){
    int k = 1, 
        l = 0, 
        m = 0,
        n = 0;
    char ** ptr = strs;                     // set as pointer strs's initialization address
    char *lock = strs[0];

    if(strsSize < 1)                        // check if there have no input
        return "";
    else if (strsSize == 1)
        return ptr[0];
    else{
        while(k < strsSize){                    // pick up smallest strs address
            if(strlen(lock) > strlen(ptr[k]))
                n = k;
                lock = ptr[n];
            k++;
        }
        
        if(strlen(lock) == 0)                   // check if input is NULL char
            return "";

        k = 0;
        char *result = (char*)calloc(1, strlen(lock)+1);

        do{
            do{
                if(l == n){
                    l++;
                    continue;
                }

                if(lock[m] != ptr[l][m]){
                    k = 1;
                    break;
                }else{
                    result[m] = lock[m];
                    l++;
                }
            }while(l < strsSize);
            if(k != 0)
                break;
            l = 0;
            m++;
        }while(m < strlen(lock));

    result[m] = '\0';                       // reset surplus fields
    return result;
    }
    
    return ptr[0];
}

 /**
  * Question's Input & Output. 
  *     You may setup any question detail by 
  *     modify "input" value.
  **/

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

    input = temp;
    output = longestCommonPrefix(input, 3);
    
    printf("output: %s\n", output);
}
