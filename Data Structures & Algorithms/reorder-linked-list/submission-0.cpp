/**
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
    void reorderList(ListNode* head) 
    {
        // find middle
        ListNode *slow=head;
        ListNode *fast=head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //split into two lists
        ListNode *second = slow->next;
        slow->next=nullptr;

        //reverse second
        ListNode *prev = nullptr;
        ListNode *curr = second;
        ListNode *later;
        while (curr!=nullptr)
        {
            later = curr->next;
            curr->next=prev;
            prev=curr;
            curr=later;
        }
        second=prev; //new head of reversed list

        //merge
        ListNode *first = head;
        ListNode *next1;
        ListNode *next2;
        while (first && second)
        {
            next1=first->next;
            next2=second->next;
            first->next=second;
            second->next=next1;
            first=next1;
            second=next2;
        }
    }
    
};