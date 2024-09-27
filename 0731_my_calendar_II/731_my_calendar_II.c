
/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);

 * myCalendarTwoFree(obj);
*/

typedef struct {
    int start;
    int end;
    struct MyCalendarTwo* next;
} MyCalendarTwo;

static bool isOverlap(int start1, int end1, int start2, int end2) {
    return (start1 < end2 && start2 < end1);
}

MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* obj=(MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));
    obj->start=-1;
    obj->end=-1;
    obj->next=NULL;
    return obj;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    MyCalendarTwo* current = obj;
    MyCalendarTwo* p = obj->next;
    MyCalendarTwo* overlapList = NULL;

    while (p != NULL) {
        if (isOverlap(p->start, p->end, start, end)) {
            int overlapStart = (start > p->start) ? start : p->start;
            int overlapEnd = (end < p->end) ? end : p->end;

            MyCalendarTwo* q = overlapList;
            while (q != NULL) {
                if (isOverlap(q->start, q->end, overlapStart, overlapEnd)) {
                    return false;
                }
                q = q->next;
            }

            MyCalendarTwo* newOverlap = (MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));
            newOverlap->start = overlapStart;
            newOverlap->end = overlapEnd;
            newOverlap->next = overlapList;
            overlapList = newOverlap;
        }
        p = p->next;
    }

    current = obj;
    p = obj->next;

    while (current->next != NULL) {
        if (p->start >= end) {
            break;
        }
        current = current->next;
        p = p->next;
    }

    MyCalendarTwo* newNode = (MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));
    newNode->start = start;
    newNode->end = end;
    newNode->next = current->next;
    current->next = newNode;

    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    MyCalendarTwo* current = obj;
    while (current != NULL) {
        MyCalendarTwo* next = current->next;
        free(current);
        current = next;
    }
}
/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);

 * myCalendarFree(obj);
*/
