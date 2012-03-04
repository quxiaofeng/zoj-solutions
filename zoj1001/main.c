#include <stdio.h>

int main()
{
    int a,b;

    freopen("..\\zoj1001\\data.txt","r",stdin);
    freopen("..\\zoj1001\\result.txt","w",stdout);

    while(scanf("%d %d",&a, &b) != EOF)
        printf("%d\n",a+b);
    return 0;
}
