char* multiply(char* num1, char* num2) {
    size_t num1Leng = strlen(num1);
    size_t num2Leng = strlen(num2);

    size_t resultSize = num1Leng + num2Leng;
    int *result = (int*)calloc(resultSize, sizeof(int));
    if (!result) {
        return NULL;
    }

    for (int i = num1Leng - 1; i >= 0; i--) {
        for (int j = num2Leng - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    char *resultStr = (char*)malloc(resultSize + 1);
    if (!resultStr) {
        free(result);
        return NULL;
    }

    int k = 0;
    int i = 0;

    while (i < resultSize && result[i] == 0) {
        i++;
    }

    while (i < resultSize) {
        resultStr[k++] = result[i++] + '0';
    }
    resultStr[k] = '\0';

    if (k == 0) {
        resultStr[0] = '0';
        resultStr[1] = '\0';
    }

    free(result);
    return resultStr;
}
