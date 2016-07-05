class solution{
    public:
        //length 字符长的总容量
        //length = INT_MAX;
        void replaceBlank(char* const str, int length){
            char* p = str;
            int numblack = 0;
            int numotherchars = 0;
            while(*p){
                if(*p == ' ') ++numblack;
                else ++numotherchars;
                ++p;
            }
            int numorigian = numblack + numotherchars;
            int numfinal = numblack * 3 + numotherchars;
            if(numfinal <= numorigian)
                return;
            assert(numfinal <= length);
            str[numfinal] = '\0';
            --numorigian;
            --numfinal;
            while(numfinal > numorigian){
                if(str[numorigian] == ' '){
                    str[numfinal--] = '0';
                    str[numfinal--] = '2';
                    str[numfinal--] = '%';
                }
                else{
                     str[numfinal--] = str[numorigian];
                }
                --numorigian;
            }
        }
};
