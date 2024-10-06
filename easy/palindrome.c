bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int ch[10];
    int j = 0;
    while (x != 0) {
        ch[j] = x % 10;
        x /= 10;    
        ++j; 
    }
    for (int i = 0; i <= (j)/2-1; i++) {
        if (ch[i] != ch[j-i-1]) {
            return false;
        }
    }
    return true;
}