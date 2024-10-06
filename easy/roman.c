int romanToInt(char* s) {
    int *roman = (int *)malloc(sizeof(int) * 15);
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case 'I':
                roman[i] = 1;
                break;
            case 'V':
                roman[i] = 5;
                break;
            case 'X':
                roman[i] = 10;
                break;
            case 'L':
                roman[i] = 50;
                break;
            case 'C':
                roman[i] = 100;
                break;
            case 'D':
                roman[i] = 500;
                break;
            case 'M':
                roman[i] = 1000;
                break;
        }
    }
    int last = roman[0];
    int i = 0, sum = 0, temp = roman[0];
    while (i < strlen(s)) {
        
        if (roman[i] == last && i != 0) {
            temp += roman[i];
            last = roman[i];
        } 
        else if (roman[i] > last) {
            temp = roman[i] - temp;
            last = roman[i];
        }
        else if (roman[i] < last) {
            sum += temp;
            last = roman[i];
            temp = roman[i];
        }
        printf("%d %d %d %d\n",roman[i],last,temp,sum);
        ++i;
    }
    if (temp > 0) sum += temp;
    return sum;
}