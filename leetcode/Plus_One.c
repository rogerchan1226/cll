#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *tmp = digits,
        *result,
        i = 0;

    tmp += (digitsSize-1);
    if(++*tmp % 10 == 0){
        *tmp = 0;
        while(tmp != digits){
            tmp--;
            if(*tmp && ++*tmp % 10 == 0){
                *tmp = 0;
                continue;
            }else 
                break;
        }
        if(*tmp == 0){ 
            result = (int*)malloc(sizeof(int) * (digitsSize + 1));
            tmp = result;
            *returnSize = digitsSize + 1;
            *(tmp++) = 1;
            while(i != digitsSize){
                *tmp = *digits;
                tmp++; digits++; i++;
            }
            return result;
        }
    }
    
    result = (int*)malloc(sizeof(int) * (digitsSize));
    tmp = result;
    *returnSize = digitsSize;
    while(i != digitsSize){
        *tmp = *digits;
        tmp++; digits++; i++;
    }

    return result;
}

void main(){
    int input[]={1},
        inputSize = sizeof(input)/sizeof(int),
        *output,
        *tmp;

    output = plusOne(input, inputSize, output);
    tmp = output;

    printf("output = ");
    while(1){
        printf("%d", *output);
        if(*(++output) >= 0){
            printf(",");
        }else{
            printf("\n");
            break;
        }
    }

    free(tmp);
}