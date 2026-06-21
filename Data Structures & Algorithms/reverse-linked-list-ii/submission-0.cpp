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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* beforeleft = &dummy;
        for (int i = 1; i < left; i++)
            beforeleft = beforeleft->next;
        
        ListNode* leftnode = beforeleft->next;
        ListNode* prev = nullptr;
        ListNode* curr = beforeleft->next;
        ListNode* later;
        for (int i = left; i<=right; i++)
        {
            later = curr->next;
            curr->next = prev;
            prev=curr;
            curr=later;
        }

        beforeleft->next=prev;
        leftnode->next=curr;

        return dummy.next;
    }
};