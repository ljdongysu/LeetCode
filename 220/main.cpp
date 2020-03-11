#include <iostream>
#include<vector>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(nums.size()<2)
        return false;
    for(int i=0;i<nums.size()-k;i++)
    {
        for(int j=i+1;j<=i+k;j++)
        {
            long nums_j=nums[j];
            long nums_i = nums[i];
            long aa  = nums_j-nums_i;
            if((aa>0?aa:(0-aa))<=t)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {7,1,3};
    cout<<containsNearbyAlmostDuplicate(nums,2,3);
}
