#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
int n;
cin>>n;
vector <vector <int>> f(n);
vector<int>::iterator it;
for (int i=0;i<n;++i)
{
    int n2;
    cin>>n2;
    //vector <int> temp;
    for (int j=0;j<n2;++j)
    {
        int t;
        cin>>t;
        f.at(i).push_back(t);
    }
}
bool flag[n];
for(int g=0;g<n;++g)
    flag[g]=false;
vector <int> days;
set <int> aware;
int test;
cin>>test;
for (int i=0;i<test;++i)
{
    int p;
    cin>>p;
    int gg=-1;
    while(n!=aware.size())
    {
            ++gg;
            vector <int> temp;
            if (gg==0)
            {
            temp=f.at(p);
            // set_difference(temp.begin(),temp.end(),aware.begin(),aware.end(),dif.begin());
            int a,b;
            a=aware.size();
            aware.insert(temp.begin(),temp.end());
            b=aware.size();
            // aware.insert(dif.begin(),dif.end());
            days[gg]=b-a;
           // cout<<aware.size()<<endl;
            flag[p]=true;
            }
            else
            {
                for (int z=0;z<f.at(p).size();++z)
                {
                    if(flag[f.at(p).at(z)]==false)
                    {
                        flag[f.at(p).at(z)]=true;
                        temp=f.at(f.at(p).at(z));
                        a=aware.size();
                        aware.insert(temp.begin(),temp.end());
                        b=aware.size();
                        days.at(gg)=b-a;
                    }

                }
            }
    }
    int mx=0; //ماکزیمم
    int an=0; //اندیس
    for (int y=0;y<days.size();++y)
    {
        if (mx<=days[y])
        {
            mx=days[y];
            an=y;
        }
    }
    cout<<an<<" "<<mx<<endl;
}
    return 0;
}
