//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.lang.*;


class Array {

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
		while(t-->0){
		  
		    //size of array
		    int n = Integer.parseInt(br.readLine().trim());
		    int arr[] = new int[n];
		    String inputLine[] = br.readLine().trim().split(" ");
		    
		    //adding elements to the array
		    for(int i=0; i<n; i++){
		        arr[i] = Integer.parseInt(inputLine[i]);
		    }
		    
		    Solution obj = new Solution();
		    
		    //calling trappingWater() function
		    System.out.println(obj.trappingWater(arr, n));
		}
	}
}


// } Driver Code Ends

class Solution{


    static long trappingWater(int arr[], int n) { 

        //Create Left Max Boundary Array

        long leftMax[] = new long[n];
        leftMax[0] = arr[0];
        for(int i = 1; i < n; i++){
            leftMax[i] = Math.max(leftMax[i-1], arr[i]);
        }
        
        //Create Right Max Boundary Array

        long rightMax[] = new long[n];
        rightMax[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            rightMax[i] = Math.max(rightMax[i+1], arr[i]);
        }


        long trappedWater = 0;

        //Create loop to calculate height of water level and Trapped water

        for(int i = 0; i < n; i++){
            long waterLevel = Math.min(rightMax[i],leftMax[i]);
            
            trappedWater += waterLevel - arr[i];
        }
        return trappedWater;
    } 
}