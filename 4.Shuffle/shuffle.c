#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  int min = 1;
  int max = 5;

  int array[5] = { 1, 2, 3, 4, 5 };
  for (int i = 4; i >= 0; i--)
  {
    int x = rand() % (i-0+1) + 0;
    int t = array[i];
    array[i] = array[x];
    array[x] = t;
  }

  for (int i = 0; i < 5; i++)
  {
    printf("%d, ", array[i]);
  }
  printf("\n");

  //int x = rand() % (max - min + 1) + min;
  //printf("x = %d\n", x);

  return 0;
}
