/*
 *
 *  Leetcode:
 *      Runtime: 0 ms
 *      Memory Usage: 5.6 MB
 * 
 */ 



#include <stdio.h>




int strStr(char * haystack, char * needle){
    if(! *needle)
        return 0;

    char *hst,
         *hs  = haystack,
         *nd  = needle;
    int cnt    = 0,
        result = 0;
    
    while(*hs){
        if(*hs != *nd){
            hs++;
            cnt++;
            continue;
        }else{
            result = cnt;
            hst = hs;
            cnt++;
            hs++; nd++;
            while(*nd && *hs){
                if(*hs != *nd){
                    nd = needle; hs = hst+1;
                    break;
                }else{
                    hs++; nd++;
                }
            }
            
            if(! *nd)
                return result;
        }
    }
    return -1;
}

void main(){
    char input[] = {"a"},
         inputNeedle[] = {"a"};    
    int  output;

    output = strStr(input, inputNeedle);

    printf("output = %d.\n", output);

}
