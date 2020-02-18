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
                    *result;
    int cnt    = 0,                 // read list count value
        cnt2   = 0,
        lo1buf = 0,                 // lo1 value buffer
        lo2buf = 0,                 // lo2 value buffer
        sum    = 0;

    //========================================
    while(l1 != NULL){
        ++cnt;
        l1 = l1->next;
    }

    l1 = l1o;

    do{
        lo1buf = lo1buf + (l1->val * pow(10, cnt));
        l1 = l1->next;
        cnt--;
    }while(cnt);
    printf("lo1buf = %d\n", lo1buf);
    //=========================================
    while(l2 != NULL){
        ++cnt;
        l2 = l2->next;
    }

    l2 = l2o;

    do{
        lo2buf = lo2buf + (l2->val * pow(10, cnt));
        l2 = l2->next;
        cnt--;
    }while(cnt);
    printf("lo2buf = %d\n", lo2buf);
    //=========================================
    sum = lo1buf + lo2buf;

    do{
        result->val = sum % 10;
        sum = sum / 10;
        result = result->next;
    }while(sum != 0);
    

    return result;
    



#if 0
    while(lo1){
        lo1buf = lo1->val;
        lo1buf = lo1buf * pow(10, cnt);
        cnt++;
    }
    cnt = 0;                        // cnt restore value
    printf("lo1buf = %d\n", lo1buf);
    return l1;
#endif
}

void freeLinkList(struct ListNode *l, 
                  struct ListNode *ln, 
                  struct ListNode *lo,
                  int numList){
    
    struct ListNode *lc;     //List Clean
    int cnt;
    
    for(cnt=0; cnt<numList; cnt++){
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

    freeLinkList(l1, l1n, l1o, numList);
    freeLinkList(l2, l2n, l2o, numList);

}