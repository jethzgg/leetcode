bool isValid(char* s) {
    int j = 0;
    char c[strlen(s)];
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ')' && (j == 0)) return false;
        if (s[i] == ']' && (j == 0)) return false;
        if (s[i] == '}' && (j == 0)) return false;
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            c[j] = s[i];
            ++j;
        }
        else if (s[i] == ')' && c[j-1] == '(') {
            c[j-1] = '\0';
            --j;
        }
        else if (s[i] == ']' && c[j-1] == '[') {
            c[j-1] = '\0';
            --j;
        }else if (s[i] == '}' && c[j-1] == '{') {
            c[j-1] = '\0';
            --j;
        }
        else return false;  
    }
    if (strlen(c) == 0) return true;
    return false;
}