class solutionmerge{
    public:
        void merge(int* a, int& lena, int* b, int lenb){
            int len = lena + lenb;
            --lena, --lenb;
            for (int i = len - 1; len >= 0 && lenb >= 0 && lena >= 0; --i){
                if (a[lena] < b[lenb]){
                    a[i] = b[lenb--];
                }
                else{
                    a[i] = a[lena--];
                }
            }
            if (lenb >= 0){
                for (; lenb >= 0; --lenb){
                    a[lenb] = b[lenb];
                }
            }
            lena = len;
        }
};
