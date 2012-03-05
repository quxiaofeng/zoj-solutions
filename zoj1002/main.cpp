/**********************************************
Written by  : quxiaofeng.at.polyu@gmail.com
Date        : 2012-03-05 11:36:38
Description : No best map result TAT
State       : Accepted
Run Time    : 0ms
Run Memory  : 180KB
***********************************************/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

void fill_map(int side_length, char * search_map, int ipos) {
    int irow = ipos / side_length;
    int icol = ipos % side_length;
    //file the forthcoming cols of the same row
    for (; icol < side_length; icol ++){
        if (search_map[irow * side_length + icol] == 'X') {
            break;
        }
        else {
            search_map[irow * side_length + icol] = '8';
        }
    }
    //file the forthcoming rows of the same col
    icol = ipos % side_length;
    for (; irow < side_length; irow ++){
        if (search_map[irow * side_length + icol] == 'X') {
            break;
        }
        else {
            search_map[irow * side_length + icol] = '8';
        }
    }
}

int try_castles(int side_length, char * city_map, int ipos) {
    int max_castles = 0;
    int cnt_castles = 0;
    char * search_map = (char *)malloc(side_length * side_length);
    memcpy (search_map, city_map, side_length * side_length);

    for(;ipos < side_length * side_length - 1; ++ipos) {
        if ('.' == search_map[ipos]){
            //find the blank and position a castle
            search_map[ipos] = 'O';
            fill_map(side_length, search_map, ipos);
            cnt_castles = try_castles(side_length, search_map, ipos + 1);
            cnt_castles += 1;
            max_castles = max_castles > cnt_castles ? max_castles : cnt_castles;

            //find the blank but do not position a castle
            cnt_castles = try_castles(side_length, city_map, ipos + 1);
            max_castles = max_castles > cnt_castles ? max_castles : cnt_castles;
        }
    }
    //last point
    if (ipos == side_length * side_length - 1 ) {
        if ('.' == search_map[ipos])
            max_castles = max_castles > 1 ? max_castles : 1;
    }
    free(search_map);
    return max_castles;
}

int main(void)
{
    int side_length = 0;
    char * city_map;
    int max_castles = 0;
    int irow = 0, icol = 0;
    int origin_pos = 0;

    //freopen("..\\zoj1002\\data.txt","r",stdin);
    //freopen("..\\zoj1002\\result.txt","w",stdout);

    //read data
    while ( scanf("%d", &side_length) && side_length ) {
        if ('\n' == getchar()) {
            ;
        }
        else {
            return -1;
        }

        city_map = (char *)malloc(side_length*side_length);

        for (irow = 0; irow < side_length; ++ irow) {
            for ( icol = 0; icol <side_length; ++ icol) {
                scanf("%c",&city_map[irow * side_length + icol]);
            }
            if ('\n' == getchar()) {
                ;
            }
            else {
                return -1;
            }
        }

        //try to solve
        max_castles = try_castles(side_length, city_map, origin_pos);
        printf("%d\n", max_castles);
    }
    return 0;
}
