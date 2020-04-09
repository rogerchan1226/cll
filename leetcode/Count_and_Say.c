#include <stdio.h>
#include <stdlib.h>




char * countAndSay(int n){
    if(n<=0)
        return NULL;
    else if(n == 1)
        return "1";
    
    char *result,           // return pointer
         *count,
         *new,
          buffer[]={1,1},
          resultBuf[]={0};
    int i,
        cnt = 0,
        val;
    
    count = buffer;
    new   = resultBuf;
    for(i=2; i<=n; i++){
        val = *count;
        while(*count){
            if(*count == val){
                count++;
                cnt++;
                continue;
            }
            break;
        }
        
        *new = cnt;
        new++;
        *new = val;
        new++;
    }
    
    result = (char*)calloc(1, sizeof(resultBuf));
    result = resultBuf;
    return result;
}


void main(){
    int n = 2;
    char *answer;

    answer = countAndSay(n);

    printf("%s\n", answer);

    free(answer);

}