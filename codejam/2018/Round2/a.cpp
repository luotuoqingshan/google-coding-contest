#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int T;
const int maxn = 105;
int n;
int b[maxn];
int l[maxn],r[maxn];
char s[maxn][maxn];
int main(){
	cin >> T;
	int cas = 0;
	while(T--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			scanf("%d",b + i);
		}
		bool flag = true;
		if(b[1] == 0 || b[n] == 0) flag = false;
		printf("Case #%d: ",++cas);
		if(flag){
			int now = 0;
			for(int i = 1;i <= n;i++){
				if(b[i] != 0){
					l[i] = i,r[i] = i;
					for(int j = now + 1;j <= now + b[i];j++){
						l[i] = min(l[i],j);
						r[i] = max(r[i],j);	
					}
					now += b[i];
				}
			}	
			int ans = 0;
			for(int i = 1;i <= n;i++){
				if(b[i] != 0){
					ans = max(ans,max(i - l[i] + 1,r[i] - i + 1));
				}
			}
			cout << ans << endl;
			for(int i = 1;i <= ans;i++){
				for(int j = 1;j <= n;j++){
					s[i][j] = '.';
				}
			}
			for(int i = 1;i <= n;i++){
				if(b[i] != 0){
					for(int j = l[i];j < i;j++){
						s[j - l[i] + 1][j] = '\\';
					}
					for(int j = i + 1;j <= r[i];j++){
						s[r[i] - j + 1][j] = '/';
					}
				}
			}
			for(int i = 1;i <= ans;i++){
				for(int j = 1;j <= n;j++){
					putchar(s[i][j]);
				}
				puts("");
			}
		}else{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}

