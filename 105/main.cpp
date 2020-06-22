#include <QCoreApplication>
#include <iostream>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 int devInt(vector<int>& preorder, vector<int>& inorder)
 {
     for (int i = 0; i < inorder.size(); ++i)
     {
         if (preorder[0] == i)
         {
             return i;
         }
     }
 }
 TreeNode* buildTree(vector<int>& preorder,int preStart,int preEnd, vector<int>& inorder, int inoStart, int inoEnd)
 {
     if (preStart < preEnd)
     {
         return NULL;
     }
     int flag = devInt(preorder,inorder);

     TreeNode* root = new TreeNode(inorder[flag]);
     root->left = buildTree(preorder,preStart+1,flag,inorder,inoStart,flag-1);
     root->right = buildTree(preorder,flag+1,preEnd,inorder,flag+1,inoEnd);
     return root;
 }

 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
 {
     int preStart = 0,inoStart = 0;
     int preEnd = 0,inoEnd = preorder.size();
     TreeNode* root = buildTree(preorder,preStart, preEnd,  inorder,  inoStart,  inoEnd);
     return root;
 }
int main()
{
    string id = "the_legend_of_1900_magic_waltz/923b0fb622520f5e31207dc0c339639743cd77bd.flv";
    size_t pos = id.find_last_of("/");
//    if (std::string::npos != pos)
//    {
//        id = id.substr(pos+1);
//    }
//    cout<<"id:"<<id<<endl;
//    pos = id.find_last_of(".");


    if (std::string::npos != pos)
    {
        id = id.substr(0, pos);
    }
    cout<<"id: "<<id<<endl;
    return 0;

}
