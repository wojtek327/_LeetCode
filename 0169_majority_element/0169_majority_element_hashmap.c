typedef struct {
    int key;    // Wartość z tablicy
    int index;  // Indeks wartości w tablicy
    UT_hash_handle hh; // Makro do obsługi hashmapy (UTHash)
} HashMapEntry;

int majorityElement(int* nums, int numsSize) {
    if(nums == NULL) { return 0; }
    if(*nums == '\0') { return 0; }

    int returnVal = 0;
    int value = 0;

    HashMapEntry* hashMap = NULL;  // Inicjalizacja hashmapy

    for (int i = 0; i < numsSize; i++) {
        HashMapEntry* item;
        HASH_FIND_INT(hashMap, &nums[i], item);

        if(item) {
            item->index += 1;
        } else {
            item = (HashMapEntry*)malloc(sizeof(HashMapEntry));
            item->key = nums[i];
            item->index = 1;

            if(item->index > returnVal) {
                value = nums[i];
            }

            HASH_ADD_INT(hashMap, key, item);
        }

        if (item->index > returnVal) {
            returnVal = item->index;
            value = nums[i];
        }
    }

    HashMapEntry *current, *tmp;
    HASH_ITER(hh, hashMap, current, tmp) {
        HASH_DEL(hashMap, current);
        free(current);
    }

    return value;
}
