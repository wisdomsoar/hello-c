#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * reverseString(char *str)
{
  int len = strlen(str);

  printf("original str: %s", str);
  char *my_result;
  my_result = malloc(len+1);

  for (int i = 0; i < len; i++)
  {
     my_result[i] = str[len-i-1];
  }
  my_result[len] = '\0';

  return my_result;
}

int main()
{
  char *result = reverseString("keyboards");
  printf("result: %s", result);
  free(result);
  return 0;
}
