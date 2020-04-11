#include <stdio.h>
#include <stdlib.h>




char * countAndSay(int n){
    if(n<=0)
        return NULL;
    else if(n == 1)
        return "1";
    
    char *result,
         *tmp,
         *arr = (char*)calloc(1, 1),
         *count,
         *new;
    int i,
        cnt = 0,
        val,
        len = 1;

    *arr = '1';

    for(i=2; i<=n; i++){
        count = arr;
        result = calloc(1, 2 * len + 1);
        len = 0;
        new = result;
        val = *count;
        while(1){
            if(val == *count){
                count++;
                cnt++;
                continue;
            }
            *new++ = ('0' + cnt);
            *new++ = val;
            len += 2;
            val = *count;
            cnt = 0;

            if(!*count)
                break;
        }

        free(arr);
        arr = result;
    }
    
    
    
    return result;
}


void main(){
    int n = 10;
    char *answer;

    answer = countAndSay(n);

    printf("Answer: %s\n", answer);

    free(answer);

}