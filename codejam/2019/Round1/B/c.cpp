#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
int T;
int n, k;

const int maxn = 1e5 + 5;


int st[maxn][22];
int a[maxn], b[maxn];
void init(){
    for(int i = 1;i <= n;i++){
        st[i][0] = a[i];
    }
    for(int j = 1; (1 << j) <= n;j++){
        for(int i = 1;i + (1 << j) - 1 <= n;i++){
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r){
    int k = 31 - __builtin_clz(r - l + 1);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int l[maxn], r[maxn];
int q[maxn], tot;
int main(){
    cin >> T;
    int cas = 0;
    while(T--){
        long long ans = 0;
        cin >> n >> k;
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }    
        for(int i = 1;i <= n;i++){
            scanf("%d", &b[i]);
        }
        init();
        tot = 0;
        for(int i = 1;i <= n;i++){
            while(tot > 0 && b[q[tot]] <= b[i])
                tot--;
            if(tot == 0)
                l[i] = 1;
            else
                l[i] = q[tot] + 1;
            q[++tot] = i;
        }
        tot = 0;
        for(int i = n;i >= 1;i--){
            while(tot > 0 && b[q[tot]] < b[i])
                tot--;
            if(tot == 0)
                r[i] = n;
            else
                r[i] = q[tot] - 1;
            q[++tot] = i;
        }
        for(int i = 1;i <= n;i++){
            //cout << l[i] << " " << r[i] << endl;
            int ll = -1, lr = -1, rl = -1, rr = -1;
            int Left = 1, Right = i;
            while(Left <= Right){
                int mid = (Left + Right + 1) / 2;
                if(query(mid, i) >= b[i] - k){
                    lr = mid;
                    Left = mid + 1;
                }else{
                    Right = mid - 1;
                }       
            }
            Left = 1, Right = i;
            while(Left <= Right){
                int mid = (Left + Right) / 2;
                if(query(mid, i) <= b[i] + k){
                    ll = mid;
                    Right = mid - 1;
                }else{
                    Left = mid + 1;
                }       
            }
            ll = max(ll, l[i]);
            Left = i, Right = n;
            while(Left <= Right){
                int mid = (Left + Right) / 2;
                if(query(i, mid) >= b[i] - k){
                    rl = mid;
                    Right = mid - 1;
                }else{
                    Left = mid + 1;
                }       
            }
            Left = i, Right = n;
            while(Left <= Right){
                int mid = (Left + Right + 1) / 2;
                if(query(i, mid) <= b[i] + k){
                    rr = mid;
                    Left = mid + 1;
                }else{
                    Right = mid - 1;
                }       
            }
            rr = min(rr, r[i]);
            if(lr != -1 && ll != -1 && rr != -1)ans += 1LL * max(lr - ll + 1, 0) * max(rr - i + 1, 0);
            if(rr != -1 && rl != -1 && ll != -1)ans += 1LL * max(rr - rl + 1, 0) * max(i - ll + 1, 0);
            if(ll != -1 && lr != -1 && rl != -1 && rr != -1) ans -= 1LL * max(lr - ll + 1, 0) * max(rr - rl + 1, 0);
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}
