#pragma once
#include <bits/stdc++.h>
using namespace std;

template <class T>
void _print(const T& x) { cerr << x; }

template <class A, class B>
void _print(const pair<A,B>& p) { cerr << "("; _print(p.first); cerr << ","; _print(p.second); cerr << ")"; }

template <class T>
void _print(const vector<T>& v) {
    cerr << "[";
    for (int i = 0; i < (int)v.size(); i++) { if (i) cerr << ", "; _print(v[i]); }
    cerr << "]";
}

#define debug(x) cerr << #x << " = ", _print(x), cerr << "\n"
