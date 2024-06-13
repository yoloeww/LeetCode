 /** 
 * Definition for singly-linkedlist.
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
        ListNode* dummy = new ListNode(0);
        dummy -> next= head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        n++;
        if (head == nullptr)
            return nullptr;
        ListNode* cur = head;
        while(n -- && fast != nullptr) {
        fast = fast -> next;
        }
        while (fast) {
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode* temp = slow -> next;
        slow -> next = slow -> next -> next;
        delete temp;
        return dummy -> next;
    }
};
