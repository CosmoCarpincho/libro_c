#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE]; // static porque tiene que permanecer
static char *allocp = allocbuf;  // siguiente posición libre

char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) // si cabe
  {
    allocp += n;
    return allocp - n;

  } else {
    return 0;
  }
}

void afree(char *p) {
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
