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
    struct ListNode *l1,        /* l1 input struct */
                    *l2,        /* l2 input struct */
                    *buffer,
                    *output;

//========== l1 linklist setting ===================================
    l1 = (struct ListNode*)calloc(1, sizeof(struct ListNode));

    l1->val = 1;
    buffer = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    l1->next = buffer;
    l1 = buffer;

    buffer = l1->next;
    buffer = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    l1->val = 2;
    l1 = buffer;

    buffer = l1->next;
    buffer = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    l1->val = 4;
    
//========== l2 linklist setting ===================================
    l2 = (struct ListNode*)calloc(1, sizeof(struct ListNode));

    l2->val = 1;
    buffer = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    l2->next = buffer;
    l2 = buffer;

    buffer = l2->next;
    buffer = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    l2->val = 3;
    l2 = buffer;

    buffer = l2->next;
    buffer = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    l2->val = 4;

    output = mergeTwoLists(l1, l2);
}