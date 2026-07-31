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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        ListNode* current = head;
        stack<ListNode*> stk;
        while (current != nullptr){
            stk.push(current);
            current = current->next;
        }

        int n = stk.size();
        current = head;

        for (int i = 0; i < n/2; i++){
            ListNode* nextNode = current->next;
            ListNode* topNode = stk.top();
            stk.pop();
            
            topNode->next = nextNode;
            current->next = topNode;
            current = nextNode;
        }

        current->next = nullptr;
    }
};
