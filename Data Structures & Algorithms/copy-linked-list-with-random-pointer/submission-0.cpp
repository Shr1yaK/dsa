/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map <Node*, Node*> mp;
        Node *curr = head;
        while (head!=NULL)
        {
            Node *new_node = new Node(head->val);
            mp[head]=new_node;
            head=head->next;
        }    

        head = curr;
        while (head!=NULL)
        {
            Node* copy = mp[head];
            copy->next = mp[head->next];
            copy->random = mp[head->random];
            head=head->next;
        }

        return mp[curr];
    }
};