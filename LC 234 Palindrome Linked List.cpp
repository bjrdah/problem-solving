/**
  * Link : https://leetcode.com/problems/palindrome-linked-list/description/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* inversList(ListNode* head){
       ListNode* curr=head;
       ListNode*  prev=NULL;
       ListNode* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* getSecondHalf(ListNode* head){

        ListNode*p =head;
        ListNode*q =head;
        while(p->next!=NULL){
            p=p->next->next;
            if(p==NULL) {p=q->next;break;}
            if (p->next==NULL){p=q->next->next;break;}
            
            q=q->next;
        }
        q->next=NULL;
        p=inversList(p);
        return p;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* sec=getSecondHalf(head);
        while(sec!=NULL) {
            if(head->val != sec->val)return false;
            head=head->next;
            sec=sec->next;
        }
        return true;
    }
};
