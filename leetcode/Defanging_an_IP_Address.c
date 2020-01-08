/*
 *
 *  Leetcode:
 *      Runtime: 0 ms
 *      Memory Usage: 6.7 MB
 * 
 */ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char * defangIPaddr(char *address){         // answer 1
    char *array = calloc(1, strlen(address) +6 +1);
    int i, j;
    
    for((i=0, j=0); i<=strlen(address); (i++, j++)){
        if(address[i] == '.'){
            array[j] = '[';
            array[j+1] = '.';
            array[j+2] = ']';
            j=j+2;
        }else array[j] = address[i];
    }
    return array;
}

char * defangIPaddr2(char* address){         // answer 2
    char *array1 =(char *) calloc(1,16+6);
    char *tmp =array1;
        
    while(*address != '\0'){
        if(*address != '.' ){
            *tmp=*address;
            address++;
            tmp++;
        }else{
            *tmp='[', tmp++;
            *tmp=*address, tmp++, address++;
            *tmp=']',tmp++;
        }
    }    
    return array1;
}

 /**
  * Question's Input & Output. 
  *     You may setup any question detail by 
  *     modify "input" value.
  **/
void main(){
    char input[8]="1.1.1.1";
    char *address;
    char *output;

    address = input;
    
    printf("Intput: %s\n", address);
    output=defangIPaddr2(address);

    printf("Output: %s\n", output);
}