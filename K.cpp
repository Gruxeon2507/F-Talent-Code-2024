#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx=0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i]>mx) mx=a[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(ans<mx-a[i]){
            ans = mx-a[i];
        }
    }
    cout << ans << endl;

}

#undef int
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
