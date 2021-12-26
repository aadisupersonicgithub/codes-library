#include <ext/rope>
using namespace __gnu_cxx;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using Set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class K, class V> using Map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void ishow2(Set<pair<i64, i64>> f) {
    int k = f.size();
    cout << "[ ";
    for (int i = 0; i < k; ++i) {
        auto v = *f.find_by_order(i);
        cout << "(" << v.first << ", " << v.second << ") "; 
    }
    cout << "]\n"; 
}
void ishow1(Set<i64> f) {
    int k = f.size();
    cout << "[ ";
    for (int i = 0; i < k; ++i) {
        cout << *f.find_by_order(i) << ' '; 
    }
    cout << "]\n";
}

