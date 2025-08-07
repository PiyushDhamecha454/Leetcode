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
    int getDecimalValue(ListNode* head) {
        string b = "";
        ListNode* temp = head;
        while (temp) {
            b += (temp->val + '0');
            temp = temp->next;
        }
        int num = 0;
        for (int i = 0; i < b.size(); i++) num += pow(2, b.size() - i - 1) * (b[i] - '0');
        return num;
    }
};