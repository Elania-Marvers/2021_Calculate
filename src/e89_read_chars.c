#include "inc.h"

static bool is_commun (const char	*str,
		       char		c)
{
  int i;
  int y;
  i = 0;
  y = e89_strlen((char *) str);
  while (i != y)
    {
      if (str[i] == c)
	return true;
      i++;
    }
  return false;
}


bool        e89_read_char(const char        *str,
			  ssize_t           *index,
			  const char        *token)
{
  int i;
  int result;
  int compteur;
  int secu;
  i = 0;
  result = 0;
  compteur = 0;
  secu = 0;

  while (i != e89_strlen((char *) str) && secu == 0)
    {
      if (is_commun(token, str[*index + i]) )
	{
	  result++;
	  compteur++;
	}
      else
	  secu = 1;
      i++;
    }


  if (*index + compteur != *index)
    {
      *index = *index + compteur;
      return true;
    }
  else
    return false;
}
