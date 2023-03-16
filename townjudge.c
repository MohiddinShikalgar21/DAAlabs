#include <stdio.h>
#include <string.h>

int findJudge(int n, int trust[7][2], int trustSize) {
    int retVal = -1;
    int i;
    int Graph[n][2];
    memset(Graph, 0, sizeof(Graph));
    for (i = 0; i < trustSize; ++i) {
        ++Graph[trust[i][0] - 1][0];
        ++Graph[trust[i][1] - 1][1];
    }

    for (i = 0; i < n; ++i) {
        if (Graph[i][0] != 0) {
            continue;
        }
        if (Graph[i][1] != n - 1) {
            continue;
        }
        retVal = i + 1;
        break;
    }

    return retVal;
}

int main(){
    int array[7][2]={{1,3},{2,1},{2,3},{2,4},{4,1},{4,3},{5,3}};
    int n=5;
    printf("%d",findJudge(n,array,7));
}