class SolutionAllSet{
public:
	vector<vector<int>> subsets(vector<int>& set){
		gen(0, set);
		return res_;
	}
private:
	void gen(int pos,vector<int>& set){
		res_.push_back(record_);
		for (int i = pos; i < set.size(); ++i){
			record_.push_back(set[i]);
			gen(i + 1, set);
			record_.pop_back();
		}
	}
private:
	vector<vector<int>> res_;
	vector<int> record_;
};

class SolutionAllSet2{
public:
	vector<vector<int>> subsets(vector<int>& set){
		std::sort(set.begin(), set.end());
		gen(0, set);
		return res_;
	}
private:
	void gen(int pos, vector<int>& set){
		res_.push_back(record_);
		for (int i = pos; i < set.size();){
			record_.push_back(set[i]);
			gen(i + 1, set);
			record_.pop_back();
			int j = i + 1;
			while (j < set.size() && set[j] == set[i]) ++j;
			i = j;
		}
	}
private:
	vector<vector<int>> res_;
	vector<int> record_;
};
