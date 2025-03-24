//#1 min 3 character
//#2 digits
//#3 English letters big and small

//one vovel aeiou
//one consonant rest lettrers

//ASCII
//DIGIT from 0x30 to 0x39
//Characters Big 0x41 to 0x5A 
//Characters small 0x61 to 0x7A

size_t custom_strlen(const char* str) {
    size_t len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

bool isValid(char* word) {
    if (custom_strlen(word) < 3) { return false; }
	/*
	//Dodatkowe zabezpieczenie nie wymagane w tym zadaniu
    if (word == NULL) { return false; }
    if (*word == '\0') { return false; }
	*/

    bool oneVovel = false;
    bool oneConsonant = false;

    while(*word) {
        uint8_t checkFlag = 0;
        uint8_t isDigit = 0;

        if((*word >= 0x30) && (*word <= 0x39)) {
            //digit 
            isDigit = 1;
        }
        else if((*word >= 0x41) && (*word <= 0x5A)){
            //big letter
            checkFlag = 1;
        }
        else if((*word >= 0x61) && (*word <= 0x7A)){
            //small letter
            checkFlag = 1;
        }

        if(checkFlag == 1) {
            if((*word == 'a') || (*word == 'e') || (*word == 'i') || (*word == 'o') || (*word == 'u') ||
               (*word == 'A') || (*word == 'E') || (*word == 'I') || (*word == 'O') || (*word == 'U')) {
                oneVovel = true;
            }
            else {
                oneConsonant = true;
            }
        }

        if((checkFlag == 0) && (isDigit == 0)) {
            return false;
        }

        word++;
    }

    if((oneVovel == true) && (oneConsonant == true)) {
        return true;
    }

    return false;
}

//-----------------------------------------------------

bool isValid(const char* word) {
    if (word == NULL) {
        return false;
    }

    size_t length = 0;
    bool hasVowel = false;
    bool hasConsonant = false;
    bool hasDigit = false;

    while (*word) {
        char ch = *word;
        length++;

        if (isdigit(ch)) {
            hasDigit = true;
        } else if (isalpha(ch)) {
            if (strchr("aeiouAEIOU", ch)) {
                hasVowel = true;
            } else {
                hasConsonant = true;
            }
        } else {
            return false;
        }

        word++;
    }

    return (length >= 3) && hasVowel && hasConsonant;
}
