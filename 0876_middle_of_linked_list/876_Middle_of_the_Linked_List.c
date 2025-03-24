/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    //two pointers slow and fast 
    struct ListNode *fast;
    struct ListNode *slow;

    fast = head;
    slow = head; 

     while(fast!=NULL && fast->next!=NULL){
         fast = fast->next->next;
         slow = slow->next;
     }
     return slow;
}