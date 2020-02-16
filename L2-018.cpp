#include<cmath>
#include <cstdio>
using namespace std;
int nonNegativeNum(double c[], int start) {
    int cnt = 0;
    for (int i = start; i >= 0; i--)
        if (abs(c[i]) + 0.05 >= 0.1) cnt++;
    return cnt;
}
void printPoly(double c[], int start) {
    printf("%d", nonNegativeNum(c, start));
    if (nonNegativeNum(c, start) == 0) printf(" 0 0.0");
    for (int i = start; i >= 0; i--)
        if (abs(c[i]) + 0.05 >= 0.1)
            printf(" %d %.1f", i, c[i]);
}
double c1[3000], c2[3000], c3[3000];
int main() {
    int m = 0, n = 0, t = 0, max1 = -1, max2= -1;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        max1 = max1 > t ? max1 : t;
        scanf("%lf", &c1[t]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        max2 = max2 > t ? max2 : t;
        scanf("%lf", &c2[t]);
    }
    int t1 = max1, t2 = max2;
    while (t1 >= t2) {
        double c = c1[t1] / c2[t2];
        c3[t1 - t2] = c;//记录的商 我们只需要计算最高项的差就好了
        for (int i = t1, j = t2; j >= 0; j--, i--) c1[i] -= c2[j] * c;//正常的剑法计算，长除法
        while (abs(c1[t1]) < 0.000001) t1--;//得到下一个位置
    }
    printPoly(c3, max1 - max2);
    printf("\n");
    printPoly(c1, t1);
    return 0;
}
