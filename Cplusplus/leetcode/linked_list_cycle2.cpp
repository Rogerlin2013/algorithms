#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodeSet;

        while(head) {
            auto pos = nodeSet.find(head);
            if (pos != nodeSet.end()) {
                return *pos;
            }else {
                nodeSet.insert(head);
            }
            head = head->next;
        }
        return nullptr;
    }
};