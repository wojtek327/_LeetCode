/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL) { return head; }
    if(head->next == NULL) { return head; }

    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* next;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;

        prev=curr;
        curr=next;
    }

    return prev;
}