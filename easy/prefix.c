char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char *emptyString = (char *)malloc(1);
        emptyString[0] = '\0';
        return emptyString;
    }

    if (strsSize == 1) {
        return strs[0];
    }

    int index = 0;
    int minLen = strlen(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < minLen) {
            index = i;
            minLen = len;
        }
    }
    if (minLen == 0) {
        return "";
    }
    char *prefix = (char *)malloc((minLen + 1) * sizeof(char));
    for (int i = 0; i < strlen(strs[index]); i++) {
        prefix[i] = strs[index][i];
    }
    prefix[minLen] = '\0';
    for (int i = 0; i < strsSize; i++) {
        for (int j = minLen-1; j >= 0; j--) {
            if (prefix[j] != strs[i][j]) {
                prefix[j] = '\0';
            }
        }
    }
    
    for (int i = 0; i < minLen; i++) {
        if (prefix[i] == '\0') {
            prefix[i] = '\0';
        }
    }
    return prefix;
}