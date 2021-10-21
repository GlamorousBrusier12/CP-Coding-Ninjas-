#include<bits/stdc++.h>
using namespace std;
#define m 1000000007;
int product(int n){
    if(n == 1) return n;
    int ans = 0;
	
    int smallAns = product(n-1);
    long x = (long)smallAns*n;
    x = x % m;
    ans = (int)x;
    return ans;
}
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << product(n)  << endl;
    }
    
    return 0;
}