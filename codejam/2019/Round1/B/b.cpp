#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int T, W;
typedef long long LL;
LL ans[10];
int main(){
    int cas = 0;
    cin >> T >> W;
    while(T--){
        cout << 48 << endl;
        fflush(stdout);
        LL ret = 0, ret1 = 0; 
        cin >> ret;
        ans[0] = ret / (1LL << 48);
        ans[1] = (ret % (1LL << 48)) / (1LL << 24);
        cout << 210 << endl;
        fflush(stdout);
        cin >> ret1;
        ans[5] = (ret1 % (1LL << 42)) / (1LL << 35);
        ans[4] = (ret1 % (1LL << 52)) / (1LL << 42);
        ans[3] = (ret1 / (1LL << 52));
        for(LL i = 0;i <= 100;i++){
            LL sum = (1LL << 48) * ans[0] + (1LL << 24) * ans[1] + (1LL << 16) * i + (1LL << 12) * ans[3] + (1LL << 9) * ans[4] + (1LL << 8) * ans[5];
            if(sum == ret)
                ans[2] = i;
        }
        for(int i = 0;i < 6;i++){
            cout << ans[i];
            if(i == 5)
                cout << endl;
            else
                cout << " ";
        }
        fflush(stdout);
        int verdict;
        cin >> verdict;
    } 
    return 0;
}
