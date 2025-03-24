int strStr(char* haystack, char* needle) {
    if (*needle == '\0') { return 0; }

    char *h = haystack;

    while (*h != '\0') {
        char *temp_h = h;
        char *temp_n = needle;

        while (*temp_h != '\0' && *temp_n != '\0' && *temp_h == *temp_n) {
            temp_h++;
            temp_n++;
        }

        if (*temp_n == '\0') {
            return h - haystack;
        }

        h++;
    }

    return -1;
}
