#include <iostream>
#include<vector>

#include <algorithm>
using namespace std;




vector<vector<int>> threeSum2(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
    for (int k = 0; k < nums.size(); ++k) {
        if (nums[k] > 0) break;
        if (k > 0 && nums[k] == nums[k - 1]) continue;
        int target = 0 - nums[k];
        int i = k + 1, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] == target) {
                res.push_back({nums[k], nums[i], nums[j]});
                while (i < j && nums[i] == nums[i + 1]) ++i;
                while (i < j && nums[j] == nums[j - 1]) --j;
                ++i; --j;
            } else if (nums[i] + nums[j] < target) ++i;
            else --j;
        }
    }
    return res;
}

vector<vector<int>> threeSum1(vector<int>& nums) {
       vector<vector<int>> res;
       if(nums.size()<3)return res;
       sort(nums.begin(),nums.end());
       for (int i=0;i<nums.size();i++)
       {
           if(nums[i]>0)break;
           if(i!=0&&nums[i]==nums[i-1])continue;
           int left = i+1;
           int right = nums.size()-1;
           while(left<right)
           {
               int sum_ = nums[i]+nums[left]+nums[right];
               if(sum_==0)
               {
                   res.push_back(vector<int>{nums[i],nums[left],nums[right]});
                   left+=1;
                   right+=1;
                   while(left<right&&nums[left]==nums[left-1])left+=1;
                   while(right>left&&nums[right]==nums[right+1])right-=1;
               }
               else if(sum_<0)left+=1;
               else {
                   right-=1;
               }
           }
       }
       return res;
   }
vector<vector<int>> threeSum(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    if(nums.size()<3||*nums.begin()>0||*nums.end()<0)
    {
        return res;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>0)
            break;
        if(i>0&&nums[i]==nums[i-1]) continue;
        int flag = 0-nums[i];
        int j = i+1;
        int k = nums.size()-1;
        while(j<k)
        {
            if(nums[j]+nums[k]==flag)
            {
                res.push_back({nums[i],nums[j],nums[k]});
                while(j<k&&nums[j]==nums[j+1]) j++;
                while (j<k&&nums[k]==nums[k-1])k--;
                j++;
                k--;
            }
            else if(flag>nums[j]+nums[k]) {j++;}
            else {
                k--;
            }
        }
    }
    return res;
}


vector<vector<int>> threeSum4(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    if (nums.size()<3 || nums.back() < 0 || nums.front() > 0)
        return {};


    for(int i=0; i<nums.size()-2; i++) {
        if(i>0 && nums[i]==nums[i-1]) {
            continue;
        }

        int x = i + 1;
        int y = nums.size() - 1;
        while(x < y) {
            while(x>i+1 && nums[x]==nums[x-1]) {
                x++;
            }
            while(y<nums.size()-1 && nums[y]==nums[y+1]) {
                y--;
            }
            if(x==y || x>y) {
                break;
            }
            int sum = nums[x] + nums[y] + nums[i];
            if(sum == 0) {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[x]);
                temp.push_back(nums[y]);
                ans.push_back(temp);
                x++;
                y--;
            } else if(sum < 0) {
                x++;
            } else if(sum > 0) {
                y--;
            }
        }
    }
    return ans;

}
int main()
{
    vector<int> test = {0,0,0};
    vector<vector<int>> result = threeSum(test);
    std::cout<<result.size()<<std::endl;
    vector<vector<int>> result1 = threeSum1(test);
    std::cout<<result1.size()<<endl;
    vector<vector<int>> result4 = threeSum4(test);
    std::cout<<result4.size()<<endl;
}
