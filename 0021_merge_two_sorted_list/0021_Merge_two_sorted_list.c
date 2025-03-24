//Listy są posortowane

//C - iteracyjnie
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL && list2 == NULL) { return NULL; }
    else if(list1 == NULL) { return list2; }
    else if(list2 == NULL) { return list1; }

    //Stworzenie listy
    struct ListNode* root=(struct ListNode*)malloc(sizeof(struct ListNode));

    //Dodanie pierwszego elementu
    if(list1->val > list2->val){
        root->val=list2->val;
        list2=list2->next;
    }
    else{
        root->val=list1->val;
        list1=list1->next;
    }

    //Przechodzimy iteracyjnie p liscie. Root wskazuje na początek listy
    //i to jego będziemy zwracać
    struct ListNode* iter=root;

    //Dopoku listy nie sa piuste
    while(list1 != NULL && list2 != NULL){
        iter->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        iter=iter->next;
        if(list1->val >list2->val){
            iter->val=list2->val;
            list2=list2->next;
        }
        else{
            iter->val=list1->val;
            list1=list1->next;
        }
    }

    //Jeśli jedna jest null a druga jeszcze nie
    if(list1 == NULL && list2 != NULL){
        while(list2 != NULL){
            iter->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            iter=iter->next;
            iter->val=list2->val;
            list2=list2->next;
        }
    }
    else if(list1 != NULL && list2 == NULL){
        while(list1 != NULL){
            iter->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            iter=iter->next;
            iter->val=list1->val;
            list1=list1->next;
        }
    }

    //Ostatni wskaźnik wskazuje na null
    iter->next=NULL;
    return root;
}

//C Poprawione rozwiązanie powyżej
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Jeśli jedna z list jest pusta, zwracamy drugą,
    //Jeśli obie są puste to powinniśmy zwrócić NULL
    //I tak się stanie jak zwrócimy drugą z nich
    if (list1 == NULL) { return list2; }
    if (list2 == NULL) { return list1; }

    // Wskaźnik do wynikowej listy
    struct ListNode* mergedList = NULL;

    // Wskaźnik do ostatniego elementu w wynikowej liście
    struct ListNode** lastPtrRef = &mergedList;

    // Przechodzimy przez listy, aż jedna z nich się skończy
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            *lastPtrRef = list1;
            list1 = list1->next;
        } else {
            *lastPtrRef = list2;
            list2 = list2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    // Dodajemy pozostałe elementy jednej z list
    if (list1 != NULL) {
        *lastPtrRef = list1;
    } else {
        *lastPtrRef = list2;
    }

    return mergedList;
}

//C - recurssion
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL && list2 == NULL) { return NULL; }
    else if(list1 == NULL) { return list2; }
    else if(list2 == NULL) { return list1; }

    struct ListNode* root=NULL;

    // Pick either a or b, and recur
    if (list1->val <= list2->val) {
        root = list1;
        root->next = mergeTwoLists(list1->next, list2);
    }
    else {
        root = list2;
        root->next = mergeTwoLists(list1, list2->next);
    }
    return (root);
}
