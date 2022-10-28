#include <bits/stdc++.h>
using namespace std;

vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;

    for (int v = t; v <= s; v = p[v])
        path.emplace_back(v);
    path.emplace_back(s);

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    printf("Program execution is successfull\n");
}
