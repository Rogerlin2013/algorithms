/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* pNew = head;
    ListNode* pLastNew = NULL;

    while(pNew) {
        ListNode *next = pNew->next;

        pNew->next = pLastNew;
        pLastNew = pNew;
        pNew = next;
    }
    return pLastNew;
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