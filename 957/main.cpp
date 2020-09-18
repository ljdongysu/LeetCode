
#include <QCoreApplication>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    //暴力解法超时  正确解法：考虑到固定长度8以及可能的天数太大，考虑到可能存在循环，然后用hashMap或TreeMap先存数组的情况，
    //当出现重复时候就用N对目前Map的中(上次N-当前N)取余后在循环到N=0就出现了结果还有人计算出了循环为1，7，14这三种情况，所以进行对14取余在计算

     //暴力解法超时
    vector<int> NDaysCells(vector<int> A,int N)
    {
        if ( A.empty())
        {
            return A;
        }
        else if(A.size() < 2)
        {
            A[0] = 0;
            A[A.size()-1] = 0;
            return A;
        }
        vector<int > B(A);

        for(int i = 0; i<N; ++i)
        {
            for (int j = 1; j < A.size() - 1; ++j)
            {
                if (A[j - 1] != A[j + 1])
                {
                    B[j] = 0;
                }
                else
                {
                    B[j] = 1;
                }
            }
            B[0] = B[A.size()-1] = 0;
            B.swap(A);
        }
        return B;
    }
};
int main(int argc, char *argv[])
{
    vector<int> A = {1,0,0,1,0,0,1,0};
    Solution C;
    vector<int> d = C.NDaysCells(A,1000000000+1);
    for (auto a:d)
    {
        cout<<a<<endl;
    }
    return 0;
}
