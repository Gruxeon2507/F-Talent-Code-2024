#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;

void solve() {
    int x,y;
    cin >> x >> y;
    int mx=min(x,y);
    int s = x*y;
    int ans=0;
    while (mx>0){
        int t=mx*mx;
        int count=0;
        while(s>=t){
            s-=t;
//            cout << t << endl;
            ans++;
            count++;
        }
        if(x>y&&x>mx&&x>0){
            while(x>mx) {
                x=x-mx;
            }
            mx=x;
        }else if(x<y&&y>mx&&y>0){
            while(y>mx) {
                y=y-mx;
            }
            mx = y;
        }else{
            mx--;
        }
//        cout << mx << endl;
    }
    cout << ans << endl;
}

#undef int
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
//    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
