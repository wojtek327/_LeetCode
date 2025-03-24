struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL) { return NULL; }

    struct ListNode* A = headA;
    struct ListNode* B = headB;

    while(A != B) {
        if (A == NULL) { A = headB; }
        else { A = A->next; }

        if (B == NULL) { B = headA; }
        else { B = B->next; }
    }

    return A;
}

//Bardzo wolno O(M*N) dwie petle
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL) { return NULL; }

    struct ListNode *temp;

    while (headB != NULL) {
        temp = headA;
        while (temp != NULL) {

            // if both Nodes are same
            if (temp == headB)
                return headB;
            temp = temp->next;
        }
        headB = headB->next;
    }

    return NULL;
}

//HashTable
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL) { return NULL; }

    struct ListNode *visitedNodes[30000];
    int count = 0;

    // Traverse the first list and store all nodes in an array
    struct ListNode *curr1 = headA;

    while (curr1 != NULL) {
        visitedNodes[count++] = curr1;
        curr1 = curr1->next;
    }

    // Traverse the second list and check if any node is in the array
    struct ListNode *curr2 = headB;
    while (curr2 != NULL) {
        for (int i = 0; i < count; i++) {
            // Intersection point found
            if (visitedNodes[i] == curr2)
                return curr2;
        }
        curr2 = curr2->next;
    }

    return NULL;
}
