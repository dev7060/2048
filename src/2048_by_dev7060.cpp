//By github.com/dev7060

#include <iostream>

#include <stdlib.h>

#include <time.h>

#include <conio.h>

using namespace std;
int a[17] = {
  0
};
int t[17] = {
  0
};
void combinenshift_a(int st, int en, int ch) {
  if (ch == 1) {
    int j = st;
    for (int i = st; i <= (en + 1); i++) {
      if (a[i] != 0) {
        a[j] = a[i];
        if (j != i) {
          a[i] = 0;
        }
        j++;
      }
    }
    for (int m = st; m <= en; m++) {
      if (a[m] == a[m + 1]) {
        a[m] += a[m + 1];
        a[m + 1] = 0;
      }
    }
    j = st;
    for (int i = st; i <= (en + 1); i++) {
      if (a[i] != 0) {
        a[j] = a[i];
        if (j != i) {
          a[i] = 0;
        }
        j++;
      }
    }
  } else if (ch == 2) {
    int j = st;
    for (int i = st; i <= (en + 1); i++) {
      if (t[i] != 0) {
        t[j] = t[i];
        if (j != i) {
          t[i] = 0;
        }
        j++;
      }
    }
    for (int m = st; m <= en; m++) {
      if (t[m] == t[m + 1]) {
        t[m] += t[m + 1];
        t[m + 1] = 0;
      }
    }
    j = st;
    for (int i = st; i <= (en + 1); i++) {
      if (t[i] != 0) {
        t[j] = t[i];
        if (j != i) {
          t[i] = 0;
        }
        j++;
      }
    }
  }

}
void combinenshift_d(int st, int en, int ch) {
  //st->from rhs, en=1-lhs
  if (ch == 1) {
    int j = st;
    for (int i = st; i >= (en - 1); i--) {
      if (a[i] != 0) {
        a[j] = a[i];
        if (j != i) {
          a[i] = 0;
        }
        j--;
      }
    }
    for (int m = st; m >= en; m--) {
      if (a[m] == a[m - 1]) {
        a[m] += a[m - 1];
        a[m - 1] = 0;
      }
    }
    j = st;
    for (int i = st; i >= (en - 1); i--) {
      if (a[i] != 0) {
        a[j] = a[i];
        if (j != i) {
          a[i] = 0;
        }
        j--;
      }
    }
  } else if (ch == 2) {
    int j = st;
    for (int i = st; i >= (en - 1); i--) {
      if (t[i] != 0) {
        t[j] = t[i];
        if (j != i) {
          t[i] = 0;
        }
        j--;
      }
    }
    for (int m = st; m >= en; m--) {
      if (t[m] == t[m - 1]) {
        t[m] += t[m - 1];
        t[m - 1] = 0;
      }
    }
    j = st;
    for (int i = st; i >= (en - 1); i--) {
      if (t[i] != 0) {
        t[j] = t[i];
        if (j != i) {
          t[i] = 0;
        }
        j--;
      }
    }
  }

}
void transform() {
  t[1] = a[13];
  t[2] = a[9];
  t[3] = a[5];
  t[4] = a[1];
  t[5] = a[14];
  t[6] = a[10];
  t[7] = a[6];
  t[8] = a[2];
  t[9] = a[15];
  t[10] = a[11];
  t[11] = a[7];
  t[12] = a[3];
  t[13] = a[16];
  t[14] = a[12];
  t[15] = a[8];
  t[16] = a[4];
}

void transform2() {
  a[13] = t[1];
  a[9] = t[2];
  a[5] = t[3];
  a[1] = t[4];
  a[14] = t[5];
  a[10] = t[6];
  a[6] = t[7];
  a[2] = t[8];
  a[15] = t[9];
  a[11] = t[10];
  a[7] = t[11];
  a[3] = t[12];
  a[16] = t[13];
  a[12] = t[14];
  a[8] = t[15];
  a[4] = t[16];
}

int main() {
  char input;
  a[5] = 2;
  while (1) {
    system("clear");
    int flag1 = 1;
    int random1;
    while (1) {
      srand(time(0));
      random1 = rand() % 17;
      if (random1 == 0) {
        random1 = 1;
      }
      if (a[random1] == 0) {
        flag1 = 2;
      }
      if (flag1 == 2) {
        break;
      }
    }
    srand(time(0));
    int fill1 = rand() % 2;
    if (fill1 == 0) {
      fill1 = 2;
    } else {
      fill1 = 4;
    }
    a[random1] = fill1;
    for (int i = 1; i <= 16; i++) {
      cout << a[i] << " ";
      if (i % 4 == 0) {
        cout << "\n";
      }
    }
    cin >> input;
    if (input == 'a') {
      combinenshift_a(1, 3, 1);
      combinenshift_a(5, 7, 1);
      combinenshift_a(9, 11, 1);
      combinenshift_a(13, 15, 1);
    } else if (input == 'd') {
      combinenshift_d(4, 2, 1);
      combinenshift_d(8, 6, 1);
      combinenshift_d(12, 10, 1);
      combinenshift_d(16, 14, 1);
    } else if (input == 'w') {
      transform();
      combinenshift_d(4, 2, 2);
      combinenshift_d(8, 6, 2);
      combinenshift_d(12, 10, 2);
      combinenshift_d(16, 14, 2);
      transform2();

    } else if (input == 's') {
      transform();
      combinenshift_a(1, 3, 2);
      combinenshift_a(5, 7, 2);
      combinenshift_a(9, 11, 2);
      combinenshift_a(13, 15, 2);
      transform2();
    }
    int filled = 0;
    int win_flag = 1;
    for (int i = 1; i <= 16; i++) {
      if (a[i] != 0) {
        filled++;
      }
      if (a[i] == 2048) {
        win_flag = 2;
      }
    }
    if (win_flag == 2) {
      system("clear");
      cout << "won";
      break;
    }
    if (filled == 16) {
      system("clear");
      cout << "all filled";
      break;
    }
  }
  return 0;
}
