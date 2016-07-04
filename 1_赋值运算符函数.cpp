ass CMyString{
    public:
        CMyString(char* pData = NULL);
        CMyString(const CMyString& str);
        ~CMyString()
            CMyString& operator=(const CMyString& str);
    private:
        char* m_pData;

}

//m1:
CMyString& CMyString::operator = (const CMyString& str){
    if(this == &str){
        return str;
    }
    delete m_pData;
    m_pData = NULL;
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
    return *this;
}

//m2:
CMyString& CMyString::operator = (const CMyString& str){
    if(this == &str){
        return *this;
    }
    CMyString tmp(str);
    std::swap(tmp.m_pData, this->m_pData);
    return *this;
}
