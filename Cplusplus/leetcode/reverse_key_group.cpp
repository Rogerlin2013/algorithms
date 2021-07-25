

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k < 2) {
        return head;
    }

    ListNode *new_head = nullptr;
    ListNode *new_tail = nullptr;

    ListNode *cur = head;

    // k group
    ListNode *kg_tail = nullptr;
    ListNode *kg_head = nullptr;
    int length = 0;

    while(true) {
        while(cur && length < k) {
                ListNode *temp = cur;
                cur = cur->next;

                if (!kg_tail)
                {
                    kg_head = kg_tail = temp;
                    temp->next = nullptr;
                }else {
                    temp->next = kg_head;
                    kg_head = temp;
                }
                length++;
            }

            if (length == k)
            {
                if (new_tail)
                {
                    new_tail->next = kg_head;
                    new_tail = kg_tail;
                }else {
                    new_head = kg_head;
                    new_tail = kg_tail;
                }
                length = 0;
                kg_head = nullptr;
                kg_tail = nullptr;
            }else {
                ListNode *left_head = reverseList(kg_head);
                if (new_tail) {
                    new_tail->next = left_head;
                    return new_head;
                }else {
                    return left_head;
                }
            }
    }
}

ListNode* reverseList(ListNode* head) {
    if (NULL == head || NULL == head->next)
    {
        return head;
    }
    
    ListNode* pNewLastNode = head->next;
    head->next = NULL;
    ListNode* pNewHeadNode = reverseList(pNewLastNode);
    pNewLastNode->next = head;
    
    return pNewHeadNode;
}