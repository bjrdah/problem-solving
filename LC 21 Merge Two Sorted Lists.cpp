/**
 * Link : https://leetcode.com/problems/merge-two-sorted-lists/description/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2==NULL) return NULL;        
        if(list1 == NULL || list2==NULL) {
            if(list1 == NULL) return list2;
            return list1;
        }        
        ListNode* newMerge=(ListNode*)malloc(sizeof(ListNode));
        ListNode* res=(ListNode*)malloc(sizeof(ListNode));
        if(list1->val<list2->val) {newMerge=res=list1;list1=list1->next;}
        else {newMerge=res=list2;list2=list2->next;}
        while (list1!=NULL and list2!=NULL){
            if(list1->val < list2->val) {newMerge->next=list1;list1=list1->next;}
            else {newMerge->next=list2;list2=list2->next;}
            newMerge=newMerge->next;
        }
        while(list1!=NULL) {newMerge->next=list1;list1=list1->next; newMerge=newMerge->next;} 
        while(list2!=NULL) {newMerge->next=list2;list2=list2->next; newMerge=newMerge->next;} 
        return res;
    }
};
