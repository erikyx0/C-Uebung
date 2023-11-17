#ifndef status
#define status

int sorttobiggerorsmaller(int i, int posi, int iplus, int posiplus, int (*smallorbig())(int, int));
int NUMcomparison(int a, int b);
void sortasbigger(int i, int posi, int iplus, int posiplus);
void sortasmaller(int i, int posi, int iplus, int posiplus);

#endif