void replaceSpace(char* str){
    // suppose : str = new char[INT_MAX]
    int spacenum = 0;
    int allnum = 0;
    char* p = str;
    while (*p){
        ++allnum;
        if (*p == ' ') ++spacenum;
        ++p;
    }
    int newlen = allnum + 2 * spacenum;
    str[allnum + 1] = '\0';
    for (; newlen >= 0 && newlen > allnum; --allnum){
        if (str[allnum] == ' '){
            str[newlen--] = '0';
            str[newlen--] = '2';
            str[newlen--] = '%';
        }
        else{
            str[newlen--] = str[allnum];
        }
    }
}
