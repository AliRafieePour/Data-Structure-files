#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;

vector<double> ctfs;
double calcul(double irr,int t)
{
    double sum=0;
    for (int i=0;i<=t;++i)
    {
        sum+=(ctfs.at(i)/pow((1+irr),i));
    }
    return sum;

}
int main()
{
    int n; // tedade T ya andis CTF
    int num;
    double d;
    double result;
    int devides=0;
    while (cin>>n)
    {
        double a=-0.99999999;
        double b=10000000;
        ctfs.clear();
        for (int i=0;i<=n;++i)
        {
            cin>>num;
            ctfs.push_back(num);
        }
        while (a<=b && devides<100000)
        {
            ++devides;
            d=(a+b)/2.0;
            result=calcul(d,n);
            if (result<0)
            {
                b=d;
            }
            else
            {
                a=d;
            }
        }
        cout<<setprecision(2);
        cout<<setfill('0');
        cout<<d<<endl;

    }
    return 0;
}
