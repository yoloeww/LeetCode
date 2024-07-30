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
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    ListNode* rever(ListNode* head) {
        if (head == nullptr && head -> next == nullptr) return head;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* temp = nullptr;
        while (cur) {
            temp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    bool isPail(ListNode* head) {
        // write code here
        if (head == nullptr || head -> next == nullptr) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        // if (fast != nullptr) {
        //     slow = slow -> next;
        // }
        ListNode* cur = head;
        ListNode* mid = rever(slow);
        while (mid) {
            if (cur -> val != mid -> val) return false;
            mid = mid -> next;
            cur = cur -> next;
        }
        return true;
    }
};
