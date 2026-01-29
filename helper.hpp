// clangd: -x c++-header -std=c++20
#pragma once 
#include <unordered_map>
#include <ostream>
#include <iostream>
#include <vector>

template <class K, class V>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<K,V>& mp);
template<class V>
std::ostream& operator<<(std::ostream& os, const std::vector<V> & vect);

#include "helper.tpp"
