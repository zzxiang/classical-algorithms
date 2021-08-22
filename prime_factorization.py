# Return a dictionary of prime factors and their counts.
def prime_factorization(n):
  dic = dict()
  for p in range(2, n+1):
    if p * p > n:
      break
    if n % p == 0:
      cnt = 0
      while n % p == 0:
        cnt += 1
        n //= p
      dic[p] = cnt
  if n > 1:
    dic[n] = 1
  return dic


def print_prime_factors(n):
  prime_factors = prime_factorization(n)
  pow_strs = []
  for prime_factor, cnt in prime_factors.items():
    pow_strs.append(f'{prime_factor}^{cnt}')
  print(f'{n} =', ' * '.join(pow_strs))


if __name__ == '__main__':
  print_prime_factors(7)   # 7 = 7^1
  print_prime_factors(21)  # 21 = 3^1 * 7^1
  print_prime_factors(162)  # 162 = 2^1 * 3^4
