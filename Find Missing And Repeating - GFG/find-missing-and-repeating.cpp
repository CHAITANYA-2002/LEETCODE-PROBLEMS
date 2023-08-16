//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        sort(arr.begin(),arr.end());
        int rep ;
        int mis;
        for(int i=0;i<n-1;i++)
        {
             
            if(arr[i] == arr[i+1])
            {
                rep = arr[i];
            }
             if(arr[i+1]-arr[i] == 2 )
            {
                mis = arr[i]+1;
            }
            else if(arr[0] !=1)
            mis=1;
            else if(arr[n-1] !=n )
        mis = n;
            
        }
        
        return {rep,mis};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends