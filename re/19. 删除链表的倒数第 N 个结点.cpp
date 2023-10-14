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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n == 0) return nullptr;

        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* x = findListNode(dummy,n + 1);
        x -> next = x -> next -> next;
        return dummy -> next;
    }
    ListNode* findListNode(ListNode* head,int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (k -- && fast) {
            fast = fast -> next;
        }
        while (fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};
