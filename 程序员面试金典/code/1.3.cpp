void removeDuplicate(char* str){
    if (str == NULL) return;
    bool d[256] = { false  };
    char* p = str;
    d[*p] = true;
    ++p;
    int tail = 1;
    while (*p){
        if (!d[*p]){
            str[tail++] = *p;
        }
        d[*p] = true;
        ++p;
    }
    str[tail] = '\0';
}
