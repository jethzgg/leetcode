int strStr(char* haystack, char* needle) {
    int index = -1;
    if (strlen(needle) > strlen(haystack)) return -1;
    else if (strlen(needle) == strlen(haystack)) {
        for (int i = 0; i< strlen(needle); i++) {
            if (needle[i] != haystack[i]) return -1;
        }
        return 0;
    }
    else {
        for (int i = 0; i <= strlen(haystack) - strlen(needle); i++) {
            if (haystack[i] == needle[0]) {
                printf("%c %c\n",haystack[i], needle[0]);
                if (strlen(needle) == 1) return i;
                int count = 0;
                for (int j = 0; j < strlen(needle); j++) {
                    if (haystack[i+j] == needle[j]) {
                        count += 1; 
                    }
                }
                if (count == strlen(needle)) {
                    return i;
                    break;
                }
            }
        }
    }
    return index;
}