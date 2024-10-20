#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

//3
//2 3 1 1
//4 1 -2 -2
//3 2 3 3

// 4 1 -2 -2
// 2 3 1 1
// 4 6 2 2
// 0 -5 -4 -4
// 3 2 3 3
void cal(vector<vector<double>>& a, vector<double>& x, int n) {
    for(int i=0;i<n;i++) {
        for(int k=i+1;k<n;k++){
            if(fabs(a[i][i])<fabs(a[k][i])) {
                swap(a[i],a[k]);
            }
        }
        for(int k=i+1;k<n;k++) {
            double t = a[k][i]/a[i][i];
            for(int j=0;j<=n;j++) {
                a[k][j]-=t*a[i][j];
            }
        }
    }
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<=n;j++) {
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
    for (int i=n-1;i>=0;i--) {
        x[i]=a[i][n];
        for (int j=i+1;j<n;j++) {
            x[i]-=a[i][j]*x[j];
        }
        x[i]/=a[i][i];
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n + 1));
    vector<double> x(n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<=n;j++) {
            cin >> a[i][j];
        }
    }
    cal(a, x, n);
    for(int i=0;i<n;i++){
        if(isnan(x[i])){
            cout << "ERROR" << endl;
            return;
        }
        cout << fixed << setprecision(6) << x[i] << endl;
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
