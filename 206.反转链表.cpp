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
    ListNode* reverseList(ListNode* head) {
         ListNode* temp;
         ListNode* pre = nullptr;
         ListNode* cur = head;
         while(cur) {
             temp = cur -> next;
             cur -> next = pre;
             pre = cur;
             cur = temp;
         }
       return pre;
    }
};
2023/5/24
206. 反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* temp = nullptr;
        ListNode* pre = nullptr;
        while (cur) {
            pre = cur -> next;
            cur -> next = temp;
            temp = cur;
            cur =  pre;
        }
        return temp;
    }
};
