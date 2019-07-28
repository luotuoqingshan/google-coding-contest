#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int T;
const int maxn = 1e5 + 5;
multiset<int> Left1, Left2, Right1, Right2;

int k, n;
int x[maxn];
int c[maxn];
pair<int, int> p[maxn];


int main(){
    cin >> T;
    int cas = 0;
    while(T--){
        Left1.clear();
        Left2.clear();
        Right1.clear();
        Right2.clear();
        cin >> k >> n;
        k++;
        for(int i = 1;i <= n;i++){
            scanf("%d", &x[i]);
        }        
        for(int i = 1;i <= n;i++){
            scanf("%d", &c[i]);
        }
        for(int i = 1;i <= n;i++){
            p[i].first = x[i];
            p[i].second = c[i];
        }
        sort(p + 1, p + 1 + n);
        for(int i = 1;i <= n;i++){
            x[i] = p[i].first;
            c[i] = p[i].second;
        }
        long long ans = 1e18;
        long long suml = 0, sumr = 0;
        for(int i = 1;i <= n;i++){
            Right1.insert(c[i] + x[i]);
            sumr += c[i] + x[i];
            if(Right1.size() > (k - 1) / 2){
                auto it = Right1.end();
                it--;
                sumr -= (*it);
                Right2.insert(*it);
                Right1.erase(it);
            }                
        }
        for(int i = 1;i <= n;i++){
           auto it = Right1.lower_bound(x[i] + c[i]);
           if(*it == x[i] + c[i]){
                sumr -= x[i] + c[i];
                Right1.erase(it);
                if(Right2.size() > 0){
                    sumr += *Right2.begin();
                    Right1.insert(*Right2.begin());
                    Right2.erase(Right2.begin());
                }
           }else{
                auto it1 = Right2.lower_bound(x[i] + c[i]);
                if(it1 != Right2.end())
                    Right2.erase(it1);
           }
           if(Left1.size() == (k / 2) && Right1.size() == ((k - 1) / 2)){
               if(k & 1){
                   ans = min(ans, c[i] + suml + sumr);
               }else{
                   ans = min(ans, x[i] + c[i] + suml + sumr);
               }
           }
           Left1.insert(c[i] - x[i]);
           suml += c[i] - x[i];
           if(Left1.size() > k / 2){
               auto it2 = Left1.end();
               it2--;
               suml -= (*it2);
               Left2.insert(*it2);
               Left1.erase(it2);
           }
        }
        printf("Case #%d: ", ++cas);
        cout << ans << endl;
    }
    return 0;
}
