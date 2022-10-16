#include <math.h>
#include <stdio.h>

void print(int arr[][30], int row, int col) {
  int i = 0, j = 0;
  for (i = 0; i <= row; i++) {
    for (j = 0; j <= col; j++) {
      if (j != 0) {
        printf(" ");
      }
      printf("%d", arr[i][j]);
    }
    printf("\n");
  }
}
int solve(int ex, int ey, int mx, int my) {
  int m_map[30][30] = {0};
  int result[30][30] = {0};
  int direction[4] = {-2, -1, 1, 2};

  int i = 0, j = 0;

  // 初始化马的位置
  m_map[mx][my] = 1;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      // 马的方向控制
      if (abs(direction[i]) == abs(direction[j])) {
        continue;
      }
      // 避免越界
      if (mx + direction[i] > 0 && mx + direction[i] < 30 &&
          my + direction[j] > 0 && my + direction[j] < 30) {
        printf("now direction %d %d\n", direction[i], direction[j]);
        m_map[mx + direction[i]][my + direction[j]] = 1;
      }
    }
  }
  // 打印马的位置
  // print(m_map, ex, ey);

  // 初始化棋盘的x轴和y轴
  for (i = 0; i <= ex; i++) {
    if (m_map[i][0] == 1) {
      break;
    }
    result[i][0] = 1;
  }
  for (i = 0; i <= ey; i++) {
    if (m_map[0][i] == 1) {
      break;
    }
    result[0][i] = 1;
  }

  // 开始遍历棋盘
  for (i = 1; i <= ex; i++) {
    for (j = 1; j <= ey; j++) {
      // 若当前位置为马,则跳过
      if (m_map[i][j] == 1) {
        continue;
      }
      // 若当前位置的左侧不为马
      if (m_map[i][j - 1] != 1) {
        result[i][j] += result[i][j - 1];
      }
      // 若当前位置的上侧不为马
      if (m_map[i - 1][j] != 1) {
        result[i][j] += result[i - 1][j];
      }
    }
  }
  // 打印棋盘
  // print(result, ex, ey);
  return result[ex][ey];
}

int main() {

  if (solve(1, 1, 4, 4) != 2) {
    printf("(%d,%d) (%d,%d) solve error\n", 1, 1, 4, 4);
  }

  if (solve(6, 6, 3, 3) != 6) {
    printf("(%d,%d) (%d,%d) solve error\n", 6, 6, 3, 3);
  }

  return 0;
}