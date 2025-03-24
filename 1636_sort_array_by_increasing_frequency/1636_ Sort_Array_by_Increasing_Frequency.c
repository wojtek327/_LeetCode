/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //1 <= nums.length <= 100
 //-100 <= nums[i] <= 100
 //frequency ilość wystąpień danej liczby
typedef struct {
    int value;
    int frequency;
} Element;

int compare(const void *a, const void *b) {
    Element *elemA = (Element *)a;
    Element *elemB = (Element *)b;
    if (elemA->frequency == elemB->frequency) {
        return elemB->value - elemA->value;
    } else {
        return elemA->frequency - elemB->frequency;
    }
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    Element elements[numsSize];

    int freq[201] = {0};

    //potrzebna tablica elementów 200 bo liczby od -100 do 100
    //w petli przechowywane ilości wystąpień danej wartości
    //czyli frequency
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + 100]++;
    }

    //sparowanie ilości wystąpień z częstotliwością występowania
    int idx = 0;
    for (int i = 0; i < 201; i++) {
        if (freq[i] > 0) {
            elements[idx].value = i - 100;
            elements[idx].frequency = freq[i];
            idx++;
        }
    }

    //Sortowanie elementów w tablicy elementy względem ilości wystąpień
    qsort(elements, idx, sizeof(Element), compare);

    //
    int sortedIdx = 0;
    //Pętla przechodzi przez każdy element
    for (int i = 0; i < idx; i++) {
        //petla przechodzi przez ilość elementów wpisując
        //każda wartość pojedynczo np. jak są trzy 2 to wpisuje je trzy razy
        for (int j = 0; j < elements[i].frequency; j++) {
            nums[sortedIdx++] = elements[i].value;
        }
    }

    *returnSize = numsSize;
    return nums;
}
