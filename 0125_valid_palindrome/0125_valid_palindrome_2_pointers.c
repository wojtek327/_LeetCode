bool CheckIfLowercaseLetter(const char val) {
    if(val >= 'a' && val <= 'z') {
        return true;
    }
    return false;
}

bool CheckIfUppercaseLetter(const char val) {
    if(val >= 'A' && val <= 'Z') {
        return true;
    }
    return false;
}

bool CheckIfDiggit(const char val) {
    if(val >= '0' && val <= '9') {
        return true;
    }
    return false;
}

bool isPalindrome(const char *s) {
    const char *start = s;
    const char *end = s;

    while (*end) {
        end++;
    }

    end--;
    while (start < end) {
        while (start < end && !((CheckIfLowercaseLetter(*start)) || (CheckIfUppercaseLetter(*start)) || (CheckIfDiggit(*start)))) {
            start++;
        }
        while (start < end && !((CheckIfLowercaseLetter(*end)) || (CheckIfUppercaseLetter(*end)) || (CheckIfDiggit(*end)))) {
            end--;
        }
        char c1 = (CheckIfUppercaseLetter(*start)) ? *start + 32 : *start;
        char c2 = (CheckIfUppercaseLetter(*end)) ? *end + 32 : *end;

        if (c1 != c2) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}
//------------------------------------------------------------------------------------------------
bool isPalindrome(const char *s) {
    const char *start = s;
    const char *end = s;

    while (*end) {
        end++;
    }

    end--;
    while (start < end) {
        while (start < end && !((*start >= 'a' && *start <= 'z') ||
        (*start >= 'A' && *start <= 'Z') || (*start >= '0' && *start <= '9'))) {
            start++;
        }
        while (start < end && !((*end >= 'a' && *end <= 'z') ||
        (*end >= 'A' && *end <= 'Z') || (*end >= '0' && *end <= '9'))) {
            end--;
        }
        char c1 = (*start >= 'A' && *start <= 'Z') ? *start + 32 : *start;
        char c2 = (*end   >= 'A' && *end <= 'Z')   ? *end   + 32 : *end;

        if (c1 != c2) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}
//--------------------------------------------------------------
bool isPalindrome(const char *s) {
    const char *start = s;
    const char *end = &s[strlen(s) - 1];

    while (start < end) {
        while (start < end && !((*start >= 'a' && *start <= 'z') || (*start >= 'A' && *start <= 'Z') || (*start >= '0' && *start <= '9'))) {
            start++;
        }
        while (start < end && !((*end   >= 'a' && *end <= 'z') || (*end >= 'A' && *end <= 'Z') || (*end >= '0' && *end <= '9'))) {
            end--;
        }
        char c1 = (*start >= 'A' && *start <= 'Z') ? *start + 32 : *start;
        char c2 = (*end   >= 'A' && *end <= 'Z')   ? *end   + 32 : *end;

        if (c1 != c2) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}
