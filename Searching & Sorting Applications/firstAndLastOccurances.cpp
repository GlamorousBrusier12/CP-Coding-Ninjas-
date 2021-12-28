// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


vector<int> find(int arr[], int n , int x )
{
    vector<int> ans;
    int lastIndex = -1, firstIndex = -1;
    int si = 0, ei = n-1;
    while(si <= ei){
        printf("(%d, %d):",si, ei);
        int mid = si + (ei-si)/2;
        if(arr[mid] == x){
            printf("=>1\n");
            firstIndex = mid;
            ei = mid -1;
        }else{
            printf("=>0\n");
            if(arr[mid] < x){
                si = mid + 1;
            }else{
                ei = mid - 1;
            }
        }
    }
    si = firstIndex, ei = n-1;
    // finding the last occurance
    while(si<=ei){
        int mid = si + (ei-si)/2;
        if(arr[mid] == x){
            lastIndex = mid;
            si = mid + 1;
        }else{
            if(arr[mid] < x){
                si = mid + 1;
            }else{
                ei = mid - 1;
            }
        }
    }
    // finding the first ocuurance
    ans.push_back(firstIndex);
    ans.push_back(lastIndex);
    return ans;
}