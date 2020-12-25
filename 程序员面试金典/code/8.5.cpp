class solutionparentheses{
    public:
        vector<string> genParrentheses(int n){
            vector<string> res;
            gen(res, "", 0, 0, n);
            return res;
        }
    private:
        void gen(vector<string>& res, string str, int left, int right, int n){
            if (left == n && right == n){
                res.push_back(str);
            }
            if (left < n){
                gen(res, str + "(", left + 1, right, n);
            }
            if (left > right){
                gen(res, str + ")", left, right + 1, n);
            }
        }
};
