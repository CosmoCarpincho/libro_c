// strlen: regresa la longitud de la cadena s

int strlen_2(char *s) {
  char *p = s;

  while (*p != '\0')
    p++;

  return p - s;
}
