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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int sum=0;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int d1; int d2;
        while (l1 || l2)
        {
            if (l1) d1=l1->val;
            else    d1=0;

            if (l2) d2=l2->val;
            else    d2=0;

            sum=sum+d1+d2;
            ListNode *newNode = new ListNode(sum%10);
            tail->next=newNode;
            tail=tail->next;
            sum=sum/10;
            if (l1) l1=l1->next;
            if (l2) l2=l2->next;
        }

        if (sum!=0)
        {
            ListNode *newNode = new ListNode(sum%10);
            tail->next=newNode;
            tail=tail->next;
        }

        return dummy.next;
    }
};