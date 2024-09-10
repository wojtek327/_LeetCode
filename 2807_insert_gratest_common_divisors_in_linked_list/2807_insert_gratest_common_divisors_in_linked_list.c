/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static int gcd(int a,int b);

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* tmp = head;

    while(tmp->next != NULL){
        struct ListNode* newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        if (newNode == NULL) {
            return head;
        }
        newNode->val = gcd(tmp->val, tmp->next->val);
        newNode->next=tmp->next;
        tmp->next=newNode;
        tmp=tmp->next->next;
    }

    return head;
}

static int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
