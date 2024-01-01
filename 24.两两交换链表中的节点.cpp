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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        auto cur = dummy;
        auto node1 = head;

        while (node1 && node1 -> next) {
            auto node2 = node1 -> next;
            auto node3 = node2 -> next;

            cur -> next = node2;
            node2 -> next = node1;
            node1 -> next = node3;


            cur = node1;
            node1 = node3;
        }
        return dummy -> next;
    }
};
