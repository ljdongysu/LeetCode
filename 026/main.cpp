#include <iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    for(auto iter_i = nums.begin();iter_i!=nums.end();iter_i++)
    {
        if(iter_i+1!=nums.end()&&*iter_i==*iter_i)
        {
            nums.erase(iter_i);
        }
    }
    return nums.size();
}

//class A
//{
//public:
//    A() {}
//    virtual void show_name(){cout<<"this in class A";}
//};
//class B: public A
//{
//public:
//    B() {}
//    void show_name(){cout<<"this in class B";}
//};
int main()
{
    vector<int> test1 = {1,2};
    cout<<removeDuplicates(test1);
    for(int i=0;i<test1.size();i++)
        cout<<test1[i];

//    B adam;
//    adam.show_name();
//    A *psc = &adam;
//    psc->show_name();

}
