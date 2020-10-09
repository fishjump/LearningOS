#include <iostream>

using namespace std;

class A
{
public:
    const int a = 1;

private:
    const int b = 2;
};

struct B
{
    int a;
    int b;
};

int main()
{
    A a;
    ((B *)&a)->b = 3;
    cout << "B::a = " << ((B *)&a)->a << " B::b = " << ((B *)&a)->b << endl;
}
