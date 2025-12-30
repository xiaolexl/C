#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Employee {
    int a, b, id;
};

// 验证选人集合是否满足题意
bool validate(const vector<Employee>& employees, const vector<int>& selected) {
    unordered_map<int, Employee> mp;
    for (auto& e : employees) mp[e.id] = e;

    vector<int> ranks;
    for (int id : selected) {
        ranks.push_back(mp[id].a);
    }
    sort(ranks.begin(), ranks.end());

    for (int id : selected) {
        int rank = mp[id].a;
        int higher_count = (int)(ranks.end() - upper_bound(ranks.begin(), ranks.end(), rank));
        if (higher_count > mp[id].b) return false;
    }
    return true;
}

// 解析输入字符串得到员工列表
vector<Employee> parse_employees(const string& input) {
    istringstream in(input);
    int T; in >> T;
    vector<Employee> employees;
    for (int _ = 0; _ < T; _++) {
        int n; in >> n;
        for (int i = 1; i <= n; i++) {
            int a, b; in >> a >> b;
            employees.push_back({a,b,i});
        }
    }
    return employees;
}

// 解析输出，得到选中人数
int parse_max_count(const string& output) {
    istringstream in(output);
    int T; T = 1;
    int max_c = 0;
    while (T--) {
        int c; in >> c;
        max_c = c;
        for (int i = 0; i < c; i++) {
            int x; in >> x;
        }
    }
    return max_c;
}

// 解析输出，得到选中员工id集合
vector<int> parse_selected_ids(const string& output) {
    istringstream in(output);
    int T; T = 1;
    vector<int> selected;
    while (T--) {
        int c; in >> c;
        for (int i = 0; i < c; i++) {
            int x; in >> x;
            selected.push_back(x);
        }
    }
    return selected;
}

// 随机生成测试样例字符串，n最大值默认为1000
string gen_random_test_case(int max_n = 1000) {
    static mt19937 rng((unsigned) chrono::steady_clock::now().time_since_epoch().count());
    int n = uniform_int_distribution<int>(1, max_n)(rng);
    ostringstream out;
    out << "1\n" << n << "\n";
    for (int i = 0; i < n; i++) {
        int a = uniform_int_distribution<int>(1, n)(rng);
        int b = uniform_int_distribution<int>(0, n - 1)(rng);
        out << a << " " << b << "\n";
    }
    return out.str();
}

