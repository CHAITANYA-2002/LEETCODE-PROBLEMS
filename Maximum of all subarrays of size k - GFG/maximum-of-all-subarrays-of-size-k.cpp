//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    
    int largest_num(int start, int*arr, int k) {
        int largest = start;
            for(int j=start;j<start+k;j++)
                if(arr[largest] < arr[j])
                    largest=j;
        return largest;
    }
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> res;
        int largest = largest_num(0,arr,k);
        for(int i=0; i<n-k+1; i++) {
            if(i > largest) {
                largest = largest_num(i,arr,k);
            } else {
                if (arr[largest] < arr[i+k-1])
                    largest=i+k-1;
            }
            res.push_back(arr[largest]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends