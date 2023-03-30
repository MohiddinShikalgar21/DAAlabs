package Test;
import java.util.*;

public class longblocksum {
     static int brutesum(int[] arr) {
    	int max=0;
    	int sum=0;
    	for(int i=0;i<arr.length;i++) {
    		sum+=arr[i];
    		for(int j=i+1;j<arr.length;j++) {
    			sum+=arr[j];
    			max=Math.max(sum, max);
    		}
    		sum=0;
    	}
    	return max;
    }
    static int kadanessum(int[] arr) {
    	int sum=0;
    	for(int i=0;i<arr.length;i++) {
    		sum+=arr[i];
    		if(sum<0) sum=0;
    	}
    	return sum;
    }
    static int maxsum(int[] arr) {
    	int[] dp=new int[arr.length];
    	int sum=0;
    	int max=0;
    	for(int i=0;i<arr.length;i++) {
    		dp[i]=Math.max(arr[i], arr[i]+sum);
    		sum=dp[i];
    		max=Math.max(sum,max);
    	}
    	return max;
    }
    public static void main(String[] args) {
    	int[] arr={21,-2,12,-21,1,2,4,-5,34,1};
    	System.out.println(brutesum(arr));
    	System.out.println(kadanessum(arr));
    	System.out.println(maxsum(arr));

    }
}
