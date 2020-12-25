
bool isUnique(string& str){
    if (str.size() > 256) return false;
    int nums[256] = { 0  };
    for (auto ch : str){
        if (nums[ch] >= 1){
            return false;
        }
        ++nums[ch];
    }
    return true;
}
