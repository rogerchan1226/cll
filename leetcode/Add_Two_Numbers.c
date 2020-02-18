#include <stdio.h>
#include <stdlib.h>
#include <math.h>       // gcc command should add -lm



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


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l1o = l1,      // l1o = l1 origin pointer
                    *l2o = l2,      // l2o = l2 origin pointer
                    *result,
                    *result_o,
                    *result_n;
    int cnt    = 0,                 // read list count value
        lo1buf = 0,                 // lo1 value buffer
        lo2buf = 0,                 // lo2 value buffer
        sum    = 0;

    result = calloc(1, sizeof(struct ListNode));
    result_o = result_n = result;

    //========================================
    do{
        l1 = l1->next;
        if(l1 == NULL)
            break;
        ++cnt;
    }while(1);

    l1 = l1o;

    do{
        lo1buf = lo1buf + (l1->val * pow(10, cnt-1));
        l1 = l1->next;
        cnt--;
    }while(cnt);

    cnt = 0;

    //=========================================
    do{
        l2 = l2->next;
        if(l2 == NULL)
            break;
        ++cnt;
    }while(1);

    l2 = l2o;

    do{
        lo2buf = lo2buf + (l2->val * pow(10, cnt-1));
        l2 = l2->next;
        cnt--;
    }while(cnt);

    //=========================================
    sum = lo1buf + lo2buf;

    do{
        result_n = calloc(1, sizeof(struct ListNode));
        result->val = sum % 10;
        sum = sum / 10;
        if(sum == 0)
            break;
        result->next = result_n;
        result = result->next;
    }while(1);
    

    return result_o;
}

void freeLinkList(struct ListNode *l, 
                  struct ListNode *ln, 
                  struct ListNode *lo){
    
    struct ListNode *lc;     //List Clean
    int cnt;
    
    while(l->next != NULL){
        lc = l->next;
        free(l);
        l = lc;
    }

    free(ln);
    free(lo);

}

void main(){
    struct ListNode *l1,
                    *l2,
                    *l1n,           // l1n = l1 next pointer
                    *l2n,           // l2n = l2 next pointer
                    *l1o,           // l1o = l1 origin pointer
                    *l2o,           // l2o = l2 origin pointer
                    *answer;
    int l1v[4]  ={2, 4, 3},         // l1v = l1 value
        l2v[4]  ={5, 6, 4},         // l2v = l2 value
        numList = 3,
        cnt     = 0;

    l1 = calloc(1, sizeof(struct ListNode));
    l2 = calloc(1, sizeof(struct ListNode));
    l1n = l1o = l1;
    l2n = l2o = l2;

    for(cnt=0; cnt<numList; cnt++){
        l1n = calloc(1, sizeof(struct ListNode));
        l1->val = l1v[cnt];
        l1->next = l1n;
        l1 = l1->next;      //l1n
        
        l2n = calloc(1, sizeof(struct ListNode));
        l2->val = l2v[cnt];
        l2->next = l2n;
        l2 = l2->next;      //l1n
    }

    l1 = l1o;
    l2 = l2o;
    
    answer = addTwoNumbers(l1, l2);

    freeLinkList(l1, l1n, l1o);
    freeLinkList(l2, l2n, l2o);

}