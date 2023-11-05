#include<iostream>
#include<vector>
using namespace std;

int ternary_search(const vector<double>& a, double x)
{
    int length = a.size();
    if(length<3)
    {
        if(x==a[0])
        {
            return 0;
        }
        else if(length == 2)
        {
            if(x==a[1])
            {
                return 1;
            }
        }
        else
        {
            cout<<"Not found";
            return -1;
        }
    }
    int l1 = length / 3;
    int l2 = (length * 2) / 3;
    if(x <= a[l1 - 1] && x >= a[0])
    {
        vector<double> temp(a.begin(), a.begin() + l1);
        return ternary_search(temp, x);
    }
    else if(x > a[l1 - 1] && x <= a[l2 - 1])
    {
        vector<double> temp(a.begin() + l1, a.begin() + l2);
        return ternary_search(temp, x) + l1;
    }
    else if(x > a[l2 - 1] && x <= a[length - 1])
    {
        vector<double> temp(a.begin() + l2, a.end());
        return ternary_search(temp, x) + l2;
    }
    else
    {
        cout << "Not found" << endl;
        return -1;
    }
}

int main()
{
    vector<double> test = {1.0, 3.0, 5.0, 7.0, 9.0, 15.0, 21.0};
    cout << ternary_search(test, 5.0) << endl;
    cout << ternary_search(test, 4.0) << endl;
}
