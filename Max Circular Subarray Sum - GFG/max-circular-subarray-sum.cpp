//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
public:

    int circularSubarraySum(int arr[], int num){

        int max_straight_SUM = INT_MIN;
        int min_straight_SUM = INT_MAX;
        int array_SUM = 0;
        int temp_max_SUM = 0;
        int temp_min_SUM = 0;

        //traversing the array.
        for (int i=0; i<num; i++)
        {
            //Storing array sum.
            array_SUM += arr[i];
            
            //Finding maximum subarray sum.
            temp_max_SUM = max(temp_max_SUM + arr[i], arr[i]);
            max_straight_SUM = max(max_straight_SUM, temp_max_SUM);

            //Finding minimum subarray sum.
            temp_min_SUM = min(temp_min_SUM + arr[i], arr[i]);
            min_straight_SUM = min(min_straight_SUM, temp_min_SUM);
        }

        //If all numbers are negative, max wrap will be zero, which
        //can not be maximum subarray sum, so answer is max_straight_SUM.
        if(array_SUM == min_straight_SUM)
            return max_straight_SUM;
        
        //Else we compare max of straight region with max of wrapped region.
        return max(max_straight_SUM, (array_SUM - min_straight_SUM));
    }
};


//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends