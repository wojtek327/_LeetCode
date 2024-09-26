typedef struct {
    int start;
    int end;
    struct MyCalendar* next;
} MyCalendar;

MyCalendar* myCalendarCreate() {
    MyCalendar* obj=(MyCalendar*)malloc(sizeof(MyCalendar));
    obj->start=-1;
    obj->end=-1;
    obj->next=NULL;
    return obj;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    MyCalendar* current = obj;
    MyCalendar* p=obj->next;

    while (current->next != NULL) {
        if (p->start >= end) {
            break;
        }
        if (p->end > start) {
            return false;
        }
        current = current->next;
        p=p->next;
    }

    MyCalendar* newNode = (MyCalendar*)malloc(sizeof(MyCalendar));
    newNode->start = start;
    newNode->end = end;
    newNode->next = current->next;
    current->next = newNode;

    return true;
}

void myCalendarFree(MyCalendar* obj) {
    MyCalendar* current = obj;
    while (current != NULL) {
        MyCalendar* next = current->next;
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
