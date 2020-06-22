#include <QCoreApplication>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left =1;
        int right = maxV(piles) + 1;

        //「搜索区间」变成左闭右闭
        while(left<=right)
        {
            int middle = (left+right)/2;
            if(canFinish(piles,middle,H))
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return left;
    //「搜索区间」变成左闭右开
    //         while (left < right) {
    //     // 防止溢出
    //     int mid = left + (right - left) / 2;
    //     if (canFinish(piles, mid, H)) {
    //         right = mid;
    //     } else {
    //         left = mid + 1;
    //     }
    // }
    // return left;
    }
    bool canFinish(vector<int > piles,int middle,int H)
    {
        int costTime = 0;
        for (auto n:piles)
        {
            costTime += n/middle + (n%middle == 0 ? 0:1);
        }
        return costTime <= H ? true : false;
    }
    int maxV(vector<int> piles)
    {
        int maxValue = 0;
        for (auto n:piles)
        {
            maxValue = max(n,maxValue);
        }
        return maxValue;
    }

};

int main(int argc, char *argv[])
{
    Solution A;
    vector<int> piles = {30, 11, 23, 4, 20};
    int H = 5;
    int result = A.minEatingSpeed(piles,H);
    cout<<result<<endl;
}
