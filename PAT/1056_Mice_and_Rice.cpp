#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
struct Node {
    int weight;
    int rank;
} mouses[N];
int main() {
    int NP, NG;
    queue<int> q;
    cin >> NP >> NG;
    for(int i = 0; i < NP; i++) {
        cin >> mouses[i].weight;
    }
    for(int i = 0; i < NP; i++) {
        int temp;
        cin >> temp;
        q.push(temp);
    }
    int group, cnt, maxWeight, maxIndex;
    while((cnt = (int)q.size()) > 1) {
        group = cnt / NG + (cnt % NG == 0 ? 0 : 1);
        for(int i = 0; i < group; i++) {
            maxWeight = -1;
            maxIndex = -1;
            for(int j = 0; j < NG && i * NG + j < cnt; j++) {
                mouses[q.front()].rank = group + 1;
                if(mouses[q.front()].weight > maxWeight) {
                    maxIndex = q.front();
                    maxWeight = mouses[q.front()].weight;
                }
                q.pop();
            }
            q.push(maxIndex);
        }
    }
    mouses[q.front()].rank = 1;
    cout << mouses[0].rank;
    for(int i = 1; i < NP; i++) {
        cout << " " << mouses[i].rank;
    }
    return 0;
}