#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;    // Wartość z tablicy
    int index;  // Indeks wartości w tablicy
    UT_hash_handle hh; // Makro do obsługi hashmapy (UTHash)
} HashMapEntry;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    HashMapEntry* hashMap = NULL;  // Inicjalizacja hashmapy

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        // Sprawdzenie, czy wartość "complement" już istnieje w hashmapie
        HashMapEntry* entry;
        HASH_FIND_INT(hashMap, &complement, entry);
        if (entry) {
            result[0] = entry->index;
            result[1] = i;
            return result;
        }

        // Dodanie nums[i] do hashmapy
        entry = (HashMapEntry*)malloc(sizeof(HashMapEntry));
        entry->key = nums[i];
        entry->index = i;
        HASH_ADD_INT(hashMap, key, entry);
    }

    // Jeśli nie znaleziono rozwiązania
    result[0] = -1;
    result[1] = -1;
    return result;
}
