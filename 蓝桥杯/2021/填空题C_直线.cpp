#include <bits/stdc++.h>
using namespace std;
const int n = 2;
const int m = 3;
struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
}; // 点
struct Line {
    Point a, b; // 包含两个点
    Line(Point x, Point y) {
        this->a = x;
        this->b = y;
    }
}; // 直线
vector<Line> LineList;
double Dis(Point p0, Point p1) {
    return sqrt((p0.x - p1.x) * (p0.x - p1.x) + (p0.y - p1.y) * (p0.y - p1.y));
}
bool checkPointInLine(Line L, Point P) {
    double dis[3];
    dis[0] = Dis(L.a, P);
    dis[1] = Dis(L.b, P);
    dis[2] = Dis(L.a, L.b);
    sort(dis, dis+3);
    if(fabs(dis[0] + dis[1] - dis[2]) < 1e-5) {
        return true;
    } else {
        return false;
    }
}
bool checkLineRepeat(Line L) { // 检查当前直线是否已经存在
    for(int i = 0; i < LineList.size(); i++) {
        if(checkPointInLine(LineList[i], L.a) && checkPointInLine(LineList[i], L.b)) {
            return true;
        }
    }
    return false;
}
int main() {
    int ans = 0;
    vector<Point> pointList;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            pointList.push_back(Point(i, j)); // 把所有点的坐标记录下来
        }
    }
    // 开始暴力枚举所有坐标
    for(int i = 0; i < pointList.size(); i++) {
        for(int j = i+1; j < pointList.size(); j++) {
            Line curLine = Line(pointList[i], pointList[j]);
            if(!checkLineRepeat(curLine)) {
                ans++;
                LineList.push_back(curLine);
            }
        }  
    }
    cout << ans << endl;
    return 0;
}