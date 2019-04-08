#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int T;
int n;
const int maxn = 1e5 + 5;

int a[maxn],b[maxn],c[maxn];


int main(){
	cin >> T;
	int cas = 0;
	while(T--){
		printf("Case #%d: ",++cas);
		cin >> n;
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
		}
		int n1 = 0,n2 = 0;
		for(int i = 1;i <= n;i++){
			if(i & 1){
				b[++n1] = a[i];
			}else{
				c[++n2] = a[i];
			}
		}
		sort(b + 1,b + 1 + n1);
		sort(c + 1,c + 1 + n2);
		for(int i = 1,j = 1,k = 1;i <= n;i++){
			if(i & 1){
				a[i] = b[j++];
			}else{
				a[i] = c[k++];
			}
		}	
		int ans = -1;
		for(int i = 1;i < n;i++){
			if(a[i] > a[i + 1]){
				ans = i - 1;
				break;
			}
		}
		if(ans == -1) printf("OK\n");
		else printf("%d\n",ans);
	}
	return 0;
}

