bool isSubstring(const string& str1, const string& str2){
    return str1.find(str2) != string::npos;
}
bool isRotation(string& str1, string& str2){
    if(str1.size() != str2.size()) return false;
    string str = str2 + str2;
    return isSubstring(str, str1);
}
