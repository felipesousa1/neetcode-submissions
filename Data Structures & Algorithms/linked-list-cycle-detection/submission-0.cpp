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
    unordered_set<ListNode*> visited;
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        
        if (visited.find(head) != visited.end()) return true;

        visited.insert(head);

        return hasCycle(head->next);
    }
};
