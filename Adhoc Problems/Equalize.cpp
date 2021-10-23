#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    for (int i = 0; i < n; )
    {
        if(s1[i] == s2[i]) i++;
        else{
            if(i != n-1 && s1[i+1]!= s1[i] && s1[i+1]!= s2[i+1]){
                ans++, i+=2;
            }else{
                ans++, i++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}