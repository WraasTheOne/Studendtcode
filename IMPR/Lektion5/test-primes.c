#include "primes.h"
#include <math.h>
#include <assert.h>
#include <stdio.h>

int main(void)
{
  int n, i;
  int counter = 0;
  printf("hvor mange primtal vil du have\n");
  scanf("%d", &n);

  for (i = 0; counter < n; i++)
  {
    counter = counter + (is_prime(i));
    if (is_prime(i) == 1)
    {
      printf("primetal %d: %d\n", counter, i);
    }
  }
  return 0;
}

/* Return if i is a prime number.
   It is assumed as a precondition that the parameter i is non-negative */
int is_prime(int i)
{
  assert(i >= 0);

  if (i == 1)
    return 0;
  else if (i == 2)
    return 1;
  else if (i % 2 == 0)
    return 0;
  else
  {
    int k, limit;
    limit = (int)(ceil(sqrt(i)));
    for (k = 3; k <= limit; k += 2)
      if (i % k == 0)
        return 0;
    return 1;
  }
}
