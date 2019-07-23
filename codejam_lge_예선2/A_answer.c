#include <stdio.h>
 
int n;
int d;
int x[500][500];
 
void input() {
    scanf("%d %d", &n, &d);
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &x[j][i]);
        }
    }
}
 
int get(int level, int index) {
    switch (index) {
        case 0:
            return x[level][level];
        case 1:
            return x[n / 2][level];
        case 2:
            return x[n - level - 1][level];
        case 3:
            return x[n - level - 1][n / 2];
        case 4:
            return x[n - level - 1][n - level - 1];
        case 5:
            return x[n / 2][n - level - 1];
        case 6:
            return x[level][n - level - 1];
        case 7:
            return x[level][n / 2];
        default:
            return -1;
    }
}
 
void set(int level, int index, int value) {
    switch (index) {
        case 0:
            x[level][level] = value;
            break;
        case 1:
            x[n / 2][level] = value;
            break;
        case 2:
            x[n - level - 1][level] = value;
            break;
        case 3:
            x[n - level - 1][n / 2] = value;
            break;
        case 4:
            x[n - level - 1][n - level - 1] = value;
            break;
        case 5:
            x[n / 2][n - level - 1] = value;
            break;
        case 6:
            x[level][n - level - 1] = value;
            break;
        case 7:
            x[level][n / 2] = value;
            break;
        default:
            break;
    }
}
 
void process() {
    int move = d / 45;
 
    for (int i = 0; i < n / 2; ++i) {
    int value[8];
        for (int j = 0; j < 8; ++j) {
            value[j] = get(i, j);
        }
        for (int j = 0; j < 8; ++j) {
            set(i, (8 + j + move) % 8, value[j]);
        }
    }
}
 
void output() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", x[j][i]);
        }
        printf("\n");
    }
}
 
int main() {
    int t;
    scanf("%d", &t);
 
    for (int i = 0; i < t; ++i) {
        input();
        process();
        output();
    }
 
    return 0;
}