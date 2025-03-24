/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 */
int* grayCode(int n, int* returnSize) {
    int size = 1 << n;
    *returnSize = size;

    int* arr = (int*) malloc(sizeof(int) * size);

     if (!arr) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = (i ^ (i >> 1));
    }

    return arr;
}
