void reverse(char* str){
    if (str == NULL) return;
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i){
        std::swap(str[i], str[len - 1 - i]);
    }
}
