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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        int n = 0;
        while (cur1) {
            n++;
            cur1 = cur1 -> next;
        }
        while (cur2) {
            n--;
            cur2 = cur2 -> next;
        }
        if (cur1 != cur2)
            return nullptr;
        cur1 = n > 0 ? headA : headB;
        cur2 = cur1 == headA ? headB : headA;
        n = abs(n);
        while (n != 0) {
            n --;
            cur1 = cur1 -> next;
        }
        while (cur1 != cur2) {
            cur1 = cur1 -> next;
            cur2 = cur2 -> next;
        }
        return cur1;
    }
};
