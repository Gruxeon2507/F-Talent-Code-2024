#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;

void solve() {
    string s;
    cin >> s;
    int size = s.size();
    int n;
    cin >> n;
    vector<pair<char,int>> a(n);
    unordered_map<char,int> m;
    unordered_map<char,int> m2;
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
        m[a[i].first]=a[i].second;
        m2[a[i].first]=0;
    }
    int ans=0;
    for(int i=0;i<size;i++){
        if(m[s[i]]!=0){
            m2[s[i]]++;
            if(m2[s[i]]%m[s[i]]==1){
                ans+=2;
                m2[s[i]]++;
            }else ans++;
        }else{
            ans++;
        }
    }
//    for(auto it:m2){
//        cout << it.first << " " << it.second << endl;
//    }
//    cout << size << endl;
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
