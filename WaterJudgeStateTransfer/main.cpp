#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

struct State {
    ll a = 0;
    ll b = 0;
    State(int x = 0, int y = 0) {
        a = x;
        b = y;
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

vector<State> ergodicstate(State s, ll M, ll N) {
    vector<State> next_state(6, State());
    State (*fp[6])(State, ll, ll) = {filla, fillb, poura, pourb, pouratob, pourbtoa};
    State (*p)(State, ll, ll) = NULL;
    State tmp;
    for(int i = 0; i < 6; i++) {
        p = fp[i];
        next_state[i] = (*p)(s, M, N);
        tmp = next_state[i];
    }
    return next_state;
}

string findOperation(int n) {
    string str[6] = {"filla", "fillb", "poura", "pourb", "pouratob", "pourbtoa"};
    string tmp;
    if(n < 6 && n >= 0)
        return str[n];
    else
        return tmp;
}

void test() {
    ll M, N;
    ll target;
    State st;
    while(cin >> M >> N >> target) {
        vector<vector<int>> IsVisited(M+1, vector<int>(N+1,false));
        vector<vector<State>> IsLastVisited(M+1, vector<State>(N+1,State()));
        vector<vector<int>> IsLastOperatoin(M+1, vector<int>(N+1,0));
        IsVisited[0][0] = 1;
        int step = 0;
        while(true) {
            step++;
            bool Is_new_visited = false;
            bool Isfind = false;
            vector<int> result;
            for(int i = 0; i <= M; i++) {
                for(int j = 0; j <= N; j++) {
                    if(IsVisited[i][j] == step) {
                        vector<State> next_state = ergodicstate(State(i,j), M, N);
                        for(unsigned int s = 0; s < next_state.size(); s++) {
                            if(IsVisited[next_state[s].a][next_state[s].b] == 0) {
                                Is_new_visited = true;
                                IsVisited[next_state[s].a][next_state[s].b] = step + 1;
                                IsLastVisited[next_state[s].a][next_state[s].b] = State(i,j);
                                IsLastOperatoin[next_state[s].a][next_state[s].b] = s;
                                if(next_state[s].a == target || next_state[s].b == target) {
                                    cout << next_state[s].a << "--" << next_state[s].b << endl;
                                    Isfind = true;
                                    State tmp = next_state[s];
                                    while(tmp.a || tmp.b) {
                                        result.push_back(IsLastOperatoin[tmp.a][tmp.b]);
                                        tmp = IsLastVisited[tmp.a][tmp.b];
                                    }
                                    reverse(result.begin(), result.end());
                                    break;
                                }
                            }
                        }
                    }
                    if(Isfind) break;
                }
                if(Isfind) break;
            }
            if(Is_new_visited == false) {
                cout << "No solution \n";
                break;
            }
            if(Isfind) {
                State tmp;
                State (*fp[6])(State, ll, ll) = {filla, fillb, poura, pourb, pouratob, pourbtoa};
                cout << "Minimum Step:" << step << endl;
                for(unsigned int i = 0; i < result.size(); i++) {
                    tmp = (*fp[result[i]])(tmp, M, N);
                    cout << findOperation(result[i]) << endl;
                    cout << tmp.a << "---" << tmp.b << endl;
                }
                break;
            }
        }
    }
}

int main() {
    test();
    return 0;
}
