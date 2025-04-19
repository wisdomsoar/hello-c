#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char *str)
{
  int len = strlen(str);

  printf("original str: %s\n", str);
  printf("original str len: %d\n", len);

                                   //    012345678     (len = 9)
  for (int i = 0; i < len/2; i++)  //    keyboards
  {
     char t = str[len-i-1];

     printf("t: %c\n", t);
     str[len-i-1] = str[i];     
     str[i] = t;
  }
}

int main()
{
  char test_str[10] = "keyboards";
  reverseString(test_str);
  printf("result: %s", test_str);
  return 0;
}
