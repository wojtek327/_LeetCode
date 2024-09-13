#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 char *letters[] = {
    "",         //0
    "",         //1
    "abc",      //2
    "def",      //3
    "ghi",      //4
    "jkl",      //5
    "mno",      //6
    "pqrs",     //7
    "tuv",      //8
    "wxyz"};    //9

 char** letterCombinations(char* digits, int* returnSize) {
    int len = strlen(digits);
    *returnSize = 0;

    if (len == 0 || digits == NULL || *digits == '\0') {
        return NULL;
    }

    int rows = 1;
    for (int i = 0; digits[i]; i++) {
        rows *= strlen(letters[digits[i] - '0']);
    }

    char** combs = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
         combs[i] = (char*)malloc((len + 1) * sizeof(char));
    }

    int queueSize = strlen(letters[digits[0] - '0']);
    for (int i = 0; i < queueSize; i++) {
        combs[i][0] = letters[digits[0] - '0'][i];
        combs[i][1] = '\0';
    }

    int currentSize = queueSize;

    for (int i = 1; i < len; i++) {
        int digit = digits[i] - '0';
        int nextQueueSize = currentSize * strlen(letters[digit]);

        for (int j = 0; j < currentSize; j++) {
            for (int k = 0; k < strlen(letters[digit]); k++) {
                memmove(combs[j + k * currentSize], combs[j], i * sizeof(char));
                combs[j + k * currentSize][i] = letters[digit][k];
                combs[j + k * currentSize][i + 1] = '\0';
            }
        }

        currentSize = nextQueueSize;
    }

    *returnSize = currentSize;
    return combs;
}
