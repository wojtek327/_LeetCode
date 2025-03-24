/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //dwa wskaźniki algorytm wyszukiwania cyklami floyda
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL) {
        return false;
    }

    struct  ListNode* slow = head;
    struct  ListNode* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;

        if(fast != NULL) {
            fast = fast->next;
        }

        slow = slow->next;

        if(slow == fast) { return true; }
    }
    return false;
}
//hash table duzo wolniejsze rozwiązanie
bool hasCycle(struct ListNode *head) {

    struct ListNode* set[10000];
    int i = 0;

    while (head != NULL) {
        for (int j = 0; j < i; j++) {
            if (set[j] == head)
                return true;
        }
        set[i++] = head;
        head = head->next;
    }
    return false;
}
//pomysł polega na zmodyfikowaniu struktury węzła\
// poprzez dodanie do niego flagi i zaznaczenie flagi przy każdej wizycie w węźle.
//w związku z tym że strutktura listy nie ma zmiennej flag, to modyfikuje tutaj wartości
//raczej zły pomysł do zastosowania, podobny czas działa co rozwiązania z dwoma składnikami
bool hasCycle(struct ListNode *head) {
    while (head != NULL) {
        if (head->val == -10001) {
            return true;
        }
        head->val = -10001;

        head = head->next;
    }
    return false;
}

//wskazać bieżący węzeł połączonej listy na węzeł,
//który zostanie utworzony. Ilekroć następny węzeł
//wskazuje na ten węzeł, oznacza to, że istnieje pętla.
struct ListNode* createNode(int new_data) {
   struct ListNode* new_node
       = (struct ListNode*)malloc(sizeof(struct ListNode));
   new_node->val = new_data;
   new_node->next = NULL;
   return new_node;
}

bool hasCycle(struct ListNode *head) {
   struct ListNode* temp = createNode(0);

   while (head != NULL) {

       // This condition is for the case when there is no
       // loop
       if (head->next == NULL)
           return false;

       // Check if next is already pointing to temp
       if (head->next == temp)
           return true;

       // Store the pointer to the next node
       // in order to get to it in the next step
       struct ListNode* next = head->next;

       // Make next point to temp
       head->next = temp;

       // Get to the next node in the list
       head = next;
   }
   return false;
}
