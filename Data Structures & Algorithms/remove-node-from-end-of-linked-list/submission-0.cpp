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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* atual = head;
        int size = 0;
        while(atual != nullptr){
            size++;
            atual = atual->next;
        }

        atual = dummy;
        int novo_n = size-n;
        while(novo_n--){
            atual = atual->next;
        }

        ListNode* proximo = atual->next;
        atual->next = proximo->next;

        ListNode* nova_head = dummy->next;
        delete dummy;
        return nova_head;
    }
};