// --------- 你的【正确代码】封装 ----------------
string solve_correct(string input) {
    istringstream in(input);
    ostringstream out;

    int T; in >> T;
    while (T--) {
        int n; in >> n;
        vector<vector<pair<int,int>>> groups(n+1);
        for (int i = 1; i <= n; i++) {
            int a, b; in >> a >> b;
            groups[a].emplace_back(b, i);
        }
        for (int i = 1; i <= n; i++) {
            sort(groups[i].begin(), groups[i].end(), [](auto &x, auto &y) {
                return x.first > y.first;
            });
        }
        int l=0, r=n, ans=0;
        auto check = [&](int x) {
            if (x == 0) return true;
            int s=0;
            for (int i=1; i<=n; i++) {
                if (s >= x) return true;
                if (groups[i].empty()) continue;
                int m = (int)groups[i].size();
                int high = min(x - s, m);
                int t_max = 0;
                for (int t_candidate = high; t_candidate >= 1; t_candidate--) {
                    if (groups[i][t_candidate-1].first >= (x - s - t_candidate)) {
                        t_max = t_candidate;
                        break;
                    }
                }
                s += t_max;
            }
            return s >= x;
        };
        while (l <= r) {
            int mid = (l+r)/2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        out << ans << "\n";
        vector<int> selected;
        int s=0;
        for (int i=1; i<=n && s<ans; i++) {
            if (groups[i].empty()) continue;
            int m = (int)groups[i].size();
            int high = min(ans - s, m);
            int t_max = 0;
            for (int t_candidate = high; t_candidate >= 1; t_candidate--) {
                if (groups[i][t_candidate-1].first >= (ans - s - t_candidate)) {
                    t_max = t_candidate;
                    break;
                }
            }
            for (int j=0; j<t_max; j++) selected.push_back(groups[i][j].second);
            s += t_max;
        }
        for (size_t i=0; i<selected.size(); i++) {
            if (i > 0) out << " ";
            out << selected[i];
        }
        out << "\n";
    }
    return out.str();
}

// --------- 你的【提交代码】封装 ----------------
string solve_your_code(string input) {
    istringstream in(input);
    ostringstream out;
    using ll = long long;
    const ll Q = 2e5 + 9;

    struct op {
        vector<ll> bh;
        ll zj{};
        ll ds{};
        ll rs{};
    };

    int T; in >> T;
    while (T--) {
        ll n; in >> n;
        vector<op> a(n+2);
        set<ll> st;
        vector<vector<op>> b(n+2);

        auto cmp = [](const op& l, const op& r) {
            if (l.zj == r.zj) return l.ds > r.ds;
            return l.zj < r.zj;
        };

        for (int i = 1; i <= n; i++) {
            a[i].bh.clear();
            a[i].bh.push_back(i);
            in >> a[i].zj >> a[i].ds;
            a[i].rs = 1;
            b[a[i].zj].clear();
            st.insert(a[i].zj);
        }

        sort(a.begin()+1, a.begin()+1+n, cmp);
        vector<ll> p;
        for (int i = 1; i <= n; i++) {
            p.push_back(a[i].bh.front());
            if (i < n && a[i].zj == a[i+1].zj && a[i].ds == a[i+1].ds) {
                a[i+1].rs += a[i].rs;
            } else {
                b[a[i].zj].push_back({p, a[i].zj, a[i].ds, a[i].rs});
                p.clear();
            }
        }

        auto check = [&](ll x) {
            ll num = 0;
            for (auto &i : st) {
                ll tp = 0;
                ll now = 0;
                for (const auto &j : b[i]) {
                    now += j.rs;
                    if ((j.ds + now) >= (x - num)) {
                        tp = now;
                    }
                }
                num += tp;
            }
            return num >= x;
        };

        ll l = 1, r = n, ans = 0;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (check(mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }

        vector<ll> cnt;
        ll num = 0, ip = 0;
        for (auto &i : st) {
            ll tp = 0, now = 0;
            for (const auto &j : b[i]) {
                now += j.rs;
                if ((j.ds + now) >= (ans - num)) {
                    tp = now;
                }
            }
            num += tp;
            ll rp = 0;
            for (auto &j : b[i]) {
                for (auto &k : j.bh) {
                    if (ip < ans && rp < tp) {
                        cnt.push_back(k);
                        ip++;
                        rp++;
                    }
                }
            }
        }
        out << ans << "\n";
        for (size_t i = 0; i < cnt.size(); i++) {
            if (i > 0) out << " ";
            out << cnt[i];
        }
        out << "\n";
    }
    return out.str();
}

// =============================== 主程序 ==============================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cnt = 0;
    while (true) {
        test_cnt++;
        string test_input = gen_random_test_case(1000);

        string out_correct = solve_correct(test_input);
        string out_your = solve_your_code(test_input);

        int max_correct = parse_max_count(out_correct);
        int max_your = parse_max_count(out_your);

        vector<Employee> employees = parse_employees(test_input);
        vector<int> your_selected = parse_selected_ids(out_your);

        if (max_correct != max_your) {
            cout << "【人数不一致】\n输入数据:\n" << test_input;
            cout << "正确解人数: " << max_correct << "\n你的解人数: " << max_your << "\n";
            cout << "正确解输出:\n" << out_correct << "\n你的解输出:\n" << out_your << "\n";
            break;
        }

        if (!validate(employees, your_selected)) {
            cout << "【你的解不满足题目限制】\n输入数据:\n" << test_input;
            cout << "你的解人数: " << max_your << "\n选中员工ID: ";
            for (auto x : your_selected) cout << x << " ";
            cout << "\n你的解输出:\n" << out_your << "\n";
            break;
        }

        if (test_cnt % 1000 == 0) {
            cout << "已测试 " << test_cnt << " 次，暂未发现差异或不满足\n";
        }
    }

    return 0;
}

