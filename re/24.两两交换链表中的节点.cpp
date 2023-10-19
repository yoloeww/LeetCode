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
 迭代：
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode();
        dummy -> next = head;
        auto cur = dummy;
        auto node1 = head;
        while (node1 && node1 -> next) {
            
            auto node2 = node1 -> next;
            auto node3 = node2 -> next;

            cur -> next = node2;
            node2 -> next = node1;
            node1 -> next = node3
            
            cur = node1;
            node1 = node3;
        }
        return dummy -> next;
    }
};
时间复杂度：O(n)，其中 n 是链表的节点数量。需要对每个节点进行更新指针的操作。

空间复杂度：O(1)
