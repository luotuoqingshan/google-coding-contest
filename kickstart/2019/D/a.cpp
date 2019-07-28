#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

const int maxn = 1e5 + 5;

int N, Q;
int a[maxn];
set<int> s;
int main(){
    int T;
    int cas = 0;
    cin >> T;
    while(T--){
        printf("Case #%d:", ++cas);
        cin >> N >> Q;
        s.clear();
        for(int i = 0;i < N;i++){
            scanf("%d", a + i);
            if(__builtin_popcount(a[i]) & 1){
                s.insert(i);
            }
        }    
        for(int i = 0;i < Q;i++){
            int p, v;
            scanf("%d%d", &p, &v);
            if(__builtin_popcount(v) & 1){
                s.insert(p);
            }else{
                s.erase(p);
            }
            if(s.size() & 1){
                int ans = min(*s.begin() + 1, N - *s.rbegin());
                printf(" %d", N - ans);
            }else{
                printf(" %d", N);
            } 
        } 
        puts("");
    } 
    return 0;
}
