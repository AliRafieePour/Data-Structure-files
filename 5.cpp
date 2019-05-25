#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include <list>
using namespace std;
void maxi(vector<int>a)
{
    int m=0;int n=0;
    for (int i=0;i<a.size();++i)
    {
        if (m<=a.at(i))
        {
            m=a.at(i);
            n=i;
        }
    }
    cout<<m<<" "<<n<<endl;
}
bool check(bool a[],int n)
{
    int c=0;
    for (int i=0;i<n;++i)
    {
        if (a[i]==true)
            ++c;
    }
    if (c==n)
        return true;
    else
        return false;
}
int main()
{
    int d=0;
    vector <int> days;
    days.push_back(1);
    queue <int> q;
    int n;
    cin>>n;
    bool *lis=new bool(n);
    for (int o=0;o<n;++o)
        lis[o]=false;
    vector<vector<int>> data(n);
    for (int i=0;i<n;++i)
    {
        int n2;
        cin>>n2;
        for (int r=0;r<n2;++r)
        {
            int y;
            cin>>y;
            data.at(i).push_back(y);
        }
    }
    int x;
    cin>>x;
    vector <int> temp;

    for (int k=0;k<x;++k)
    {
        int cc=0;
        int gg;
        cin>>gg;
        q.push(gg);
        lis[gg]=true;
        while (!check(lis,n))
        {
            temp=data.at(q.front());
            for (int yy=0;yy<temp.size();++yy)
            {
                if (!lis[temp.at(yy)])
                {
                    ++cc;
                    q.push(temp.at(yy));
                    lis[temp.at(yy)]=true;
                }
            }
            ++d;
            days.push_back(cc);;
            q.pop();
        }
        maxi(days);
        days.clear();
        temp.clear();
        for (int g=0;g<q.size();++g)
        {
            q.pop();
        }
        for (int qqq=0;qqq<n;++qqq)
            lis[qqq]=false;

    }
    return 0;
}
