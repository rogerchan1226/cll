/*
 *
 *  Leetcode:
 *      Runtime: 12 ms
 *      Memory Usage: 9.1 MB
 * 
 */ 

#include <stdio.h>
#include <stdlib.h>




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct node {
    int val;
    int index;
    struct node* next;
};

void freeHashTable(struct node ** hashTable, int numsSize){
    int k = 0;
    struct node *temp = NULL,
                *delete = NULL;
    
    for(k=0; k<numsSize; k++){
        temp = hashTable[k];
        delete = temp;
        while(temp){
            delete = temp;
            temp = temp->next;
            free(delete);
        }
    }
    free(hashTable);
}

void insert(struct node** hashTable, int val, int index, int numsSize){
    int j = abs(val) % numsSize;
    struct node* temp = hashTable[j];
    struct node* add = (struct node*)malloc(sizeof(struct node));

    add->val = val;
    add->index = index;
    add->next = temp->next;
    temp->next = add;
}

int search(struct node** hashTable, int target, int numsSize){
    int index = abs(target) % numsSize;
    struct node* temp = hashTable[index]->next;
    while(temp){
        if(temp->val == target)
            return temp->index;
        
        temp = temp->next;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i=0,
        index=0,
        *result;
    struct node** hashTable = (struct node**)malloc(numsSize * sizeof(struct node*));

    for(i=0; i<numsSize; i++)
        hashTable[i] = (struct node*)calloc(1, sizeof(struct node));
    for(i=0; i<numsSize; i++){
        index = search(hashTable, target - nums[i], numsSize);
        if (index == -1)
            insert(hashTable, nums[i], i, numsSize);
        else{
            result = (int *)malloc(sizeof(int) * 2);
            result[0] = index;
            result[1] = i;

            freeHashTable(hashTable, numsSize);
            *returnSize=2;
            return result;
        }
    }
    freeHashTable(hashTable, numsSize);
    *returnSize=0;
    return result;
}

 /**
  * Question's Input & Output. 
  *     You may setup any question detail by 
  *     modify "input" value.
  **/
int main(void){
    int *output = (int*)calloc(1, 3);
    int input[7] = {7,1,3,4,5,6};
    int *tmp = (int*)calloc(1, 1);

    output = twoSum(input, 6, 4, tmp);

    printf("output: [%d,%d]\n", output[0], output[1]);
}