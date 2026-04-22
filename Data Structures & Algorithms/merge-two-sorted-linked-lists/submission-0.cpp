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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0); 
        ListNode* tail = &dummy;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;      // Attach list1's node to our merged list
                list1 = list1->next;     // Move list1's pointer forward
            } else {
                tail->next = list2;      // Attach list2's node to our merged list
                list2 = list2->next;     // Move list2's pointer forward
            }
            tail = tail->next; 
        }
        if (list1 != nullptr) {
            tail->next = list1;
        } else if (list2 != nullptr) {
            tail->next = list2;
        }
        
        // The real merged list starts exactly one node after our fake dummy
        return dummy.next;
    }
};
