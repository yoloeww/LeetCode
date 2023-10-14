/**
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        int t = 0;
        while (cur1 || cur2 || t) {
            if (cur1) {
                t += cur1 -> val;
                cur1 = cur1 -> next;
            }
            if (cur2) {
                t += cur2->val;
                cur2 = cur2 -> next;
            }
            cur -> next = new ListNode(t % 10);
            cur = cur -> next;
            t /= 10;

        }
        return dummy -> next;
    }
};
