//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}

// } Driver Code Ends


//User function Template for C++

void rotate(int arr[], int n)
{
    vector<int>ans;
    ans.push_back(arr[n-1]);
    for(int i=0;i<n-1;i++){
        ans.push_back(arr[i]);
    }
    int i=0;
     for(auto it: ans){
         arr[i]=it;
         i++;
     }
}