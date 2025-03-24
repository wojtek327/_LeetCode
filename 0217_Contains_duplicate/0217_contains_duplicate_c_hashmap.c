//zuzywa duzo pamieci ale dziala szybciej
typedef struct {
    int key;
    UT_hash_handle hh;
} HashItem;

bool containsDuplicate(int* nums, int numsSize) {
    HashItem* hashTable = NULL;  // Inicjalizacja hashtable

    for (int i = 0; i < numsSize; ++i) {
        HashItem* item;

        HASH_FIND_INT(hashTable, &nums[i], item);
        if (item) {
            HASH_CLEAR(hh, hashTable);
            return true;
        }

        item = (HashItem*)malloc(sizeof(HashItem));
        item->key = nums[i];
        HASH_ADD_INT(hashTable, key, item);
    }

    HASH_CLEAR(hh, hashTable);
    return false;
}
