#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <algorithm>
#define MAX 5
#define MMAX 30
using namespace std;
char chmap[MAX][MAX];
int map[MAX][MAX];
int rmap[MAX][MAX];
bool g[MMAX][MMAX];
int used[MMAX],mat[MMAX];
int n,m;
int nn,mm;
int Augement(int x)
{
    int i;
    for(i=1; i<=mm; i++)
        if( !used[i] && g[x][i] )
        {
            used[i] = 1;
            if( mat[i] == 0 || Augement(mat[i]) )
            {
                mat[i] = x;
                return 1;
            }
        }
    return 0;
}
int Hungary()
{
    int i,sum = 0;
    memset(mat,0,sizeof(mat));
    for(i=1; i<=nn; i++)
    {
        memset(used,0,sizeof(used));
        if( Augement(i) )
            sum++;
    }
    return sum;
}
int main()
{
    int i,k;

    //freopen("..\\zoj1002\\data.txt","r",stdin);
    //freopen("..\\zoj1002\\result.txt","w",stdout);

    while( ~scanf("%d",&n) && n )
    {
        memset(map,0,sizeof(map));
        memset(rmap,0,sizeof(map));
        memset(g,0,sizeof(g));
        for(i=0; i<n; i++)
            scanf("%s",chmap[i]);
        nn = mm = 0;
        for(i=0; i<n; i++)
        {
            k = 0;
            while( k < n )
                if( chmap[i][k] == '.' )
                {
                    nn++;
                    while( k < n && chmap[i][k] != 'X' )
                    {
                        map[i][k] = nn;
                        k++;
                    }
                }
                else
                    k++;
        }

        for(i=0; i<n; i++)
        {
            k = 0;
            while( k < n )
                if( chmap[k][i] == '.' )
                {
                    mm++;
                    while( k < n && chmap[k][i] != 'X' )
                    {
                        rmap[k][i] = mm;
                        k++;
                    }
                }
                else
                    k++;
        }
        for(i=0; i<n; i++)
            for(k=0; k<n; k++)
                if( chmap[i][k] == '.' )
                    g[map[i][k]][rmap[i][k]] = 1;
        int ans = Hungary();
        printf("%d/n",ans);
    }
    return 0;
}
