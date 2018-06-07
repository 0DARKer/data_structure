#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int k;
int a[1005],team[1005];
int findteam(int k)
{
    if (team[k]!=k) return team[k]=findteam(team[k]);
      else return k;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) team[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x]++; a[y]++;
        int fx=findteam(x);
        int fy=findteam(y);
        if (fx!=fy) team[fy]=fx;
    }
    bool flag=1;
    for(int i=1;i<=n;i++)
        if (a[i]%2!=0)
        {
          flag=0;
          break;
        }
    if (flag)
    {
        int k=findteam(1);
        for(int i=2;i<=n;i++)
        if (k!=findteam(i)) {printf("0\n"); return 0;}
        printf("1\n");
    }
    else printf("0\n");
    return 0;
}
