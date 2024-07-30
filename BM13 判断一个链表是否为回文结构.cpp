/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        // write code here
        if (head == nullptr) return nullptr;
        ListNode* fast = head -> next;
        ListNode* slow = head;
        ListNode* newend = head -> next;
        while (fast && fast -> next) {
            slow -> next = slow -> next -> next;
            fast -> next = fast -> next -> next;
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = newend;
        return head;
    }
};
