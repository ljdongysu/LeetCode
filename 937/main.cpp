#include <QCoreApplication>
#include<vector>
#include<iostream>
using namespace std;

static bool cmp(string a,string b)
{
    int aNum = a.find(' ');
    int bNum = b.find(' ');
    if (a.substr(aNum+1) == b.substr(bNum+1))
    {
        return a<b;
    }
    return a.substr(0,aNum) < b.substr(0,bNum);
}

static bool cmpvector(vector<string> a,vector<string> b)
{
    return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
}

vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> digitLog;
    vector<vector<string>> letterLog;
    for (int i = 0; i < logs.size(); ++i)
    {
        int num = logs[i].find(' ');
        if (logs[i][num+1] >= '0' && logs[i][num+1] <= '9')
        {
            digitLog.push_back(logs[i]);
        }
        else
        {   vector<string> a;
            a.push_back(logs[i].substr(0,num));
            a.push_back(logs[i].substr(num+1));
            letterLog.push_back(a);
        }
    }
    sort(letterLog.begin(),letterLog.end(),cmpvector);
    vector<string> letter;
    for (int i = 0; i < letterLog.size(); ++i)
    {
        letter.push_back(letterLog[i][0]+' '+letterLog[i][1]);
        cout<<"letter: "<<letterLog[i][0]+' '+letterLog[i][1]<<" ";
    }
    cout<<endl;
    for (auto s: digitLog)
    {
        letter.push_back(s);
    }
    return letter;
}
int main()
{
vector<string> a = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
a = reorderLogFiles(a);
for (auto s: a)
{
    cout<<s<<" ";
}
cout<<endl;


}
