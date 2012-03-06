/**********************************************
Written by  : quxiaofeng.at.polyu@gmail.com
Date        : 2012-03-06 02:29:36
Description : dfs with a complicated situation
State       : Accepted
Run Time    : 270ms
Run Memory  : 180KB
***********************************************/
#include <stdio.h>
#include <malloc.h>

void deepFirstSearch( int bigNumber, int smallNumber, int factor, int * bigDisolved, int * smallDisolved)
{
    //ending condition
    if( factor > 100 ) return;
    else if( smallNumber == 1) {
        if ( bigNumber == 1 ) {
            * bigDisolved = 1;
            return;
        }
        else * smallDisolved = 1;
    }

    //three branches on factor
    if( bigNumber % factor == 0 ) deepFirstSearch( bigNumber / factor, smallNumber,     factor + 1, bigDisolved, smallDisolved);
    if( smallNumber % factor == 0 ) deepFirstSearch( bigNumber,     smallNumber / factor, factor + 1, bigDisolved, smallDisolved);
    deepFirstSearch( bigNumber, smallNumber, factor + 1, bigDisolved, smallDisolved);
}

int main()
{
    int bigNumber, smallNumber;
    int * bigDisolved = 0;
    int * smallDisolved = 0;

    //freopen("..\\zoj1003\\data.txt","r",stdin);
    //freopen("..\\zoj1003\\result.txt","w",stdout);

    while (scanf("%d %d", &bigNumber, &smallNumber) != EOF)
    {
        int temp;
        if( bigNumber < smallNumber ) temp = bigNumber, bigNumber = smallNumber, smallNumber = temp;
        * bigDisolved = 0;
        * smallDisolved = 0;
        deepFirstSearch( bigNumber, smallNumber, 2, bigDisolved, smallDisolved);
        if ( * bigDisolved ) printf("%d\n", bigNumber );
        else if( * smallDisolved ) printf("%d\n", smallNumber );
        else       printf("%d\n", bigNumber );
    }


    return 0;
}

