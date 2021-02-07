// https://qiita.com/kaityo256/items/11763b5464a4c40ab61c

#include <cstdio>

template <class T>
void bitdump(T a) {
  char *x = (char*)(&a);
  int count = 0;
  int total_bytes = 8;
  int sign_and_exp_bits = 12;
  if (sizeof(T)==16) {
    total_bytes = 10;
    sign_and_exp_bits = 16;
  } else if (sizeof(T) == 4) {
    total_bytes = 4;
    sign_and_exp_bits = 9;
  }
  for (int i=0;i<total_bytes;i++) {
    for (int j=0;j<8;j++) {
      if (x[total_bytes-i-1] & (1<<(7-j))) printf("1");
      else printf("0");
      count++;
      if (count==1 || count==sign_and_exp_bits) printf(" ");
    }
  }
  printf("\n");
}

int main(void) {
  bitdump(1.125F);  // float
  bitdump(1.125);   // double
  bitdump(1.125L);  // long double
}

