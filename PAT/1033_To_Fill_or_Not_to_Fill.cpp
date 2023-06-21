#include <bits/stdc++.h>
using namespace std;
struct Station {
    double D;
    double price;
} stations[500];
bool cmp(Station s1, Station s2) {
    return s1.D < s2.D;
}
int main() {
    //freopen("in.in", "r", stdin);
    double C, D, Davg;
    int N;
    scanf("%lf %lf %lf %d", &C, &D, &Davg, &N);
    for(int i = 0; i < N; i++) {
        scanf("%lf %lf", &stations[i].price, &stations[i].D);
    }
    stations[N].price = 0.0;
    stations[N].D = D;
    N++;
    sort(stations, stations+N, cmp);
    if(stations[0].D != 0.0) {
        cout << "The maxium travel distance = 0.00" << endl;
    } else {
        double MAX = C * Davg; // 初始状态下加满油能行驶的最远距离
        double gas = 0.0; // 当前汽油
        double total = 0.0; // 目标汽油
        int i = 0;
        Station *current = &stations[0];
        Station *target = NULL;
        while(i < N) {
            current = &stations[i];
            target = NULL;
            i++;
            double fastDist = current->D + MAX;
            while(i < N && stations[i].D <= fastDist) {
                if(stations[i].price < current->price) {
                    target = &stations[i];
                    break;
                }
                if(target == NULL || stations[i].price <= target->price) {
                    target = &stations[i];
                }                
                i++;
            }
            if(target == NULL) break;
            double need = 0.0, move = target->D - current->D;
            if(target->price < current->price) {
                need = max(0.0, move / Davg - gas);
                gas = 0.0;
            } else {
                need = C - gas;
                gas = C - move / Davg;
            }
            total += need * current->price;
            i = (int)(target - stations);
        }
        if(i < N){
            printf("The maximum travel distance = %.2lf", current->D + MAX);
        } else {
            printf("%.2lf", total);
        }
    }
    return 0;
}