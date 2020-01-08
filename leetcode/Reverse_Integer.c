/*
 *
 *  Leetcode:
 *      Runtime: 4 ms
 *      Memory Usage: 6.9 MB
 * 
 */ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int reverse(int x){         //answer 1
    char *buf = calloc(1, 12),
         *rebuf = calloc(1, 12),
         *buftmp = buf,
         *rebuftmp = rebuf;
    long int result = 0;
    int i;
    
    sprintf(buf, "%d", x);

    for((buftmp += strlen(buf)-1); *buftmp != '\0'; buftmp--){
        if(*buftmp == '-')
            break;
        *rebuftmp = *buftmp;
        rebuftmp++;
    }

    printf("rebuf: %s\n", rebuf);
    
    i = 0;
    printf("strlen(rebuf): %ld\n", strlen(rebuf));
    rebuftmp = rebuf;
    while(*rebuftmp != '\0'){
		result *= 10;
		result += (*rebuftmp-0x30);
		rebuftmp++;
	}
    if(result > 2147483647)
        return 0;

    if(x < 0)
        result = result * (-1);

    printf("result = %ld\n", result);

    return result;
}

int integer_reverse(int x){         //answer 2
    int result = 0;
    int tmp ;
    if(x >= 0){
        while(x){
            result *= 10;
            tmp = x % 10;
            result += tmp;
            x /= 10;
        }
    }else{       
        while(x){
            result *= 10;
            tmp = x % 10;
            result += tmp*(-1);
            x /= 10;
        }
        result = result*(-1);
    }
    if(result > 2147483647 || result < -2147483647)
        return 0;

    return result;   
}

 /**
  * Question's Input & Output. 
  *     You may setup any question detail by 
  *     modify "input" value.
  **/
void main(){
    int input=-1456;
    int output;
    
    output=reverse(input);

    printf("Input: %d\n", input);
    printf("Output: %d\n", output);
}
