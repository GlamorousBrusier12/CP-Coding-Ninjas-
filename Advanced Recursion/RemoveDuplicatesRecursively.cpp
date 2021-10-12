#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef pair<int, char> pic;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
void removeDulpicates(string &s){
    if(s[0] == '\0' || s.length() == 1) return;
    string k = s.substr(1);
    removeDulpicates(k);
    if(s[0] == k[0]) s = k;
    else s = s[0] + k;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        removeDulpicates(s);
        cout << s << endl;
    }
    return 0;
}