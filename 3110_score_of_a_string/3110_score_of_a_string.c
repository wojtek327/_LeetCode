/*
hello
h => 104 [0]
e => 101 [1]
l => 108 [2]
l => 108 [3]
o => 111 [4]

104 - 101	[0] - [1]
101 - 108	[1] - [2]
108 - 108	[2] - [3]
108 - 111	[3] - [4]

|[0] - [1]| + |[1] - [2]| + |[2] - [3]| + |[3] - [4]|

|104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| =>

 |3| + |-7| + |0| + |-3| => 3 + 7 + 0 + 3 = 13
*/

int scoreOfString(char* s) {
    if(*s == '\0') { return 0; }

    int score = 0;

    while(*(s + 1) != '\0') {
        score += abs(*s - *(s + 1));
        s++;
    }

    return score;
}

//Więcej pamięci zużywa trochę szybciej działa
int scoreOfString(char* s) {
    if (*s == '\0') {
        return 0; // Return 0 if the string is empty
    }

    int score = 0;
    char* current = s;
    char* next = s + 1;

    for (; *next != '\0'; current++, next++) {
        score += abs(*current - *next);
    }

    return score;
}
