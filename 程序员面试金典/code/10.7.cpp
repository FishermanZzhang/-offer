class solutionUglyNumber{
    public:
        bool isUgly(int n){
            while (n % 3 == 0) n /= 3;
            while (n % 5 == 0) n /= 5;
            while (n % 7 == 0) n /= 7;
            return n == 1;
        }
        vector<int> uglys(int k){
            vector<int> res;
            res.push_back(1);
            int pos3 = 0;
            int pos5 = 0;
            int pos7 = 0;
            for (int i = 1; i < k; ++i){
                int x = _3min(res[pos3] * 3, res[pos5] * 5, res[pos7] * 7);
                res.push_back(x);
                if (x == res[pos3] * 3) ++pos3;
                if (x == res[pos5] * 5) ++pos5;
                if (x == res[pos7] * 7) ++pos7;
            }
            return res;
        }
        int ugly(int k){
            vector<int> res;
            res.push_back(1);
            int pos3 = 0;
            int pos5 = 0;
            int pos7 = 0;
            for (int i = 1; i < k; ++i){
                int x = _3min(res[pos3] * 3, res[pos5] * 5, res[pos7] * 7);
                res.push_back(x);
                if (x == res[pos3] * 3) ++pos3;
                if (x == res[pos5] * 5) ++pos5;
                if (x == res[pos7] * 7) ++pos7;
            }
            return res[res.size() - 1];
        }
    private:
        int _3min(int x, int y, int z){
            return std::min(x, std::min(y, z));
        }
};
