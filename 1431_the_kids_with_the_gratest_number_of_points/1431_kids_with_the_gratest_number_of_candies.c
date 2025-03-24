/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool * array;
    array = (bool*)malloc(candiesSize * sizeof(bool));

    int maxNumber = *(candies+0);

    for(uint8_t i=1; i<candiesSize; i++)
    {
        if(maxNumber < *(candies+i))
        {
            maxNumber = *(candies+i);
        }
    }

    for(uint8_t i=0; i<candiesSize; i++)
    {
        if((candies[i] + extraCandies) >= maxNumber) {
            array[i] = true;
        }
        else {
            array[i] = false;
        }
    }

    *returnSize = candiesSize;
    return (array);
}


bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    if (candies == NULL || candiesSize == 0 || candiesSize > 255) {
        *returnSize = 0;
        return NULL;
    }

    bool * array;
    array = (bool*)malloc(candiesSize * sizeof(bool));

    int maxNumber = *(candies+0);

    for(uint8_t i=1; i<candiesSize; i++)
    {
        if(maxNumber < *(candies+i))
        {
            maxNumber = *(candies+i);
        }
    }

    for(uint8_t i=0; i<candiesSize; i++)
    {
        if((candies[i] + extraCandies) >= maxNumber) {
            array[i] = true;
        }
        else {
            array[i] = false;
        }
    }

    *returnSize = candiesSize;
    return (array);
}
