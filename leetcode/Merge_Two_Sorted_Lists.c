/*
 *
 *  Leetcode:
 *      Runtime: ms
 *      Memory Usage: MB
 * 
 */ 
#include <stdio.h>
#include <stdlib.h>

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


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *buffer,
                    *result;
    
    result = l1;
    buffer = l2;

    return result;
}

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