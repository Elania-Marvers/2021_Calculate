#include "inc.h"

bool	e89_read_text (const char	*str,
		       size_t		*index,
		       const char	*token)
{
  int i;
  int result;
  int obj;
  i = 0;
  result = 0;
  obj = e89_strlen ((char *) token);
  
  while (i != obj)
    {
      if (str[*index + i] == token[i])
	result++;
      i++;
    }

  if (result == obj)
    {
      *index = *index + obj;
      return true;
    }

  return false;
  
}
