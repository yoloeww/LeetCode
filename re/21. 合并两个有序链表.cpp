lass Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        while (cur1 && cur2) {
            if (cur1 -> val > cur2 -> val) {
                cur -> next = cur2;
                cur2 = cur2 -> next;
            }
            else {
                cur -> next = cur1;
                cur1 = cur1 -> next;
            }
            cur = cur -> next;
        }
        if (cur1) cur -> next = cur1;
        if (cur2) cur -> next = cur2;
        return dummy -> next;
    }
};
