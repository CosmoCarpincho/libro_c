// strcmp: regresa <0 si s<t, 0 si s==t, >0 si s > t
int strcmp_2(char *s, char *t) {
  int i;

  for (i = 0; s[i] == t[i]; i++) {
    if (s[i] == '\0')
      return 0;
  }
  return s[i] - t[i];
}

// strcmp: apuntadores
int strcmp_3(char *s, char *t) {
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;

  return *s - *t;
}
