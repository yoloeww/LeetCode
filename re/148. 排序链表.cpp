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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
    ListNode* mergeSort(ListNode* head) {
        if (!head || !head -> next) return head;
        ListNode* mid = findMid(head);
        ListNode* l1 = head;
        ListNode* l2 = mid -> next;
        mid -> next = nullptr;
        l1 = mergeSort(l1);
        l2 = mergeSort(l2);
        return merge(l1,l2);
    }
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head,*fast = head;
        while (fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode();
        ListNode* cur = dummyHead;
        while (l1 && l2) {
            if (l1 -> val <= l2 -> val) {
                cur -> next = l1;
                l1 = l1 -> next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur -> next;
        }
        cur -> next = l1 ? l1 : l2;
        return dummyHead -> next;
    }
};
