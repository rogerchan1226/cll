#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int cnt,
        subCnt,
        tmp,
        result=0;
    
    for(cnt=0; cnt<numsSize; cnt++){
        result++;
        for(subCnt=cnt+1; subCnt<numsSize; subCnt++){
            if(nums[cnt] != nums[subCnt]){
                break;
            }
        }
        tmp=1;
        for(; subCnt<numsSize; subCnt++){
            nums[cnt+tmp] = nums[subCnt];
            tmp++;
        }

        if(nums[cnt] >= nums[cnt+1])
            break;
    }
    
    return result;
}


void main(){
    int i;
    int numsSize = 16;
    int nums[] = {1,1,2,3,4,5,5,5,5,5,5,5,5,5,5,6};
    int len = removeDuplicates(nums, numsSize);

    for (int i = 0; i < len; i++) {
        printf("%d", nums[i]);
    }

    printf("\n");
}