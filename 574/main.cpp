#include <QCoreApplication>
#include <vector>
#include<iostream>
using namespace std;
int findCircleNum(vector<vector<int>>& M) {
    int N = M.size();
    int total_N = N;
    for (int i =0;i<N;i++)
        for(int j =i+1;j<N;j++)
        {if(M[i][j])
                total_N-=1;
            cout<<i<<","<<j<<endl;
    }
    return total_N;
}
int main()
{
    vector<vector<int>> M(3,vector<int>(3,1));
    int result = findCircleNum(M);
    cout<<result<<endl;
}
