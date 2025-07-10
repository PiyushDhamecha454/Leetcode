class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* l = head;
        ListNode* r = head->next;

        while (l && r) {
            swap(l->val, r->val);
            if (!r->next || !r->next->next) break;
            l = l->next->next;
            r = r->next->next;
        }

        return head;
    }
};