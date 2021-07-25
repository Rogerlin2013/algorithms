
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 迭代法
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    ListNode *result = new ListNode(0);
    ListNode *tail = result;
    
    while (l1 && l2)
    {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
            
        }else {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
        tail->next = nullptr;
    }

    tail->next = l1? l1 : l2;

    return result->next;
}

// 递归
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    if (nullptr == l1) {
        return l2;
    }
    if (nullptr == l2) {
        return l1;
    }

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }else {
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }
}