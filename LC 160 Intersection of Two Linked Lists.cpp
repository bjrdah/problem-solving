/**
 * Link : https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getListLength(ListNode* h){
        int i=0;
        while(h!=NULL) {i++;h=h->next;}
        return i;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==headB && headA!=NULL) return headA;
        if((headA==NULL)|| (headB==NULL) )return NULL;
        ListNode* a=headA;
        int la=getListLength(a);
        ListNode* b=headB;
        int lb=getListLength(b);
        int  d=abs(la-lb);
        if (la>lb){
           int j=0;
            while(j<d){a=a->next;j++;}
        }
        else {
           int j=0;
            while(j<d){b=b->next;j++;}
        }
        while(a!=NULL && b!=NULL){
            if (a==b) return b;
            a=a->next;
            b=b->next;
        }
        return NULL;
    }
};
