#include <bits/stdc++.h>
#include <iostream>
#define fin(i, s, n) for (int i = s; i < n; i++)
#define fde(i, n) for (int i = n; i >= 0; i--)
#define pii pair<int, int>
#define ll long long
#define mod 1000000007
using namespace std;

string removeSpaces(string str)
{
  str.erase(remove(str.begin(), str.end(), ' '), str.end());
  return str;
}
void buildZarray(string str, int *z)
{
  z[0] = 0;
  int l = 0, r = 0, n = str.length();
  fin(i, 1, n)
  {
    if (i > r)
    {
      l = r = i;
      while (r < n && str[r - l] == str[r])
      {
        r++;
      }
      z[i] = r - l;
      r--;
    }
    else
    {
      int k = i - l;
      if (z[k] <= r - i)
      {
        z[i] = z[k];
      }
      else
      {
        l = i;
        while (r < n && str[r - l] == str[r])
        {
          r++;
        }
        z[i] = r - l;
        r--;
      }
    }
  }
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--)
  {
    string sentence, word;
    // it can take string with white spaces as input
    getline(cin >> ws, sentence);
    cin >> word;
    sentence = removeSpaces(sentence);
    string Zsentence = word + "$" + sentence;
    int n = Zsentence.size();
    int *z = new int[n];
    buildZarray(Zsentence, z);
    int count = 0;
    fin(i, word.size() + 1, n)
    {
      if (z[i] == word.size())
      {
        count++;
      }
    }
    cout << count << endl;
  }
  return 0;
}