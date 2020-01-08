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



char * defangIPaddr(char *address){
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

char *deXXXXX(char* address){
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


void main(){
    char real[8]="1.1.1.1";
    char *address;
    char *final;

    address = real;
    
    printf("Intput: %s\n", address);
    final=deXXXXX(address);

    printf("Output: %s\n", final);
}