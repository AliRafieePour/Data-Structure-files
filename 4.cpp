#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string.h>
#include <string>
#include <list>
class graph
{
private:
    int v;
    list <int> *ver;
public:
    graph(int v)
    {
        this.v=v;
        ver=new list[v];
    }
    void bfs(int n)
    {
        int x;
        bool seen[b];
        int levels[v];
        memset(seen,0,sizeof(seen));
        int cnt[v]={0};
        list<int> q;
        list<int>::<iterator> it;
        q.push_back(n);
        seen[n]=1;
        while(!q.empty())
        {
            x=q.front();
            q.pop_front();
            cnt[levels[x]]++;
            for (it=ver[x].begin();it!=ver[x].end();++it)
            {
              if(!seen[x])
              {
                  seen[it]=1;
                  q.push_back()
              }
            }

            {

            }
        }

    }
};
