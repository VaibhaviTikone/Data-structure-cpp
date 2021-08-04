#include<iostream>
#include<thread>
using namespace std;

void fun1(int n)
{
    for(int i=0;i<n;i++)
        cout<<i<<endl;
}

void fun2(int n)
{
    for(int i=0;i<n;i++)
        cout<<i<<i<<endl;
}

class thread_obj{
    public:
    void operator()(int n)
    {
        cout<<"Inside thread_obj class function\n";
        for(int i=0;i<n;i++)
            cout<<i+i<<endl;
    }
};

int main()
{
    cout<<"Exectuting threads\n";
    thread t1(fun1,5);
    thread t2(thread_obj(),3);
    t1.join();
    cout<<"Testing in between\n";
    t2.join();
    return 0;
}