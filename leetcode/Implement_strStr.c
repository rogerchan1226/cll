#include <stdio.h>
#include <string.h>




int strStr(char * haystack, char * needle){
    if(! *needle)
        return 0;

    char *hst,
         *hs  = haystack,
         *nd  = needle;
    int cnt = 0;
    
    while(*hs){
        if(*hs != *nd){
            hs++;
            continue;
        }else{
            hst = hs;
            cnt++;
            hs++; nd++;
            while(*nd && *hs){
                if(*hs != *nd){
                    nd = needle; hs = hst;
                    cnt = 0;
                    break;
                }else{
                    cnt++;
                    hs++; nd++;
                }
            }
            
            if(cnt == strlen(needle))
                return cnt;
        }
    }
    return -1;
}

void main(){
    char input[] = {"a"},
         inputNeedle[] = {"a"};    
    int  output;

    output = strStr(input, inputNeedle);

    if(output == 0){
        printf("output = %d, Needle NULL.\n", output);
    }else if(output == -1){
        printf("output = %d, There has no string match.\n", output);
    }else{
        printf("output = %d, String match return SUCCESS.\n", output);
    }

}
