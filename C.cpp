#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;

// y =ax+b;
// x=1 y=1; 1 = a+b
// x=2 y=3; 3 = 2a+b
// a = (y2-y1)/(x2-x1);
// b = y1-a*x1;
// y = 1,5x;
// y = -1,5*x+6;
// y = -1*x+5;
// x = (b1-b2)/(a2-a1);
// y = -1,5*x+6;
// if y2<y<y1 x2<x<x1
pair<float,float> cal(float x1, float x2, float y1, float y2){
    float a=0;
    if(x2!=x1){
        a=(y2-y1)/(x2-x1);
    }
    float b = y1-x1*a;
    return pair<float,float> (a,b);
}

pair<float,float> cal2(float a1, float a2, float b1, float b2){
    float x=0;
    if(a1!=a2){
         x =(b2-b1)/(a1-a2);
    }
    float y = a1*x+b1;
    return pair<float,float> (x,y);
}

void solve() {
    int x1,x2,y1,y2,z1,z2;
    int x01,x02,y01,y02,z01,z02;
    cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
    cin >> x01 >> x02 >> y01 >> y02 >> z01 >> z02;
//    if(x1==x01&&x2==x02&&y1==y01&&y2==y02&&z1==z01&&z2==z02){
//        cout << "YES" << endl;
//        return;
//    }
    pair<float,float> t1,t2,t3;
    if(x1!=y1||(x1==y1&&x2==y2))  t1 = cal(x1,y1,x2,y2);
    if(x1!=z1||(x1==z1&&x2==z2))  t2 = cal(x1,z1,x2,z2);
    if(z1!=y1||(z1==y1&&z2==y2))  t3 = cal(z1,y1,z2,y2);
    if(x01!=x02) {
        pair<float,float> t4 = cal(x01,y01,x02,y02);
        if((x1!=y1||(x1==y1&&x2==y2))&&(t4.first!=t1.first||(t4.first==t1.first&&t4.second==t1.second))){
            pair<float,float> t = cal2(t1.first,t4.first,t1.second,t4.second);
            if(min(x01,y01)<=t.first && t.first<=max(x01,y01) && min(x02,y02)<= t.second && t.second<=max(x02,y02)) {
                cout << "YES" << endl;
                return;
            }
        }
        if((x1!=z1||(x1==z1&&x2==z2))&&(t4.first!=t2.first||(t4.first==t2.first&&t4.second==t2.second))){
            pair<float,float> t = cal2(t2.first,t4.first,t2.second,t4.second);
            if(min(x01,y01)<=t.first && t.first<=max(x01,y01) && min(x02,y02)<= t.second && t.second<=max(x02,y02)) {
                cout << "YES" << endl;
                return;
            }
        }
        if((z1!=y1||(z1==y1&&z2==y2))&&(t4.first!=t3.first||(t4.first==t3.first&&t4.second==t3.second)) ){
            pair<float,float> t = cal2(t3.first,t4.first,t3.second,t4.second);
            if(min(x01,y01)<=t.first && t.first<=max(x01,y01) && min(x02,y02)<= t.second && t.second<=max(x02,y02)) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    if(x01!=z01) {
        pair<float,float>  t5 = cal(x01,z01,x02,z02);
        if((t5.first!=t1.first||(t5.first==t1.first&&t5.second==t1.second)) && (x1!=y1||(x1==y1&&x2==y2))){
            pair<float,float> t = cal2(t1.first,t5.first,t1.second,t5.second);
            if(min(x01,z01)<=t.first && t.first<=max(x01,z01) && min(x02,z02)<= t.second && t.second<=max(x02,z02)) {
                cout << "YES" << endl;
                return;
            }
        }
        if((t5.first!=t2.first||(t5.first==t2.first&&t5.second==t2.second)) && (x1!=z1||(x1==z1&&x2==z2))){
            pair<float,float> t = cal2(t2.first,t5.first,t2.second,t5.second);
            if(min(x01,z01)<=t.first && t.first<=max(x01,z01) && min(x02,z02)<= t.second && t.second<=max(x02,z02)) {
                cout << "YES" << endl;
                return;
            }
        }
//        cout << z1 << " " << y1 << " " << z2 << " " << y2 << endl;
//        cout << t5.first << " " << t3.first << endl;
//        cout << t5.second << " " << t3.second << endl;
        if((t5.first!=t3.first||(t5.first==t3.first&&t5.second==t3.second)) && (z1!=y1||(z1==y1&&z2==y2))){
            pair<float,float> t = cal2(t3.first,t5.first,t3.second,t5.second);
//            cout << x01 << " " << z01 << " " << x02 << " " << z02  << endl;
//            cout << t.first << " " << t.second << endl;
            if(min(x01,z01)<=t.first && t.first<=max(x01,z01) && min(x02,z02)<= t.second && t.second<=max(x02,z02)) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    if(z01!=y01) {
        pair<float,float> t6 = cal(z01,y01,z02,y02);
        if((t6.first!=t1.first||(t6.first==t1.first&&t6.second==t1.second)) && (x1!=y1||(x1==y1&&x2==y2))){
            pair<float,float> t = cal2(t1.first,t6.first,t1.second,t6.second);
            if(min(z01,y01)<=t.first && t.first<=max(z01,y01) && min(z02,y02)<= t.second && t.second<=max(z02,y02)) {
                cout << "YES" << endl;
                return;
            }
        }
        if((t6.first!=t2.first||(t6.first==t2.first&&t6.second==t2.second)) && (x1!=z1||(x1==z1&&x2==z2))){
            pair<float,float> t = cal2(t2.first,t6.first,t2.second,t6.second);
            if(min(z01,y01)<=t.first && t.first<=max(z01,y01) && min(z02,y02)<= t.second && t.second<=max(z02,y02)) {
                cout << "YES" << endl;
                return;
            }
        }
        if((t6.first!=t3.first||(t6.first==t3.first&&t6.second==t3.second)) && (z1!=y1||(z1==y1&&z2==y2))){
            pair<float,float> t = cal2(t3.first,t6.first,t3.second,t6.second);
            if(min(z01,y01)<=t.first && t.first<=max(z01,y01) && min(z02,y02)<= t.second && t.second<=max(z02,y02)) {
                cout << "YES" << endl;
                return;
            }
        }
    }
//    if(z01!=z02) pair<float,float> t6 = cal(z01,y01,z02,y02);
    cout << "NO" << endl;


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
