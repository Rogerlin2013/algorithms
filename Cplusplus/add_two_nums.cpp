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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = nullptr;
        ListNode *tail = nullptr;
        int carry = 0;

        while (l1 != nullptr && l2 != nullptr) {
            ListNode * node = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;

            if (ans == nullptr) {
                ans = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *left = nullptr;
        if (l1 != nullptr) {
            left = l1;
        }
        if (l2 != nullptr) {
            left = l2;
        }

        while (left != nullptr) {
            ListNode * node = new ListNode((left->val + carry) % 10);
            carry = (left->val + carry) / 10;

            tail->next = node;
            tail = node;
            left = left->next;
        }
        if (carry > 0) {
            ListNode * node = new ListNode(carry);
            tail->next = node;
        }
        return ans;
    }
};