#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef pair<int, char> pic;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
int keypad(int num, string output[])
{
    if( num < 10 ){
        if(num == 2 ){
            output[0] = "a";
            output[1] = "b";
            output[2] = "c";
            return 3;
        } else if(num == 3 ){
            output[0] = "d";
            output[1] = "e";
            output[2] = "f";
            return 3;
        } else if(num == 4 ){
            output[0] = "g";
            output[1] = "h";
            output[2] = "i";
            return 3;
        } else if(num == 5 ){
            output[0] = "j";
            output[1] = "k";
            output[2] = "l";
            return 3;
        } else if(num == 6 ){
            output[0] = "m";
            output[1] = "n";
            output[2] = "o";
            return 3;
        } else if(num == 7 ){
            output[0] = "p";
            output[1] = "q";
            output[2] = "r";
            output[3] = "s";
            return 4;
        } else if(num == 8 ){
            output[0] = "t";
            output[1] = "u";
            output[2] = "v";
            return 3;
        } else if(num == 9 ){
            output[0] = "w";
            output[1] = "x";
            output[2] = "y";
            output[3] = "z";
            return 4;
        }
        
    }
    
    int smallOutput = keypad(num/10, output);
    string word;
    if(num%10 == 2 ){
        word = "abc";
    } else if(num%10 == 3 ){
        word = "def";
    } else if(num%10 == 4 ){
        word = "ghi";
    } else if(num%10 == 5 ){
        word = "jkl";
    } else if(num%10 == 6 ){
        word = "mno";
    } else if(num%10 == 7 ){
        word = "pqrs";
    } else if(num%10 == 8 ){
        word ="tuv";
    } else if(num%10 == 9 ){
        word = "wxyz";
    }
    for(int j = 1; j< word.length(); j++ ){
        for(int i=0 ; i< smallOutput; i++){
            output[j*smallOutput+i] = output[i] + word[j] ;
        }   
    }
    for(int i = 0; i<smallOutput ; i++){
        output[i] = output[i] + word[0];
    }
    return (word.length()*smallOutput);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string output[10000];
        int ans = keypad(n, output);
        for(int i = 0; i<ans; i++){
            cout << output[i]<< endl;
        }
        cout << endl;
    }
    return 0;
}
/*
int main(){
    cout << 1 << endl;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cout << 2 << endl;
    cin >> t;
    cout << 3 << endl;
    while(t--){
        cout << t << endl;
        int n;
        cin >> n;
        string output[100000];
        // int ans = keypad(n, output);
        int ans = 0;
        cout  << ans << endl;
        for(int i = 0; i<ans; i++){
            cout << output[i]<< ' ';
        }
        cout << endl;
    }
    // write your code here
    return 0;
}*/