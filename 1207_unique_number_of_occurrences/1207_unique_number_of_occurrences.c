//python
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        counter = Counter(arr)
        s = set()
        for v in counter.values():
            if v in s:
                return False
            else:
                s.add(v)

        return True

//C
bool uniqueOccurrences(int* arr, int arrSize) {
    int *table = (int*)malloc(arrSize * sizeof(int));
    if (!table) { return false;  }
    memset(table, 0, arrSize * sizeof(int));

    for(uint16_t i = 0; i<arrSize; i++) {

    }

    return false;
}
