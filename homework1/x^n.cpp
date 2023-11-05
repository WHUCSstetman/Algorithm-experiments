#include <iostream>
using namespace std;
double get_ans(double x,int n)
{
    if (n==0)
    {
        return 1;
    }
    else if(n==1)
    {
        return x;
    }
    else if(n<0)
    {
        x = 1/x;
        n = -n;
    }
    if (n%2==0)
    {
        int half =0;
        half = get_ans(x,n/2);
        return half*half;
    }
    else if(n%2!=0)
    {
        int half =0;
        half = get_ans(x,n/2);
        return half*half*x;
    }
}
int main()
{
   cout<<get_ans(2,5);
}