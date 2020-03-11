#include <QCoreApplication>
#include<iostream>
#include<vector>
using namespace std;
void sortOddEven(vector<int> &testVec);
int main(int argc, char *argv[])
{
    vector<int > Imput = {4,2,5,7};
    sortOddEven(Imput);
    return 0;
}

void sortOddEven(vector<int> &testVec)
{
    vector<int > odd;
    vector<int > even;
    for (int i =0 ; i < testVec.size(); i = i+2 )
    {
        if (testVec[i] % 2 != 0)
        {
            odd.push_back(i);
        }

        if(testVec[i+1] %2 ==0)
        {
            even.push_back(i+1);
        }
    }

    for (size_t i = 0; i < odd.size(); ++i)
    {
        int temp = testVec[odd[i]];
        testVec[odd[i]] = testVec[even[i]];
        testVec[even[i]] = temp;
    }
}
