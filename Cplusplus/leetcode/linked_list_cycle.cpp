/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> nodeSet;

        while(head) {
            auto search = nodeSet.find(head);
            if (search != nodeSet.end()) {
                return true;
            }
            nodeSet.insert(head);
            head = head->next;
        }
        return false;
    }

    bool hasCycle2(ListNode *head) {
        ListNode *p1 = head;
        ListNode *p2 = head;

        while(p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2) {
                p2 = p2->next;
            }

            if(nullptr != p2 && p1 == p2){
                return true;
            }
        }

        return false;
    }
};