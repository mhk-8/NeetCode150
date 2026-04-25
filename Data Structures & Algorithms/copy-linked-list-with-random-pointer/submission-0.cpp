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
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        curr = head;
        Node* dummy = new Node(0);  
        Node* copy_tail = dummy;

        while (curr != nullptr) {
            Node* clone = curr->next;
            copy_tail->next = clone;
            copy_tail = clone;
            curr->next = clone->next;
            curr = curr->next;
        }

        Node* result = dummy->next;
        delete dummy;  
        return result;
    }
};
