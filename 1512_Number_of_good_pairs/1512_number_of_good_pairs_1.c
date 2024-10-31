//O(n^2)
int numIdenticalPairs(int* nums, int numsSize){
    int numberOfGoodPairs = 0;

    for(uint8_t j = 0; j<(numsSize-1); j++)
    {
        for(uint8_t i = (j+1); i<numsSize; i++)
        {
            if(*(nums + i) == *(nums + j))// && (i < j))
            {
                numberOfGoodPairs++;
            }
        }
    }


    return numberOfGoodPairs;
}
