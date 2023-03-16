#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int a,int b){
    if(a>=b) return a;
    return b;
}

int robs(int* nums, int numsSize){
    if (numsSize == 1)
        return nums[0];

    int i, *sum = (int*)calloc(sizeof(int), (numsSize + 1));
    sum[0] = 0, sum[1] = nums[0], sum[2] = nums[1];

    for (i = 3; i <= numsSize; i++)
        sum[i] = max(sum[i - 2], sum[i - 3]) + nums[i - 1];

    return max(sum[numsSize], sum[numsSize - 1]);
}

int main(){
    int arr[]={1,2,3,4,5};
    printf("%d",robs(arr,5));
}
