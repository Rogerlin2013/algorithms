struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode *nullHead = new ListNode(0);
    nullHead->next = head;

    ListNode *p1 = nullHead;
    ListNode *p2 = head;

    if (NULL == head)
    {
        return head;
    }

    ListNode *p3 = head->next;

    while(p1 && p2 && p3) {
        ListNode *next = p3->next;

        p1->next = p3;
        p3->next = p2;
        p2->next = next;

        p1 = p2;
        p2 = p2->next;
        if (p2)
        {
            p3 = p2->next;
        }else {
            p3 = NULL;
        }
    }

    return nullHead->next;
}

ListNode* swapPairs(ListNode* head) {
    if (NULL == head || NULL == head->next)
    {
        return head;
    }

    ListNode* p1 = head;
    ListNode* p2 = head->next;

    p1->next = swapPairs(p2->next);
    p2->next = p1;

    return p2;
}