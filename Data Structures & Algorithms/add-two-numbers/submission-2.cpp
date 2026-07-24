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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumHead = new ListNode(0);
        ListNode* current = sumHead;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr){
            int t1, t2;
            if (l1 == nullptr){
                t1 = 0;
            }
            else {
                t1 = l1->val;
                l1 = l1->next;
            }
            if (l2 == nullptr){
                t2 = 0;
            }
            else {
                t2 = l2->val;
                l2 = l2->next;
            }
            
            int s =  t1 + t2 + carry;
            ListNode* sum = new ListNode(s % 10);
            carry = s/10;
            current->next = sum;
            current = current->next;
        }

        if (carry != 0){
            ListNode* carryP = new ListNode(carry);
            current->next = carryP;
        }

        return sumHead->next;
    }
};
