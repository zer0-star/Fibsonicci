#include "fib_base.h"
#include "num/mulnum_fft.h"

using num = big::num_t<std::uint8_t>;

number fibonacci(number n) {
  if (n <= 1) {
    return n;
  }

  num a, b, c(3);

  if ((n & 1) == 0) {
    a = 0;
    b = 1;
  } else {
    a = 1;
    b = -1;
  }

  n >>= 1;

  while (n > 1) {
    if ((n & 1) == 0) {
      b = a + b * c;
    } else {
      a = b + a * c;
    }

    c = c * c - 2;
    n >>= 1;
  }

  return static_cast<number>(b + a * c);
}
