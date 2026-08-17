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
    
private:
    ListNode* merge2Lists(ListNode* a, ListNode* b){
        ListNode res(0);
        ListNode* tail = &res;

        while (a!= nullptr && b != nullptr){
            if (a->val <= b->val){
                tail->next = a;
                a = a->next;
            } 
            else {
                tail->next = b;
                b = b->next;
            }

            tail = tail->next;
        }

        tail->next = (a == nullptr) ? b : a;

        return res.next;

    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int interval = 1;
        int n = lists.size();

        while(interval < n){
            for (int i = 0; i + interval < n; i += interval*2){
                lists[i] = merge2Lists(lists[i], lists[i+interval]);
            }

            interval *= 2;
        }

        return lists[0];
    }
};
