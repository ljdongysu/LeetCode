#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
bool checkInclusion(string t, string s)
{
    int left = 0, right = 0;
    int len = t.size();
    int valid = 0;
    unordered_map<char, int> need, window;
    for (char d : t) need[d]++;
    while(right < s.size())
    {
        char d = s[right];
        std::cout<<d<<endl;
        if(need.count(d))
        {
            window[d]++;
            if(need[d] == window[d])
            {
                valid++;
            }
        }
        right++;
//每次增加到字串长度后就会取判断是否为字串，实则true否则减小长度继续下次增加长度迭代
//         while	(right	-	left	>=	t.size())	{
//             //	在这里判断是否找到了合法的子串
//            if	(valid	==	need.size())
        while(valid == need.size())
        {
            if(right - left == len)
            {
                return true;
            }
            char d = s[left];
            cout<<"left: "<<left<<",  right: "<<right<<", valid: "<<valid<<", need.size:  "<<need.size()<<endl;

            left++;
            if(need.count(d))
            {
                if(need[d] == window[d])
                {
                    valid--;
                }
                window[d]--;
            }
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    string s1 = "ab";
    string s2 = "eidboaooo";
    cout<<checkInclusion(s1,s2)<<endl;
    return 0;
}
