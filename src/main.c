#include "inc.h"

int main (void)
{
  char buffer[4096];
  ssize_t i;

  do
  {
    i = read(0, buffer, sizeof(buffer) - 1);
    if (i > 0)
      buffer[i - 1] = 0;
    printf("%s = %d\n", buffer, e89_calculate(buffer));
  }
  while (i != 0);
  /*
  printf("430+19-20*2 = %d\n", e89_calculate ("430+19-20*2")); // 409
  printf("(9+(3*5)-9)+3 = %d\n", e89_calculate ("(9+(3*5)-9)+3")); // 18  
  printf("0+9+3 = %d\n", e89_calculate ("0+9+3")); // 3  
  printf("0+9/3 = %d\n", e89_calculate ("0+9/3")); // 3  
  printf("19849+((1+49)-89) = %d\n", e89_calculate ("19849+((1+49)-89)")); // 19 810
  */
  return (0);
}
