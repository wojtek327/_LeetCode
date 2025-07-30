/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 typedef struct {
    int key;    // Wartość z tablicy
    int index;  // Indeks wartości w tablicy
    UT_hash_handle hh; // Makro do obsługi hashmapy (UTHash)
} HashMapEntry;

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    HashMapEntry* hashMap = NULL;  // Inicjalizacja hashmapy

    for (int i = 0; i < numbersSize; i++) {
        int complement = target - numbers[i];

        // Sprawdzenie, czy wartość "complement" już istnieje w hashmapie
        HashMapEntry* entry;
        HASH_FIND_INT(hashMap, &complement, entry);
        if (entry) {
            result[0] = entry->index;
            result[1] = i+1;
            return result;
        }

        // Dodanie nums[i] do hashmapy
        entry = (HashMapEntry*)malloc(sizeof(HashMapEntry));
        entry->key = numbers[i];
        entry->index = i+1;
        HASH_ADD_INT(hashMap, key, entry);
    }

    // Jeśli nie znaleziono rozwiązania
    result[0] = -1;
    result[1] = -1;
    return result;
}
