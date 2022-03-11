#include "inc.h"


static int addsub (char *s);
static int muldiv (char *s);
static int primary (char *str);


static void manger (char *s)
{
  int z;
  z = e89_strlen(s);
  for (int i = 0; i != z; i++)
    s[i] = s[i + 1];
}

static int get_num (char *s, size_t *j) // Recupère les nombres
{
  int i;
  int res;
  i = *j;
  res = 0;
  while (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '\0')
    {
      if (s[i] >= '0' && s[i] <= '9')
  res = res * 10 + (s[i] - '0');
      i++;
    }

  *j = i;
  return res;
}


static int addsub (char *s)
{
  int res;
  res = muldiv(s);

  if (s[0] == '+')
  {
    manger(s);
    res += addsub(s);
  }

  if (s[0] == '-')
  {
    manger(s);
    res -= addsub(s);
  }


  return res;
}


static int muldiv (char *s)
{

  int res;
  res = primary(s);

  if (s[0] == '*')
  {
    manger(s);
    res *= muldiv(s);
  }

  if (s[0] == '/')
  {
    manger(s);
    res /= muldiv(s);
  }


  if (s[0] == '%')
  {
    manger(s);
    res %= muldiv(s);
  }

  return res;

}




/**
 * 
 * 
 * ça va merder avec le str qui n'est pas modifier avec les () on les effaces pas sur str
 * 
 * 
 * 
 * */
static int primary (char *str)
{
  int res;
  if (str[0] == '(')
  {
    int s, u;
    s = 0;
    u = 0;
    char tab[e89_strlen (str)];
    tab[0] = '\0';
    for (int i = 0; str[i] != '\0'; i++)
    {
      if (str[i] == ')')
        s --;

      if (s != 0)
      {
        tab[u] = str[i];
        u++;
      }

      if (str[i] == '(')
        s ++;
    }
    tab[u] = '\0';

    // printf("str{%s} - tab{%s}\n", str, tab);

    if (tab[0] == '\0')
      return 0;

    res = addsub(tab);

     u += 2;
     while (u != 0)
     {
       manger(str);
       u -= 1;
     }

  }
  else
  {

    size_t i;
    i = 0;
    res = get_num (str, &i);

    while (i != 0)
    {
      manger(str);
      i -= 1;
    }

  }
    return res; 

}



static int operator (char *str)
{
  return addsub(str);
}


int e89_calculate (const char   *str)
{
  int i;
  i = e89_strlen((char *) str);
  char tab[i];
  for (int o = 0; o <= i ; o++)
    {
      if (o == i)
        tab[o] = '\0';
      else
        tab[o] = str[o];
    }

  return operator(tab);
}

