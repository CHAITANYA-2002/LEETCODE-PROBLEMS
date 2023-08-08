//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<int>left;
        vector<int>right;
        stack<int>s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                left.push_back(-1);
                s.push(i);
            }
            else{
                while(!s.empty() and arr[i]<=arr[s.top()]){
                    s.pop();
                }
                if(s.empty()){
                    left.push_back(-1);
                }
                else{
                    left.push_back(s.top());
                }
                s.push(i);
            }
        }
        while(!s.empty())s.pop();
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                right.push_back(-1);
                s.push(i);
            }
            else{
                while(!s.empty() and arr[i]<=arr[s.top()]){
                    s.pop();
                }
                if(s.empty()){
                    right.push_back(-1);
                }
                else{
                    right.push_back(s.top());
                }
                s.push(i);
            }
        }
        reverse(right.begin(),right.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            long long t1=(left[i]==-1)?-1:left[i];
            long long t2=(right[i]==-1)?n:right[i];
            ans=max(ans,(t2-t1-1)*(arr[i]));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends