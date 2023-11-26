// strcpy: copia t hacia s; versión de subíndices

void strcpy_2(char *s, char *t) {
  int i;

  i = 0;
  while ((s[i] = t[i]) != '\0')
    i++;
}

// strcpy: copia t hacia s; versión con apuntadores

void strcpy_3(char *s, char *t) {

  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}

// strcpy: t hacia s; versión 2 con apuntadores

void strcpy_4(char *s, char *t) {
  while ((*s++ = *t++) != '\0')
    ;
}

// strcpy: copia t hacia s; versión 3 con apuntadores

void strcpy_5(char *s, char *t) {
  while ((*s++ = *t++))
    ;
}
