#include <stdio.h>
#include <stdlib.h>
//#include <math.h>       // gcc command should add -lm



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

#if 1 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l1o    = l1,       /* l1o = l1 origin pointer         */
                    *l2o    = l2,       /* l2o = l2 origin pointer         */
                    *result = NULL,     /* result = output link list       */
                    *resulto;           /* resulto = result origin pointer */
    int sum   = 0,
        carry = 0;
    
    /* Allocate memory for result link list */
    result = calloc(1, sizeof(struct ListNode));
    resulto = result;

    while(1){
        sum = l1->val + l2->val + carry;
        result->val = sum % 10;
        if(sum >= 10)
            carry++;
        else
            carry = 0;      /* Means no carry */
        
        if(l1->next || l2->next || carry == 1){
            if(l1->next)
                l1 = l1->next;
            else
                l1->val = 0;

            if(l2->next)
                l2 = l2->next;
            else
                l2->val = 0;

            result->next = calloc(1, sizeof(struct ListNode));
            result = result->next;
        }
        else
        {
            break;
        }
    }
    return resulto;
}

#elif
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l1o = l1,      // l1o = l1 origin pointer
                    *l2o = l2,      // l2o = l2 origin pointer
                    *result,
                    *result_o,
                    *result_n;
    int  cnt    = 0,                 // read list count value
         cnt2   = 0;
    long lo1buf = 0,                 // lo1 value buffer
         lo2buf = 0,                 // lo2 value buffer
         sum    = 0;

    result = calloc(1, sizeof(struct ListNode));
    result_o = result_n = result;

    //========================================
    do{
        l1 = l1->next;
        ++cnt;
        if(l1 == NULL)
            break;
    }while(1);

    l1 = l1o;

    do{
        lo1buf = lo1buf + (l1->val * pow(10, cnt2));
        l1 = l1->next;
        cnt2++;
    }while(cnt2 != cnt);

    cnt  = 0;
    cnt2 = 0;

    //=========================================
    do{
        l2 = l2->next;
        ++cnt;
        if(l2 == NULL)
            break;
    }while(1);

    l2 = l2o;

    do{
        lo2buf = lo2buf + (l2->val * pow(10, cnt2));
        l2 = l2->next;
        cnt2++;
    }while(cnt2 != cnt);

    //=========================================
    sum = lo1buf + lo2buf;

    do{
        result->val = sum % 10;
        sum = sum / 10;
        if(sum == 0)
            break;
        result_n = calloc(1, sizeof(struct ListNode));
        result->next = result_n;
        result = result->next;
    }while(1);
    

    return result_o;
}
#endif

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