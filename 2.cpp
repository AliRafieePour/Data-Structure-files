#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int ts=1;
vector<int> split(vector<int> ctfs, int a, int b)
{
    int bcopy=b;
    int devide;
    devide=a/2;
    if (a==1)
    {
        return ctfs;
    }
    if (ts==b)
    {
        return ctfs;
    }
    ts=ts+2;
    vector <int> p;
    vector <int> q;
    vector <int> pp;
    vector <int> teke1;
    vector <int> teke2;
    for (int i=0;i<devide;++i)
    {
        p.push_back(ctfs.at(i));
    }
    for (int i=devide;i<a;++i)
    {
        q.push_back(ctfs.at(i));
    }
    pp=q;
    pp.insert(pp.end(),p.begin(),p.end());
    if (ts != b)
    {
        teke1=split(p,p.size(),bcopy);
        teke2=split(q,q.size(),bcopy);
        vector <int> yy;
        yy=teke1;
        yy.insert(yy.end(),teke2.begin(),teke2.end());
        return yy;
    }
    else
    {
        return pp;
    }
}
int main()
{
    vector <int> ctfs;
    vector <int> copy;
    int a,b;
    cin>>a>>b;
    if (b%2==0)
    {
         cout<<-1<<endl;
    }
    else
    {
        for (int i=1;i<=a;++i)
        {
            ctfs.push_back(i);
        }
        if (b==1)
        {
            for (int i=0;i<a;++i)
            {
                cout<<ctfs.at(i)<<" ";
            }
        }
        else
        {
            copy=split(ctfs,a,b);
            for (int i=0;i<a;++i)
            {
                cout<<copy.at(i)<<" ";
            }
        }
    }
    return 0;
}
