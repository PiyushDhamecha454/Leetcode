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
    ListNode* removeNthFromEnd(ListNode* head, int x) {
        if (!head || !head->next) return NULL;
        int n = 0;
        ListNode *temp = head;
        while (temp) {
            temp = temp->next;
            n++;
        }
        if (n == x) return head->next;
        temp = head;
        n -= x;
        while (n-- > 1) temp = temp->next;
        if (temp && temp->next) temp->next = temp->next->next;
        return head;
    }
};