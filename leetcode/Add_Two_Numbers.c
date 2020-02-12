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
    
    //=========================================
    sum = lo1buf + lo2buf;

    
    
    

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

void main(){
    struct ListNode *l1,
                    *l2,
                    *l1o = l1,      // l1o = l1 origin pointer
                    *l2o = l2;      // l2o = l2 origin pointer
    int l1v[4]  ={2, 4, 3},         // l1v = l1 value
        l2v[4]  ={5, 6, 4},         // l2v = l2 value
        numList = 3,
        cnt     = 0;

    l1 = (struct ListNode*)malloc(numList * sizeof(struct ListNode));
    l2 = (struct ListNode*)malloc(numList * sizeof(struct ListNode));

    for(cnt=0; cnt<numList; cnt++){
        l1 = calloc(1, sizeof(struct ListNode));
        l1 = l1->next;
        cnt++;
    }

    for(cnt=0; cnt<numList; cnt++){
        l2 = calloc(1, sizeof(struct ListNode));
        l2 = l2->next;
        cnt++;
    }

    l1 = l1o;
    l2 = l2o;
    cnt = 0;

    do{
        l1->val = l1v[cnt];
        l2->val = l2v[cnt];
        l1 = l1->next;
        l2 = l2->next;
        cnt++;
    }while(cnt < numList);

    addTwoNumbers(l1, l2);

#if 0
    struct ListNode **l1,
                    **l2,
                     *temp = *l1;
    int numList = 3;                // set defult number of value in list
    char listBuf[3]={'2','4','3'};
    int i;


    l1 = (struct ListNode**)malloc(numList * sizeof(struct ListNode*));
    l2 = (struct ListNode**)malloc(numList * sizeof(struct ListNode*));
    for (i=0; i<numList; i++){
        l1[i] = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    }
    for (i=0; i<numList; i++){
        l2[i] = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    }


    i=0;
    while(i<numList){
        l1[i]->val = listBuf[i];
        if((i+1) < numList)
            l1[i]->next = l1[i+1];
        printf("value: %d\n", l1[i]->val);
        i++;
    }

    addTwoNumbers(l1[1],l2[1]);
#endif


}