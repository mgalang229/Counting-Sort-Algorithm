#include <bits/stdc++.h>

using namespace std;

void cntSort(int a[], int n){
	int op[10];
	int cnt[10];
	int max = a[0];
	for(int i = 0; i < n; i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	for(int i = 0; i <= max; i++){
		cnt[i] = 0;
	}
	for(int i = 0; i < n; i++){
		cnt[a[i]]++;
	}
	for(int i = 1; i <= max; i++){
		cnt[i] += cnt[i-1];
	}
	for(int i = n-1; i >= 0; i--){
		op[cnt[a[i]]-1] = a[i];
		cnt[a[i]]--;
	}
	for(int i = 0; i < n; i++){
		a[i] = op[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a[] = {4,2,2,8,3,3,1};
	int n = sizeof(a)/sizeof(a[0]);
	cntSort(a, n);
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}
