/**
 * Link : https://leetcode.com/problems/add-two-numbers/description/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=l1;
        ListNode* prev;
        int res=0;
        int ansl1;
        while(true){
            ansl1=l1->val;
            l1->val=(l1->val+l2->val+res)%10;
            res=(ansl1+l2->val+res)/10;
            prev=l1;
            l1=l1->next;
            l2=l2->next;
            if(l1==nullptr && l2==nullptr){
                if(res!=0){
                    prev->next=new ListNode(res);
                    return ans;
                }
            }
            if(l1==nullptr){
                prev->next=l2;
                l1=prev->next;
                break;
            }
            if(l2==nullptr) {
                break;
            }
        }
        while(l1!=nullptr){
            ansl1=l1->val;
            l1->val=(l1->val+res)%10;
            res=(ansl1+res)/10;
            if(l1->next==nullptr){
                if(res!=0){
                    l1->next=new ListNode(res);
                    return ans;
                }
            }
            l1=l1->next;
        }
        return ans;
    }
};
