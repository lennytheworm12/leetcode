#include <unordered_map>
#include <ostream>

template <class K, class V>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<K, V>& mp) {
    os << "{ ";
    for (const auto& [k, v] : mp) os << k << ":" << v << " ";
    os << "}";
    return os;
}

