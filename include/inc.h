#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void valider();
int e89_strlen (char *str);

bool e89_read_char(const char *str, ssize_t *index, const char *token);
bool e89_read_text (const char *str, size_t *index, const char *token);
int e89_strcasecmp (char *sa, char *sb);
int e89_get_numeral (int nbr, int mul);
int e89_calculate (const char           *str);





