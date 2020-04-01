/*
 *
 *  Leetcode:
 *      Runtime: ms
 *      Memory Usage: MB
 * 
 */ 
#include <stdio.h>
#include <stdlib.h>

#define ANSWER 1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    struct ListNode *next;
};
#if ANSWER

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

#else 
void listValueCompare(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *buffer;

    if(l1->val > l2->val){
        buffer = l1;
        l1 = l2; 
        l2 = buffer;
    }
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *bufferL1,
                    *bufferL2,
                    *result;

    if(!l1)
        return l2;
    else if(!l2)
        return l1;

    listValueCompare(&l1, &l2);
    result = l1;

    do{
        bufferL1 = l1->next;
        bufferL2 = l2->next;
        if(bufferL1 && bufferL2){
            listValueCompare(&l1, &l2);
            l1->next = l2;
            l2->next = bufferL1;
            l1 = bufferL1;
            l2 = bufferL2;
        }else if(!bufferL1){
            listValueCompare(&l1, &l2);
            l1->next = l2;
            break;
        }else if(!bufferL2){
            listValueCompare(&l1, &l2);
            l1->next = l2;
            l2->next = bufferL1;
            break;
        }
    }while(bufferL1 || bufferL2);


    return result;
}

#endif

void freeLinkList(struct ListNode* linklist){
    struct ListNode* buffer;

    while(1){
        buffer = linklist;
        linklist = linklist->next;
        free(buffer);
        if(linklist){
            continue;
        }
        break;
    }
}

void showResult(struct ListNode* output){

    while(1){
        printf("%d", output->val);
        if(output->next){
            output = output->next;
            printf("->");
            continue;
        }
        printf("\n");
        break;
    }
}

void main(){
/**
 * Merge two sorted linked lists and return it as a new list. The new 
 * list should be made by splicing together the nodes of the first two 
 * lists.
 * 
 * Example:
 *      Input:  1->2->4, 1->3->4
 *      Output: 1->1->2->3->4->4
 */
    int cnt,
        nums;
    /* You can modify input value from below int array. */
    int input1[] ={1,2,4},
        input2[] ={1,3,4}; 
    struct ListNode *l1,
                    *l1o,       /* List 1 origin pointer */       
                    *l2,
                    *l2o,       /* List 2 origin pointer */
                    *buffer,
                    *output;

//========== l1 linklist setting ===================================
    l1 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    l1o = l1;
    nums = sizeof(input1)/sizeof(int);

    for(cnt=0; cnt<nums; cnt++){
        l1->val=input1[cnt];
        if((cnt+1) == nums){
            l1->next = NULL;
            break;
        }
        buffer = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        l1->next = buffer;
        l1 = l1->next;
    }

//========== l2 linklist setting ===================================
    l2 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    l2o = l2;
    nums = sizeof(input2)/sizeof(int);

    for(cnt=0; cnt<nums; cnt++){
        l2->val=input2[cnt];
        if((cnt+1) == nums){
            l2->next = NULL;
            break;
        }
        buffer = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        l2->next = buffer;
        l2 = l2->next;
    }

    output = mergeTwoLists(l1o, l2o);
    
    showResult(output);     /* Show answer */

    freeLinkList(l1o);
    freeLinkList(l2o);
    freeLinkList(output);
}