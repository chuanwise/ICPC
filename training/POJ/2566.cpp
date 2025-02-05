#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <bitset>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;
typedef pair<ll, int > Pli;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const int MAX_N = 1e5 + 10;

template <typename T>
inline T sqr(T a) { return a * a;};

int N, K, A;
ll T, sum;
pair<ll, Pii> ans;
vector<Pli> v;

inline ll mabs(ll x) {
    return (x >= 0) ? x : -x;
}

int main(int argc, char const *argv[])
{
    while (scanf("%d%d", &N, &K) && (N || K)) {
        sum = 0;
        v.clear();
        v.push_back(Pli(sum, 0));
        for (int i = 0; i < N; ++i) {
            scanf("%d", &A);
            sum = sum + A;
            v.push_back(Pli(sum, i + 1));
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < K; ++i) {
            scanf("%lld", &T);
            int s = 0, t = 0, l, r;
            ans.first = INF;
            for(;;) {
                while (t < v.size() && v[t].first - v[s].first <= T) 
                    ++t;
                --t;
                if (t > s) {
                    if (mabs(ans.first - T) > mabs(v[t].first - v[s].first - T)) {
                        ans.first = v[t].first - v[s].first;
                        l = min(v[s].second, v[t].second);
                        r = max(v[s].second, v[t].second);
                        ans.second = Pii(l, r);
                    }
                }
                ++t;
                if (t == v.size()) break;
                if (t > s) {
                    if (mabs(ans.first - T) > mabs(v[t].first - v[s].first - T)) {
                        ans.first = v[t].first - v[s].first;
                        l = min(v[s].second, v[t].second);
                        r = max(v[s].second, v[t].second);
                        ans.second = Pii(l, r);
                    }
                }
                ++s;
            }
            if (ans.second.first > ans.second.second)
                swap(ans.second.first, ans.second.second);
            printf("%lld %d %d\n", ans.first, ans.second.first + 1, ans.second.second);
        }
    }
    return 0;
}