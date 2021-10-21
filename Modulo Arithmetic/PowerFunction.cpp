#include<bits/stdc++.h>
using namespace std;
#define m 1000000007;
int power(int x, int y){
    if(y == 0) return 1;
    int ans = 0;
	
    int smallAns = power(x, y-1);
    long a = (long)smallAns*x;
    a = a%m;
    ans = (int)a;
    return ans;
}
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        cout << power(x, y)  << endl;
    }
    
    return 0;
}