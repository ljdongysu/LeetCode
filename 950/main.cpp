//#include <QCoreApplication>
#include <iostream>
#include <vector>
 #include   <algorithm>
#include <queue>
void swapBE(std::vector<int> & vetorC)
{
    if (vetorC.size()<2)
    {;}
    std::swap(vetorC[0],vetorC[vetorC.size()-1]);
}
std::vector<int> Card(const std::vector<int> & vectorC)
{
    std::vector<int> NewV;
    for (int i = vectorC.size() -1; i >= 0; --i)
    {
        if (NewV.size() < 2 )
        {
            NewV.insert(NewV.begin(),vectorC[i]);
            continue;
        }
        NewV.insert(NewV.begin(),NewV[NewV.size() - 1]);
        NewV.pop_back();
        NewV.insert(NewV.begin(),vectorC[i]);
    }
    return NewV;
}
void CardSJTX(const std::vector<int> & vectorC, std::vector<int> &NewV)
{
    std::queue<int> q;
    NewV.resize(vectorC.size());
    for (int i = 0; i < vectorC.size(); ++i)
    {
        q.push(i);
    }
    for (int i = 0; i < vectorC.size(); ++i)
    {
        int index = q.front();
        q.pop();
        NewV[index] = vectorC[i];
        int next = q.front();
        q.pop();
        q.push(next);
    }

}
int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    std::vector<int> vectorC{17,13,11,2,3,5,7};

    std::sort(vectorC.begin(),vectorC.end());
    std::vector<int> NewV;
//    NewV = Card(vectorC);
    CardSJTX(vectorC,NewV);


    for (int i = 0;i < NewV.size(); ++i)
        std::cout<<NewV[i]<<" ";

    return 0;
}
