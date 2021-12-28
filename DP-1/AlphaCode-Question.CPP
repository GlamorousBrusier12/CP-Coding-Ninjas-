#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool isAlpha(char c1, char c2){
    int number = (c1-'0')*10+(c2-'0');
    return (number<=26 && number >0);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    int mod = pow(10, 9)+7;
    while(t--){
        string number;
        cin >> number;
        int n = number.size();
        int *ans = new int[n+1];
        ans[0] = 1, ans[1] = 1;
        for(int i = 2; i<n+1; i++){
            if(number[i]-'0'!=0){
                ans[i] = ans[i-1];
                if(isAlpha(number[i-2], number[i-1])){
                    ans[i] = (int)((long)ans[i]%mod + (ans[i-2]%mod))%mod;
                }
            }
            else ans[i]=0;
        }
        int a = ans[n];
        delete []ans;
        cout << a << endl;       
    }
    return 0;
}   