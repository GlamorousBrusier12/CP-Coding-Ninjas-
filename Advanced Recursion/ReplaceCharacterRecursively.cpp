#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef pair<int, char> pic;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
void replacechar(string &s, char c1, char c2){
    if(s[0]=='\0') return;
    if(s[0] == c1) {
        // s[0] = c2;
        string c = s.substr(1);
        replacechar(c, c1, c2);
        s = c2 + c;
    }else{
        string c = s.substr(1);
        replacechar(c, c1, c2);
        s = s[0] + c;
    }
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
        char c1, c2;
        cin >> c1 >> c2;
        replacechar(s, c1, c2);
        cout << s << endl;   
    }
    return 0;
}