/**
 * Link : https://leetcode.com/problems/remove-linked-list-elements/description/ 
 *Definition for singly-linked list.
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        if((head->val==val)&&(head->next==NULL)) {return NULL;}
        if((head->val!=val)&&(head->next==NULL)) return head;
        ListNode* temp=head;
        while((temp!=NULL)&&(temp->val==val)){
            ListNode* curr=temp;
            temp=temp->next;
        }
        ListNode* newList=temp;
        ListNode* prev=temp;
        while(temp!=NULL){
            if(temp->val==val){
                prev->next=temp->next;
                
                temp=temp->next;
                
            }
            else {prev=temp;temp=temp->next;
            }
        }
        return newList;

    }
};
