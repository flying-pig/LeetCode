#include <stdio.h>
#include <stdlib.h>

int* countBits(int num, int *returnSize)
{
  int x = 0;
  int n;
  int *ptr;

  *returnSize = num + 1;
  int *res = (int *)calloc(*returnSize, sizeof(int));

  for (n = 0; n <= num; n++) {
    if (n >= 1 << x) {
      x++;
      ptr = res;
    }

    if (x == 0 || x == 1) {
      res[n] = x;
    } else {
      res[n] = *ptr++ + 1;
    }
  }
  return res;
}

int main(int argc, char *argv[])
{
  int num = 5;
  if (argc >= 2) {
    num = atoi(argv[1]);
  }
  int len;
  int *res = countBits(num, &len);
  int i;
  for (i = 0; i < len; i++) {
    printf("%d ", res[i]);
  }
  printf("\n");
  return 0;
}
