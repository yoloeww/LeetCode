class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string newstr1,newstr2;
        for(int i = 0;i <word1.size();i++)
        {
            newstr1 += word1[i];
        }
        for(int i = 0;i <word2.size();i++)
        {
            newstr2 += word2[i];
        }
        if(newstr1 == newstr2)
        return true;
        else
        return false;
    }
};
