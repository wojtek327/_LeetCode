//ver1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comparator(const void* p, const void* q)
{
   return (*(int*)q - *(int*)p);
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    char** sortedNames = (char**)calloc(namesSize, sizeof(char*));
    *returnSize = heightsSize;

    for(int i = 0; i < heightsSize; i++) {
        heights[i] = (heights[i] << 10) + i;
    }

    qsort(heights, heightsSize, sizeof(int), comparator);

    for(int i = 0; i < heightsSize; i++) {
        sortedNames[i] = names[heights[i] & 0x3FF];
    }

    return sortedNames;
}
//ver2
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    char* name;
    int height;
} Person;

int comparator(const void* p, const void* q) {
    return ((Person*)q)->height - ((Person*)p)->height;
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    Person* people = (Person*)malloc(namesSize * sizeof(Person));
    *returnSize = namesSize;

    for (int i = 0; i < namesSize; i++) {
        people[i].name = names[i];
        people[i].height = heights[i];
    }

    qsort(people, namesSize, sizeof(Person), comparator);

    char** sortedNames = (char**)malloc(namesSize * sizeof(char*));
    for (int i = 0; i < namesSize; i++) {
        sortedNames[i] = people[i].name;
    }

    free(people);
    return sortedNames;
}

//PYTHON
class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        # Długość tablicy
        n: int = len(names)
        # mapowanie height i names, heights distinct, heights key
        mapping: dict[int, str] = {}

        # mapowanie po indeksie wzrostu
        for ind in range(n):
            mapping[heights[ind]] = names[ind]

        # sortowanie desceding order
        heights.sort(reverse=True)

        #Assigned names to correct position based on height
        for ind in range(n):
            h: int = heights[ind]
            names[ind] = mapping[h]

        return names
