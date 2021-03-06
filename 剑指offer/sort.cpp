#include<iostream>
#include<string>
#include<functional>
#include<memory>
#include<map>
#include<unordered_map>
#include<direct.h>
#include<queue>
#include<stack>
#include<fstream>
#include<time.h>

using namespace std;

class solution_sort{
    public:
        virtual void sort(vector<int>& nums) = 0;
};

class solution_mergesort : public solution_sort{
    public:
        void sort(vector<int>& nums){
            mergesort(nums, 0, nums.size() - 1);
        }
    private:
        void mergesort(vector<int>& nums, int start, int end){
            if (start < end){
                int mid = start + ((end - start) >> 1);
                mergesort(nums, start, mid);
                mergesort(nums, mid + 1, end);
                merge(nums, start, mid, end);
            }
        }
        void merge(vector<int>& nums, int start, int mid, int end){
            vector<int> tmp(end - start + 1, 0);
            int i = start, j = mid + 1, m = mid, n = end;
            int k = 0;
            while (i <= m && j <= n){
                if (nums[i] < nums[j]){
                    tmp[k++] = nums[i++];
                }
                else{
                    tmp[k++] = nums[j++];
                }
            }
            while (i <= m){
                tmp[k++] = nums[i++];
            }
            while (j <= n){
                tmp[k++] = nums[j++];
            }
            for (int i = start; i <= end; ++i){
                nums[i] = tmp[i - start];
            }
        }
};

class solution_quicksort : public solution_sort{
    public:
        void sort(vector<int>& nums){
            quicksort(nums, 0, nums.size() - 1);
        }
    private:
        void quicksort(vector<int>& nums, int start, int end){
            if (start < end){
                int index = partition(nums, start, end);
                quicksort(nums, start, index - 1);
                quicksort(nums, index + 1, end);
            }
        }
        int partition(vector<int>& nums, int start, int end){
            int t = nums[start];
            while (start < end){
                while (start < end && nums[end] > t) --end;
                if (start < end){
                    nums[start++] = nums[end];
                }
                while (start < end && nums[start] <= t) ++start;
                if (start < end){
                    nums[end--] = nums[start];
                }
            }
            nums[start] = t;
            return start;
        }
};

class solution_heapsort : public solution_sort{
    public:
        void sort(vector<int>& nums){
            heap_sort(nums);
        }
    private:
        void adjustHead(vector<int>& nums, int i, int length){
            if (i <= (length - 1) /2 ){
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int max_pos = i;
                if (left < length && nums[left] > nums[max_pos]){
                    max_pos = left;
                }
                if (right < length && nums[right] > nums[max_pos]){
                    max_pos = right;
                }
                if (max_pos != i){
                    std::swap(nums[max_pos], nums[i]);
                    adjustHead(nums, max_pos, length);
                }
            }
        }
        void adjustHead2(vector<int>& nums, int i, int length){
            while (i <= (length - 1) / 2){
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                int max_pos = i;
                if (left < length && nums[left] > nums[max_pos]){
                    max_pos = left;
                }
                if (right < length && nums[right] > nums[max_pos]){
                    max_pos = right;
                }
                if (max_pos != i){
                    std::swap(nums[max_pos], nums[i]);
                    i = max_pos;
                }
                else{
                    break;
                }
            }
        }
        void buildHeap(vector<int>& nums){
            for (int i = nums.size() / 2 - 1; i >= 0; --i){
                adjustHead2(nums, i, nums.size());
            }
        }
        void heap_sort(vector<int>& nums){
            buildHeap(nums);
            for (int i = nums.size() - 1; i > 0; --i){
                std::swap(nums[0], nums[i]);
                adjustHead2(nums, 0, i);
            }
        }
};



int main(){
    const int N = ((1 << 15) - 1);
    vector<int> se(N, 0);
    int i = 0;
    std::generate(se.begin(), se.end(), [&i](){return i++; });
    std::random_shuffle(se.begin(), se.end());

    auto print = [](vector<int>& nums){
        for (auto n : nums){
            cout << n << " ";
        }
        cout << endl;

    };
    cout << "shuffle" << endl;
    //print(se);

    time_t st ,ed;


    // quick sort
    std::shared_ptr<solution_sort> sm(new solution_quicksort);
    st = clock();
    sm->sort(se);
    ed = clock();
    cout << "quick sort: use " << (ed - st)  << " ms" << endl;
    //print(se);

    std::random_shuffle(se.begin(), se.end());
    cout << "shuffle" << endl;
    //print(se);

    //merge sort
    sm.reset(new solution_mergesort);
    st = clock();
    sm->sort(se);
    ed = clock();
    cout << "merge sort: use " << (ed - st)  << " ms" << endl;
    //print(se);


    system("pause");
    return 0;
}
