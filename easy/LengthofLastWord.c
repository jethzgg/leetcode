int lengthOfLastWord(char* s) {
    int i = strlen(s)-1;
    int count = 0;
    while (s[i] == ' ') {    
        i -= 1;
        if (i < 0) return count;
    }
    while (i >= 0) {
        if (s[i] == ' ') break;
        if (s[i] != ' ') {
            count += 1;
            i -= 1;
        }
    }
    return count;
}