#include <stdio.h>
#include <string.h>
char s1[100], s2[100], temp[100], ope[200];
int tail;
void put(int t, int s, int q, int p)
{
    int i, j, k;
    i=t, j=s, k=p;
    while(j<=q)
    {
        temp[i++]=s1[j++];
        ope[k++]='i';
    }
    ope[k]='o';
}

void next(int k, int s, int t, int p)
{
    int i;
    if(k>=tail)
    {
        for(i=0; i<2*tail; i++)
        {
            printf("%c ", ope[i]);
        }
        printf("\n");
    }
    for(i=tail-1; i>=s; i--)
    {
        if(s1[i]==s2[k])
        {
            put(t, s, i, p);
            next(k+1, i+1, t+i-s, p+i-s+2);
        }
    }
    if(t-1>=0 && temp[t-1]==s2[k])
    {
        ope[p]='o';
        next(k+1, s, t-1, p+1);
    }
}


int main(void)
{


    while(scanf("%s%s", s1, s2)!=EOF)
    {
        tail=strlen(s1);
        printf("[\n");
        next(0, 0, 0, 0);
        printf("]\n");
    }
    return 0;
}
