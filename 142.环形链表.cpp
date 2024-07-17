 /** 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val; 
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*之所以慢指针跑一圈的过程中，快指针一定能追上是因为：（极限思想） 假设他们都是从入环点开始跑的，
 那么当慢指针刚好跑完一圈时，快指针刚好跑完两圈，也是在一圈的末尾追上慢指针。
 而现实情况往往是在慢指针到入环处时快指针已经入环并走了了，所以实际情况一定会在第一圈之内相遇。*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast -> next != nullptr) {
                  fast = fast -> next -> next;
                  slow = slow -> next;
                  if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                 while (index1 != index2) {
                    index1 = index1 -> next;
                    index2 = index2 -> next;
                }
                 return index2; // 返回环的入口
                }
        }
        return NULL; 
    }
};
