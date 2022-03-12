#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

void t1() {
    map<int, int> a;
    int x;
    while (cin >> x)
        a[x]++;
    for (auto [f, s] : a)
        cout << f << " " << s ;
}

map<int, int> sec() {
    map<int, int> ans;
    int n; cin >> n;
    int f, s;
    for (int i = 0; i < n; i++) {
        cin >> f >> s;        ans[f] = s;
    }
    return ans;
}

void t3() {
    map<int, int> a = task_2();
    int x;
    while (cin >> x) {
        cout << x << " ";
        if (a.count(x) == 0)
            cout << x;
        else
            cout << a[x];
    }
}

template <class A, class B>
map<A, B> sum(map<A, B> a, map<A, B> b) {
    map<A, B> ans;
    for (auto [x, _] : a)
        ans[x] = a[x] + b[x];
    return ans;
}

template <class A, class B, class C>
map<A, C> comp(map<A, B> a, map<B, C> b) {
    map<A, C> ans;
    for (auto [f, s] : a)
        ans[f] = b[s];
    return ans;
}


