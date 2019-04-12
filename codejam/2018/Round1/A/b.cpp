#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int T;

int R, C;
typedef long long LL;
LL B;
const int maxn = 1005;

LL M[maxn], S[maxn], P[maxn];

LL num[maxn];

LL cal(LL t){
    for(int i = 1;i <= C;i++){
        num[i] = min(M[i], max(0LL, (t - P[i])) / S[i]);
    }
    sort(num + 1, num + 1 + C);
    LL ret = 0;
    for(int i = C - R + 1;i <= C;i++){
        ret += num[i];
    }
    return ret;
}

int main(){
    cin >> T;
    int cas = 0;
    while(T--){
        cin >> R >> B >> C;
        for(int i = 1;i <= C;i++){
            cin >> M[i] >> S[i] >> P[i];
        }
        LL l = 0, r = 2e18;
        while(l < r){
            LL mid = (l + r) / 2;
            if(cal(mid) >= B){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        cout << "Case #" << ++cas << ": " << l << endl;
    }
    return 0;
}


