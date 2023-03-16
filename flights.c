#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findCheapestPrice(int n, int flights[5][3], int flightsSize, int src, int dst, int k){
    int *dist = malloc(n * sizeof(int));
    int *dist_temp = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        dist[i] = 1111;
        dist_temp[i] = 1111;
    }
    dist[src] = 0;
    dist_temp[src] = 0;
    while(k>=0){
        for (int i = 0; i < flightsSize; i++){
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];

            if (dist_temp[to] > dist[from] + price){
                dist_temp[to] = dist[from] + price;
            }
        }
        memcpy(&dist[0], &dist_temp[0], n * sizeof(int));
        k--;

    }
    int ret = dist[dst];
    if (ret == 1111) return -1;
    return ret;
}

int main(){
    int n=4;
    int flights[5][3] = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0, dst = 3, k = 1;
    int ans= findCheapestPrice(n,flights,5,src,dst,k);
    printf("%d",ans);
}