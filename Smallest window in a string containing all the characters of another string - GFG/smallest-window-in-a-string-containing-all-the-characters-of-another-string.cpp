//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    string smallestWindow (string s, string t)
    {
        if(s.size()<t.size())return "-1";
        vector<int>req(26,0);
        vector<int>mp(26,0);
        int n1=s.size(),n2=t.size();
        for(int i=0;i<n2;i++){
            req[t[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(req[i]>0)count++;
        }
        int i=0,j=0,I=-1,J=-1,ans=INT_MAX;
        int noNeeded=count;
        vector<int>vis(26,0);
        while(j<n1){
            mp[s[j]-'a']++;
            bool f=false;
            if((req[s[j]-'a']>0) and (mp[s[j]-'a']>=req[s[j]-'a']) and (vis[s[j]-'a']==0)){vis[s[j]-'a']=1;noNeeded--;}
            f=(noNeeded==0);
            if(f){
                bool allowed=true;
                while(allowed==true){
                    int t = j-i+1;
                    if(t<ans){
                        I=i;
                        J=j;
                        ans=t;
                    }
                    mp[s[i]-'a']--;
                    allowed=(mp[s[i]-'a']>=req[s[i]-'a']);
                    if(mp[s[i]-'a']<req[s[i]-'a'] and allowed){noNeeded++;}
                    if(mp[s[i]-'a']==0 and allowed){vis[s[i]-'a']=0;}
                    if(allowed)i++;
                    if(!allowed)mp[s[i]-'a']++;
                }
                j++;
            }
            else{
                j++;
            }
        }
        if(I==-1 ||J==-1){return "-1";}
        string an="";
        for(int k=I;k<=J;k++){
            an+=s[k];
        }
        return an;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends