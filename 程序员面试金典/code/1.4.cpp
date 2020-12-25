bool isAnagram(string& str1, string& str2){
    if (str1.size() != str2.size()) return false;
    int len = str1.size();
    int record[256] = { 0  };
    for (size_t i = 0; i < len; ++i){
        ++record[str1[i]];
        --record[str2[i]];
    }
    for (int i = 0; i < 256; ++i){
        if (record[i] != 0) return false;
    }
    return true;
}
