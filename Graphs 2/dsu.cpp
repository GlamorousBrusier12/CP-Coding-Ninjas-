#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class DsuNode
{
public:
  int data, rank;
  DsuNode *parent;
};
class DisjoinSet
{
private:
  map<int, DsuNode *> hash;
  DsuNode *searchHelper(DsuNode *d)
  {
    if (d->parent == d)
    {
      return d;
    }
    return searchHelper(d->parent);
  }

public:
  void initializeSet(int data)
  {
    DsuNode *newNode = new DsuNode();
    newNode->data = data;
    newNode->rank = 0;
    newNode->parent = newNode;
    hash[data] = newNode;
  }

  void Union(int data1, int data2)
  {
    if (data1 == data2)
    {
      return;
    }
    DsuNode *node1 = hash[data1];
    DsuNode *node2 = hash[data2];
    DsuNode *parent1 = searchHelper(node1);
    DsuNode *parent2 = searchHelper(node2);

    if (parent1->rank >= parent2->rank)
    {
      if (parent1->rank == parent2->rank)
      {
        parent1->rank = parent1->rank + 1;
      }
      parent2->parent = parent1;
    }
    else
    {
      parent1->parent = parent2;
    }
  }

  int searchInSet(int data)
  {
    return (searchHelper(hash[data])->data);
  }
};
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  DisjoinSet set;
  set.initializeSet(0);
  set.initializeSet(1);
  set.initializeSet(2);
  set.initializeSet(3);
  set.initializeSet(4);
  set.initializeSet(5);
  set.initializeSet(6);

  set.Union(0, 1);
  set.Union(1, 2);
  set.Union(3, 4);
  set.Union(2, 4);
  set.Union(5, 6);
  set.Union(4, 6);

  cout << set.searchInSet(0) << endl;
  cout << set.searchInSet(1) << endl;
  cout << set.searchInSet(2) << endl;
  cout << set.searchInSet(3) << endl;
  cout << set.searchInSet(4) << endl;
  cout << set.searchInSet(5) << endl;
  cout << set.searchInSet(6) << endl;

  return 0;
}