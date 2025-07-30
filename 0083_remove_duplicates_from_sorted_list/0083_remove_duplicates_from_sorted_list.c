/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL) { return head; }
    if(head->next == NULL) { return head; }

    struct ListNode *temp = head->next;
    struct ListNode *lastValidElement = head;

    /* 
	W tej pętli:
		Jeśli temp->val różni się od ostatniej zachowanej unikalnej wartości, to:
		aktualizujemy wskaźnik next ostatniego unikalnego elementu (lastValidElement->next = temp)
		przesuwamy lastValidElement na temp (czyli zachowujemy nową unikalną wartość).
		Jeśli temp->val jest równe (duplikat), to go pomijamy — nie zmieniamy lastValidElement.
    */
    while(temp != NULL) {
        if(temp->val != lastValidElement->val) {
            lastValidElement->next = temp;
            lastValidElement=temp;
        }
        temp=temp->next;
    }
    lastValidElement->next=temp;

    return head;
}