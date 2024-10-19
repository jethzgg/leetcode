char* addBinary(char* a, char* b) {
    int max1 = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    int max = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    char *rs = (char*)malloc(max + 2);
    rs[max+1] = '\0';
    int carry = 0;
    int i = strlen(a) - 1, j = strlen(b) - 1;
    while (i >= 0 && j >= 0) {
        if (a[i] == '1' && b[j] == '1') {
            if (carry == 1) {
                rs[max] = '1';
            }
            else {
                rs[max] = '0';
                carry = 1;
            }
        }
        if (a[i] == '0' && b[j] == '0') {
            if (carry == 1) {
                rs[max] = '1';
                carry = 0;
            }
            else {
                rs[max] = '0';
            }
        }
        if ((a[i] == '1' && b[j] == '0') || (a[i] == '0' && b[j] == '1')) {
            if (carry == 1) {
                rs[max] = '0';
            }
            else rs[max] = '1';
        }
        max -= 1;
        i -= 1;
        j -= 1;
    }
    if (i >= 0) {
        while (i >= 0) {
            if (a[i] == '0') {
                if (carry == 1) {
                    rs[i+1] = '1';
                    carry = 0;
                }
                else {
                    rs[i+1] = '0';
                }
            }
            if (a[i] == '1') {
                if (carry == 1) {
                    rs[i+1] = '0';
                }
                else {
                    rs[i+1] = '1';
                }
            }
            
            i -= 1;
        }
    }
    if (j >= 0) {
        while (j >= 0) {
            if (b[j] == '0') {
                if (carry == 1) {
                    rs[j+1] = '1';
                    carry = 0;
                }
                else {
                    rs[j+1] = '0';
                }
            }
            if (b[j] == '1') {
                if (carry == 1) {
                    rs[j+1] = '0';
                }
                else {
                    rs[j+1] = '1';
                }
            }
            
            j -= 1;
        }
    }
    if (carry == 1) {
        rs[0] = '1';
    }
    else {
        int i = 0;
        while (i <= max1) {
            rs[i] = rs[i+1];
            i += 1;
        }
    }
    return rs;
}