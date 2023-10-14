/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if (head == nullptr || head -> next == nullptr)  return nullptr;
        while (fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (fast == slow) {
                ListNode* index1 = slow;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1 -> next;
                    index2 = index2 -> next;
                }
                return index2;
        }
        
    }
    return nullptr;
    }
};
