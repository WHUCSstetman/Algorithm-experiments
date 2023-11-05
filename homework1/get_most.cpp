#include <iostream>
#include <vector>
using namespace std;

double* get_most(vector<double> a)
{
    int length = a.size();
    int half = length/2;
    double* ans = new double[2];

    if(a[0] == a[length-1])
    {
        ans[0] = a[0];
        ans[1] = double(length);
        return ans;
    }
    else
    {
        if (a[half - 1] == a[half])
        {
            double times = 0;
            for (int i = 0; i < length; i++)
            {
                if (a[i] == a[half - 1])
                {
                    times++;
                }
            }
            vector<double> temp_arr1(a.begin(), a.begin() + half);
            vector<double> temp_arr2(a.begin() + half, a.end());
            double* temp1 = get_most(temp_arr1);
            double* temp2 = get_most(temp_arr2);

            if (temp1[1] > temp2[1] && temp1[1] > times)
            {
                delete[] ans;
                return temp1;
            }
            else if (temp2[1] > temp1[1] && temp2[1] > times)
            {
                delete[] ans;
                return temp2;
            }
            else
            {
                ans[0] = a[half - 1];
                ans[1] = times;
                return ans;
            }
        }
        else
        {
            vector<double> temp_arr1(a.begin(), a.begin() + half);
            vector<double> temp_arr2(a.begin() + half, a.end());
            double* temp1 = get_most(temp_arr1);
            double* temp2 = get_most(temp_arr2);

            if (temp1[1] > temp2[1])
            {
                delete[] ans;
                return temp1;
            }
            else if (temp2[1] > temp1[1])
            {
                delete[] ans;
                return temp2;
            }
        }
    }

    return ans;
}

int main()
{
    vector<double> a = {0, 1, 1,2,2,3, 3,4,4, 4, 5, 6};
    double* ans = get_most(a);
    cout << ans[0];
    delete[] ans;  // 使用完毕后释放内存
}
