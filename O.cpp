#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

void solve() {
    int n,k,s;
    cin >> n >> k >> s;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> ans;

    for(int i=0;i<n-k+1;i+=s){
        vector<int> t;
        for(int j=0;j<n-k+1;j+=s){
            int mx=a[i][j];
            for(int z=i;z<i+k;z++){
                for(int m=j;m<j+k;m++){
                    if(mx<a[z][m]){
                        mx=a[z][m];
                    }
                }
            }
            t.push_back(mx);
        }
        ans.push_back(t);
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans.size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
//    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}
