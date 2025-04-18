#include <stdio.h>
#include <limits.h>

/*
 *int arr1[] = {3, 7, 2, 9, 5};
printf("%d\n", secondLargest(arr1, 5)); // 輸出: 7

int arr2[] = {10, 10, 10};
printf("%d\n", secondLargest(arr2, 3)); // 輸出: -1 (沒有第二大的數)
 * */

int secondLargest(int *ary, int cnt)
{
  int largest = INT_MIN;
  int secondLargest = INT_MIN;
  for (int i = 0; i < cnt; i++)
  {
    printf("%d\n", ary[i]);
    if (ary[i] > largest)
    {
      secondLargest = largest;
      largest = ary[i];
    }
    else
    {
      if (ary[i] > secondLargest)
      {
        secondLargest = ary[i];
      }
    }
      printf("L: %d\n", largest);
      printf("S: %d\n", secondLargest);
  }

  if (largest == secondLargest)
  {
    secondLargest = -1;
  }
  return secondLargest;
}


int main()
{
  printf("Hello\n");
  //int arr1[] = {3, 7, 2, 9, 5};
  int arr1[] = {10, 10, 10};
  printf("%d\n", secondLargest(arr1, 3));
  return 0;
}
