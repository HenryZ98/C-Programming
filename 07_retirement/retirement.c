#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void print(int months, double balance) {
   printf ("Age %3d month %2d you have $%.2lf\n", months / 12, months % 12, balance);
   return;
}

double calculator(double balance, retire_info retire_stats) {
  balance += balance * retire_stats.rate_of_return;
  balance += retire_stats.contribution;
  return balance;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
  double balance = initial;
  int total_months = startAge - 1;

  for(int i = 0; i < working.months; i++) {
    total_months += 1;
    print(total_months, balance);
    balance = calculator(balance, working);
  }

  for(int j = 0; j < retired.months; j++) {
    total_months += 1;
    print(total_months, balance);
    balance = calculator(balance, retired);
  }
  return;
}

int main(void) {
  retire_info working;
  retire_info retired;

  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12.0;
  
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12.0;

  retirement(327, 21345, working, retired);
  return 0;
}
      
