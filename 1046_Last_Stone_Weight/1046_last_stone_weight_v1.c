int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int lastStoneWeight(int* stones, int stonesSize) {
    while(stonesSize > 1) {
        qsort(stones, stonesSize, sizeof(int), compare);

        if(*(stones + stonesSize - 1) == *(stones + stonesSize-2))
        {
            *(stones + stonesSize - 1)=0;
            *(stones + stonesSize - 2)=0;
            stonesSize-=2;
        }
        else 
        {
            *(stones + stonesSize - 2) = *(stones + stonesSize - 1) - *(stones + stonesSize - 2);
            stonesSize--;
        }
    }

   return *(stones); 
}