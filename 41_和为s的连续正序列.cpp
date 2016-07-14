class solution41_2{
public:
    vector<pair<int, int>> findContinueSequence(int sum){
        vector<pair<int, int>> res;
        int left = 1;
        int index = 1;
        int t = 0;
        int pos = ((sum + 1) >> 1);
        while (index < sum){
            t += index;
            while (t > sum){
                t -= left;
                ++left;
            }
            if (t == sum){
                res.emplace_back(make_pair(left, index));
                t -= left;
                ++left;
            }
            ++index;
        }
        return res;
    }
private:
};
