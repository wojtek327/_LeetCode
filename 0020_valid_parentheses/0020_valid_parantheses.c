//test cases
//"()"
//"()[]{}"
//"(]"
//"((][))"
//"([)]"
//"({[)"
//"{[]}"
//"([])"
//"{[}]"
//"("
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.
bool isValid(char* s) {
    if(s==NULL) {return false;}
    if(*s=='\0') {return false;}

    int stackSize = 0;
    while (s[stackSize] != '\0') {
        stackSize++;
    }

    if(stackSize == 1) { return false; }

    char* stack = (char*)malloc(stackSize);
    int top = -1;

    while(*s){
        if (*s == '(' || *s == '[' || *s == '{') {
            stack[++top] = *s;
        }
        else if (*s == ')' && (top == -1 || stack[top--] != '(')) {
            free(stack);
            return false;
        } 
        else if (*s == ']' && (top == -1 || stack[top--] != '[')) {
            free(stack);
            return false;
        } 
        else if (*s == '}' && (top == -1 || stack[top--] != '{')) {
            free(stack);
            return false;
        }
        s++; 
    }

    if(top == -1) {
        return true;
    }
    free(stack);

    return false;
}