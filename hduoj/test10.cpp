#include <stdio.h>
#include <iostream>
using namespace std;

const int MAXN = 30001; /*结点数目上线*/
int pa[MAXN];    /*p[x]表示x的父节点*/
int rank[MAXN];    /*rank[x]是x的高度的一个上界*/
int num[MAXN];/*num[]存储该集合中元素个数，并在集合合并时更新num[]即可*/

void make_set(int x)
{/*创建一个单元集*/
    pa[x] = x;
    rank[x] = 0;
    num[x] = 1;
}

int find_set(int x)
{/*带路径压缩的查找*/
    /*保存待查找的数*/
    int r = x, temp;
    /*找到根节点*/
    while(pa[r] != r) r = pa[r];
    while(x != r)
    {
        temp = pa[x];
        pa[x] = r;
        x = temp;
    }
    return x;
    //if(x != pa[x]) //注释掉的其实也是可以的，不过不想用递归来做啦
    //    pa[x] = find_set(pa[x]);
    //return pa[x];
}

/*按秩合并x，y所在的集合*/
void union_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x == y)return ;
    if(rank[x] > rank[y])/*让rank比较高的作为父结点*/
    {
        pa[y] = x;
        num[x] += num[y];
    }
    else 
    {
        pa[x] = y;
        if(rank[x] == rank[y])
            rank[y]++;
        num[y] += num[x];
    }
}

//answer to 1611 
int main()
{
    int n, m, x, y, i, t, j;
    while(scanf("%d%d", &n, &m))
    {
        if(m==n && n == 0) break;
        if(m == 0)
        {
            cout << "1\n"; continue;
        }
        for(i = 0; i < n; i++)
            make_set(i);
        for(i = 0; i < m; i++)
        {
            scanf("%d", &t);
            scanf("%d", &x);
            for(j = 1; j < t; j++){
                scanf("%d", &y);
                union_set(x, y);
                x = y;
            }
        }
        x = find_set(0);/*找到0所在的树的树根*/
        //int ans = 0;
        //for(i = 0; i < n; i++)
        //    if(pa[i] == x)
        //        ans++;
        //cout << ans << endl;
        cout << num[x] << endl;
    }
    return 0;
}
