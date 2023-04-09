//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    vector<int> makeBeautiful(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;

        for (int i = 0; i < n; i++) {
            // add the current element to result vector
            res.push_back(arr[i]);

            // remove different adjacent integers from left to right
            while (res.size() > 1 && ((res[res.size()-2] >= 0 && res[res.size()-1] < 0) || (res[res.size()-2] < 0 && res[res.size()-1] >= 0))) {
                res.pop_back();
                res.pop_back();
            }
        }

        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends