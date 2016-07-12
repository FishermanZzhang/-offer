class solution{
    public:
        char fisrtOnceChar(const string& str){
            char nums[256] = { 0  };
            for (auto ch : str){
                ++nums[ch];
            }
            for (auto ch : str){
                if (nums[ch] == 1)
                    return ch;
            }
            return 0;
        }
};
