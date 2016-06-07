#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long ll;

struct State {
    ll a = 0;
    ll b = 0;
    State() {
        a = 0;
        b = 0;
    }
};

State filla(State s, ll M, ll N) {
    s.a = M;
    return s;
}

State fillb(State s, ll M, ll N) {
    s.b = N;
    return s;
}

State poura(State s, ll M, ll N) {
    s.a = 0;
    return s;
}

State pourb(State s, ll M, ll N) {
    s.b = 0;
    return s;
}

State pouratob(State s, ll M, ll N) {
    if(s.a + s.b <= N) {
        s.b = s.a + s.b;
        s.a = 0;
    } else {
        s.a = s.a + s.b - N;
        s.b = N;
    }
    return s;
}

State pourbtoa(State s, ll M, ll N) {
    if(s.a + s.b <= M) {
        s.a = s.a + s.b;
        s.b = 0;
    } else {
        s.b = s.a + s.b - M;
        s.a = M;
    }
    return s;
}

void calc_procedure(ll cnt, ll index, vector<ll> &change) {
    while(cnt) {
        change.push_back(index % 6);
        index = index / 6;
        cnt--;
    }
    reverse(change.begin(), change.end());
}

void prll_procedure(const vector<ll> &change, const ll M, const ll N) {
    State tmp;
    for(unsigned int i = 0; i < change.size(); i++) {
        cout << change[i] << "->";
        switch(change[i]) {
        case 0: {
            cout << "filla" << ":       ";
            tmp = filla(tmp, M, N);
            cout << tmp.a << "--"<< tmp.b << endl;
            break;
        }
        case 1: {
            cout << "fillb" <<  ":      ";
            tmp = fillb(tmp, M, N);
            cout << tmp.a << "--" <<tmp.b << endl;
            break;
        }
        case 2: {
            cout << "poura" <<  ":      ";
            tmp = poura(tmp, M, N);
            cout << tmp.a << "--" <<tmp.b << endl;
            break;
        }
        case 3: {
            cout << "pourb" <<  ":      ";
            tmp = pourb(tmp, M, N);
            cout << tmp.a << "--" <<tmp.b << endl;
            break;
        }
        case 4: {
            cout << "pouratob" <<  ":       ";
            tmp = pouratob(tmp, M, N);
            cout << tmp.a << "--" <<tmp.b << endl;
            break;
        }
        case 5: {
            cout << "pourbtoa" <<  ":       ";
            tmp = pourbtoa(tmp, M, N);
            cout << tmp.a << "--" <<tmp.b << endl;
            break;
        }
        }
    }
}

void test() {
    ll M, N;
    ll target;
    State st;
    queue<State> q;
    queue<State> r;
    q.push(st);
    while(cin >> M >> N >> target) {
        ll cnt = -1;
        while(!q.empty()) {
            cnt++;
            ll index = -1;
            cout << q.size() << endl;
            while(!q.empty()) {
                index++;
                State s = q.front();
                q.pop();
                if(s.a == target || s.b == target) {
                    cout << "minimum operation number:" << cnt << endl;
                    vector<ll> change;
                    calc_procedure(cnt, index, change);
                    prll_procedure(change, M, N);
                    return;
                }
                r.push(filla(s, M, N));
                r.push(fillb(s, M, N));
                r.push(poura(s, M, N));
                r.push(pourb(s, M, N));
                r.push(pouratob(s, M, N));
                r.push(pourbtoa(s, M, N));
            }
            swap(q, r);
        }
    }
}

int main() {
    test();
    return 0;
}
