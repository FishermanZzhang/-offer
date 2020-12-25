class Solutionpermutations{
public:
	vector<string> permutation(string& str){
		vector<string> res;
		gen(res, 0, str);
		return res;
	}
private:
	void gen(vector<string>& res, int pos, string& str){
		if (pos == str.size()){
			res.push_back(str);
		}
		else{
			for (int i = pos; i < str.size(); ++i){
				if (!swaped(str,i, pos)) continue;
				std::swap(str[i], str[pos]);
				gen(res, pos + 1, str);
				std::swap(str[i], str[pos]);
			}
		}
	}
	bool swaped(string& str, int i, int pos){
		for (; pos < i; ++pos){
			if (str[i] == str[pos]) return false;
		}
		return true;
	}
};


class Solutionpermutations2{
public:
	vector<string> permutation(string& str){
		std::sort(str.begin(), str.end());
		vector<string> res;
		do{
			res.push_back(str);
		} while (nextperm(str));
		return res;
	}
	bool nextperm(string& str){
		int pos = str.size() - 2;
		for ( ; pos >= 0; --pos){
			if (str[pos] < str[pos + 1])
				break;
		}
		if (pos < 0) return false;
		int pos2 = str.size() - 1;
		for (; pos2 > pos; --pos2){
			if (str[pos2] > str[pos])
				break;
		}
		std::swap(str[pos2], str[pos]);
		std::reverse(str.begin() + pos + 1, str.end());
		return true;
	}
};
