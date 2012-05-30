/**********************************************
Written by  : quxiaofeng.at.polyu@gmail.com
Date        : 2012-03-11 03:21:00
Description : dfs with context restoration
State       : Accepted
Run Time    : 0ms
Run Memory  : 160KB
***********************************************/
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAXLENGTHOFCHARS 255

char STchars[MAXLENGTHOFCHARS];
int STcurrentPos = 0;


int STpush (char currentChar) {
    if ( STcurrentPos < MAXLENGTHOFCHARS ) {
        STchars[STcurrentPos ++] = currentChar;
        return 1;
    }
    return 0;
}

int STpop (char * popChar) {
    char tempChar;
    if ( STcurrentPos > 0 ) {
        tempChar = STchars[STcurrentPos - 1];
        STcurrentPos -= 1;
        * popChar = tempChar;
        return 1;
    }
    return 0;
}

int STtopEqual (char currentChar) {
    return STchars[STcurrentPos - 1] == currentChar;;
}

void STclear() {
    STcurrentPos = 0;
}

void sovle (char * basicList, int basicCharsLeft, char * goalList, int goalCharsLeft, char * result, int resultLength, int resultIdx) {
    char tempChar = ' ';
    int i = 0;
    char * searchResult = (char *)malloc(resultLength);
    memcpy(searchResult, result, resultLength);

    if (goalCharsLeft > 1 && basicCharsLeft < 1 && !STtopEqual(goalList[goalCharsLeft - 1]) ) {
        return;
    }

    if (goalCharsLeft < 1) {
        for (i = 0; i < resultLength; i ++) {
            printf("%c", result[i]);
        }
        printf("\n");
        return;
    }

    if ( basicCharsLeft > 0 ) {
        STpush(basicList[basicCharsLeft - 1]);
        basicCharsLeft -= 1;
        searchResult[resultIdx++] = 'i';
        searchResult[resultIdx++] = ' ';
        sovle( basicList, basicCharsLeft, goalList, goalCharsLeft, searchResult, resultLength, resultIdx);
        basicCharsLeft += 1;
        resultIdx -= 2;
        searchResult[resultIdx] = ' ';
        STpop(&tempChar);
    }
    if ( STtopEqual(goalList[goalCharsLeft - 1]) ) {
        STpop(&tempChar);
        goalCharsLeft -= 1;
        searchResult[resultIdx++] = 'o';
        searchResult[resultIdx++] = ' ';
        sovle( basicList, basicCharsLeft, goalList, goalCharsLeft, searchResult, resultLength, resultIdx);
        goalCharsLeft += 1;
        resultIdx -= 2;
        searchResult[resultIdx] = ' ';
        STpush(tempChar);
    }
}

int main()
{
    char basicChars[MAXLENGTHOFCHARS];
    char goalChars[MAXLENGTHOFCHARS];
    int cntBasicChars = 0;
    int cntGoalChars = 0;
    char * basicList;
    char * goalList;
    char * result;
    int resultIdx = 0;
    int i = 0;
    int resultLength = 0;

    /*
    freopen("..\\zoj1004\\data.txt","r",stdin);
    freopen("..\\zoj1004\\result.txt","w",stdout);
    */

    while (scanf("%s%s", basicChars, goalChars)!=EOF) {
        cntBasicChars = strlen(basicChars);
        cntGoalChars = strlen(goalChars);
        printf("[\n");
        if (cntBasicChars == cntGoalChars) {
            /*backward list*/
            basicList = (char *)malloc(cntBasicChars);
            for (i = 0; i < cntBasicChars; ++i) {
                basicList[cntBasicChars - 1 - i] = basicChars[i];
            }
            goalList = (char *) malloc(cntGoalChars);
            for (i = 0; i < cntGoalChars; ++i) {
                goalList[cntGoalChars - 1 - i] = goalChars[i];
            }
            resultLength = cntGoalChars * 4;
            result = (char *)malloc(resultLength);
            memset(result, 0, resultLength);
            sovle( basicList, cntBasicChars, goalList, cntGoalChars, result, resultLength, resultIdx );
        }
        printf("]\n");
        cntBasicChars = 0;
        cntGoalChars = 0;
        STclear();
    }


    return 0;
}

