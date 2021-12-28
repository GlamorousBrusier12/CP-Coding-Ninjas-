#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int numZeroGroups = 0;
    char prev = s[0];
    (s[0]=='0'?numZeroGroups++:numZeroGroups);
    for(int i = 1; i<n; i++){
        char curr = s[i];
        prev = s[i-1];
        if(prev == '1' && curr == '0') numZeroGroups++;
    }
    cout << (numZeroGroups==0?0:((numZeroGroups-1)*min(x, y))+y) << endl;
    return 0;
}