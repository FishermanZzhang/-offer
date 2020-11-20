class solution34{
    public:
        int getKthUglyNumber(int k){
            vector<int> record(k + 1);
            record[0] = 1;
            int index2 = 0;
            int index3 = 0;
            int index5 = 0;
            for (int i = 1; i <= k; ++i){
                int t = _3min(record[index2] * 2, record[index3] * 3, record[index5] * 5);
                if (t == record[index2] * 2) ++index2;
                if (t == record[index3] * 3) ++index3;
                if (t == record[index5] * 5) ++index5;
                record[i] = t;
            }
            return record[k];
        }
    private:
        int _3min(int x, int y, int z){
            return std::min(x, std::min(y, z));
        }
};
