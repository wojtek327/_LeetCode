
//wartość missing_number nie może być zainicjalizowana 
//wartością zero.

int missingNumber(int* nums, int numsSize){
    int missing_number = numsSize;
    
    for(int i =0; i < numsSize; i++) 
    {
        missing_number ^= nums[i] ^ i;
    }
    
    return missing_number;
}
