#include <QCoreApplication>
#include <queue>
#include <iostream>
using namespace std;
class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        if (Q.size()==0)
            Q.push(t);
        else
        {
            Q.push(t);
            while(t - Q.front()>3000)
                Q.pop();
            }
        return Q.size();


    }
    private:
        queue<int> Q;

};
int main(int argc, char *argv[])
{
queue<int > a;
a.push(1);
cout<<a.front()<<endl;
a.push(2);
cout<<a.front()<<endl;;

a.push(3);
cout<<a.front()<<endl;;

//cout<<a<<endl;
a.pop();
cout<<a.front();
return 0;
}
