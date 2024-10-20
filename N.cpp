#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;

bool check(int n){
    int reverse=0;
    int t=n;
    while(n>0){
        reverse+=n%10;
        n/=10;
        reverse*=10;
    }
    reverse/=10;
//    cout << t << " " << reverse << endl;

    return reverse==t;
}

bool check2(int n){
    bool increase = true;
    int pre = n%10;
    while(n>10) {
        n /= 10;
        int t = n % 10;
//        cout << pre << " " << t << endl;
        if (increase && pre < t) {
            increase = false;
            pre = t;
            continue;
        } else if (!increase && pre > t) {
                pre = t;
                increase = true;
                continue;
        }
            return false;
        }

    return true;
}

void solve() {
    int a,b;
    cin >> a >> b;
    vector<int> ans;
    for(int i=a;i<=b;i++){
        if (check(i)){
            if(check2(i)){
                ans.push_back(i);
            }
        }
    }
    cout << ans.size() << endl;
    cout << "[";
    for(int i=0;i<ans.size();i++){
        if(i==ans.size()-1){
            cout << ans[i] << "]";
        }else{
            cout << ans[i] << ", ";
        }
    }
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
