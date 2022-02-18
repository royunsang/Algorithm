#include <bits/stdc++.h>

using namespace std;

int arr[50][50];
int flag[50][50];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int result = 0;
int turnCnt = 0;
int direction;

void TurnLeft() {
    direction = direction - 1;
    if (direction == -1)
    {
        direction = 3;
    }
}

void Moving(int x, int y, int direction) {
    flag[x][y] = 1;
    TurnLeft();
    int nx = x + dx[direction];
    int ny = y + dy[direction];
    if (arr[nx][ny] == 0 && flag[nx][ny] == 0) {
        flag[nx][ny] = 1;
        x = nx;
        y = ny;
        result++;
        turnCnt = 0;
    }
    else turnCnt++;

    if (turnCnt == 4) {
        nx = x - dx[direction];
        ny = y - dy[direction];

        if (arr[nx][ny] == 0) {
            x = nx;
            y = ny;
        }
        else return;
        turnCnt = 0;
    }
    Moving(nx, ny, direction);
}

int main() {

    int N, M;  //(3 <= N, M <=50)
    cin >> N >> M;

    int x;
    int y;

    cin >> x >> y >> direction;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    Moving(x, y, direction);
    cout << result;

    return 0;
}