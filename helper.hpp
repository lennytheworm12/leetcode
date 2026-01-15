// clangd: -x c++-header -std=c++20
#pragma once 
#include <unordered_map>
#include <ostream>
#include <iostream>

template <class K, class V>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<K,V>& mp);

#include "helper.tpp"
