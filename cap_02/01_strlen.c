int strlen_2(char s[]) {
  int i;

  i = 0;

  while (s[i] != '\0')
    ++i;

  return i;
}
