#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;

void solve(){
    int n,f,k;
    cin >> n >> f >> k;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int t=a[f-1];
    sort(a,a+n,greater<int>());
    int fl=0;
    for(int i=0;i<n;i++){
        if(a[i]==t) fl++;
    }
    if(a[k-1]>t) cout << "NO\n";
    else if(a[k-1]==t&&k<n&&a[k]==t) cout << "MAYBE\n";
    else cout << "YES\n";

}
#undef int
int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
