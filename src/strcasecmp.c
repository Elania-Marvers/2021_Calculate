#include "inc.h"



int e89_strcasecmp (char *sa, char *sb)
{
  int a;
  a = 0;

  while (sa[a] != '\0' && sb[a] != '\0')
    {
      if (sa[a] != sb[a])
	if (sa[a] >= 97 && sa[a] <= 122 || sb[a] >= 97 && sb[a] <= 122)
	    if (sa[a] - 32 != sb[a])
	      if (sb[a] - 32 != sa[a])
		return sa[a] - sb[a];
      a += 1;
    }

  return sa[a] - sb[a];
}
