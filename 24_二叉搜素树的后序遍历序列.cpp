// no idea ,has glance it
class solution_24{
public:
    bool verifySequenceOfBST(vector<int>& sequence){
        return verifySequenceOfBST(sequence, 0, sequence.size() - 1);
    }
    bool verifySequenceOfBST(vector<int>& sequence, int start, int end){
        if (start >= end) return true;
        int rootval = sequence[end];
        int index = findFitstMoreThanToot(sequence, start, end - 1, rootval);
        bool flag = verifyMoreThanToot(sequence, index, end - 1, rootval);
        if (flag == false){
            return false;
        }
        flag = verifySequenceOfBST(sequence, start, index - 1);
        if (flag == false){
            return false;
        }
        flag = verifySequenceOfBST(sequence, index, end - 1);
        return flag;
    }
private:
    int findFitstMoreThanToot(vector<int>& sequence, int start, int end, int val){
        return std::find_if(sequence.begin() + start, sequence.begin() + end + 1, [val](int x){return x > val; }) - sequence.begin();
    }
    bool verifyMoreThanToot(vector<int>& sequence, int start, int end, int val){
        //auto pos = std::find_if(sequence.begin() + start, sequence.begin() + end + 1, [val](int x){return x < val; });
        return std::find_if(sequence.begin() + start, sequence.begin() + end + 1, [val](int x){return x < val; }) == sequence.begin() + end + 1;
    }
};
