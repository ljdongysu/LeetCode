class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        if(strs.size()==0)
            return s;
        if(strs.size()==1)
        {
            return strs[0];
        }
        int min_size = strs[0].length();
        for (int i=1;i<strs.size();i++)
        {
            if(strs[i].length()<min_size)
            {
                min_size = strs[i].length();
            }
            else
            {
                continue;
            }
        }
        
        for(int i=0;i<min_size;i++)
        {
            for (int j=1;j<strs.size();j++)
            {
                if(strs[0][i]==strs[j][i])
                {
                 if(j==strs.size()-1)
                {
                    s +=strs[0][i];
                }
                    continue;
                }
                else
                {
                    return s;
                }

            }
        }
        return s;
    }
};
