int calPoints(char** operations, int operationsSize) {
    int* tmpArr = (int*) calloc(operationsSize,sizeof(int));
    int tmpArr_pos = 0;
    int sum = 0;

    for(int i = 0; i < operationsSize; ++i)
    {
        tmpArr[i] = 0;
    }

    for(int i =0; i<operationsSize; i++) {
        if(*operations[i] == '+') {
            *(tmpArr + (tmpArr_pos)) = *(tmpArr + tmpArr_pos - 1) + *(tmpArr + tmpArr_pos - 2);
            tmpArr_pos++;
        } else if(*operations[i] == 'C') {
            tmpArr_pos--;
            *(tmpArr + tmpArr_pos) = 0;
        } else if(*operations[i] == 'D') {
            *(tmpArr + (tmpArr_pos)) = *(tmpArr + tmpArr_pos - 1) * 2;
            tmpArr_pos++;
        } else {
            *(tmpArr + tmpArr_pos) = atoi(*(operations+i));
            tmpArr_pos++;
        }
    }

    for(int i = 0; i < operationsSize; ++i)
    {
        sum += tmpArr[i];
    }

    free(tmpArr);
    return sum;
}
