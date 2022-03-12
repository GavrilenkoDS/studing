#include <iostream>
#include <cstdlib>
#include <set>

using namespace std;

void 1() {
    set<int> a;

    int x;
    while (cin >> x)
        a.insert(x);

    for (int q : a)
        cout << q << " ";
}

void 2() {
    set<int> a;
    set<int> b;

    int x;
    while (cin >> x)
        if (a.count(x) == 1)
            b.insert(x);
        else
            a.insert(x);

    for (int q : b)
        cout << q << " ";
}

void 3() {
    set<int> a;
    set<int> b;

    int x;
    while (cin >> x)
        if (b.count(x) == 1)
            a.erase(x);
        else if (a.count(x) == 1)
            b.insert(x);
        else
            a.insert(x);

    for (int q : b)
        if (a.count(q) == 1)
            cout << q << " ";
}

template<class T>
set<T> _union(set<T> a, set<T> b) {
    set<int>* q = a.size() > b.size() ? &a : &b;
    set<int>* t1 = a.size() > b.size() ? &b : &a;
    set<T> ans(*q);

    for (T x : *t1)
        ans.insert(x);

    return ans;}



