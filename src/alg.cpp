// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int w = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        ++w;
    }
  }
  return w;
}
int countPairs2(int *arr, int len, int value) {
  int k = 0;
  while ((value - arr[0] >= arr[k]) && (k < len))
    ++k;
  int w = 0;
  int a = 0;
  int b = k - 1;
  while (a != b) {
    if (arr[a] + arr[b] > value) {
      --b;
    } else {
        if (arr[a] + arr[b] < value) {
          ++a;
      } else {
          for (int i = k - 1; i > a; i--) {
            if (arr[i] + arr[a] < value)
              break;
            if (arr[i] + arr[a] == value)
              ++w;
          }
          ++a;
        }
      }
  }
  return w;
}
int countPairs3(int *arr, int len, int value) {
  int w = 0;
  int k = 0;
  while ((value - arr[0] >= arr[k]) && (k < len))
    ++k;
  for (int i = 0; i < k; i++) {
    int x = value - arr[i];
    int a = i;
    int b = k - 1;
    bool f = false;
    while ((a <= b) && (!f)) {
      int cen = (a + b) / 2;
      if (arr[cen] == x) {
        for (int j = a; j < b; j++)
          if (arr[j] == x)
            ++w;
        f = true;
      }
      if (arr[cen] > x)
        b = cen - 1;
      else
        a = cen + 1;
    }
  }
  return w;
}
