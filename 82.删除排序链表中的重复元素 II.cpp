class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* cur = head;

        while (cur) {
            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            if (prev->next != cur) {
                prev->next = cur->next;
            } else {
                prev = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
v
