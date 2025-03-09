namespace factorizer{

int sieve_max = -1;
vector<int> smallest_factor;
vector<int> primes;
vector<bool> prime;

void linear_sieve(int n) {
  n = max(n, 1);
  sieve_max = n;
  smallest_factor.assign(n + 1, 0);
  prime.assign(n + 1, true);
  primes.clear();
  prime[0] = prime[1] = false;
  for (int i = 2; i <= n; ++i) {
    if (prime[i]) {
      smallest_factor[i] = i;
      primes.push_back(i);
    }
    for (int p : primes) {
      if (p > smallest_factor[i] || i * 1LL * p > n) {
        break;
      }
      prime[i * p] = false;
      smallest_factor[i * p] = p;
    }
  }
}

// O(n log log n)
void slow_sieve(int n){
  n = max(n, 1);
  sieve_max = n;
  smallest_factor.assign(n + 1, 0);  
  prime.assign(n + 1, true);
  primes.clear();
  prime[0] = prime[1] = false;
  for (int p = 2; p <= n; ++p) {
    if (prime[p]) {
      smallest_factor[p] = p;
      primes.push_back(p);
      for (long long i = p * 1LL * p; i <= n; i += p) {
        if (prime[i]) {
          prime[i] = false;
          smallest_factor[i] = p;
        }
      }
    }
  }
}

void sieve (int n) {
  linear_sieve(n);
}

bool is_prime (long long n) {
  assert(1 <= n && n <= sieve_max * 1LL * sieve_max);
  if (n <= sieve_max) {
    return prime[n];
  }
  for (auto p : primes) {
    if (p * 1LL * p > n) {
      break;
    }
    if(n % p == 0){
      return false;
    }
  }
  return true;
}

template<typename T>
vector<pair<T, int>> factorize(T x) {
  assert(1 <= x && x <= sieve_max * 1LL * sieve_max);
  vector<pair<T, int>> factors;
  if (x <= sieve_max) {
    while (x > 1) {
      if (!factors.empty() && factors.back().first == smallest_factor[x]){
        factors.back().second++;
      } else {
        factors.emplace_back(smallest_factor[x], 1);
      }
      x /= smallest_factor[x];
    }
    return factors;
  }
  for (int p : primes) {
    if (p * 1LL * p > x) {
      break;
    }
    if(x % p == 0) {
      factors.emplace_back(p, 0);
      do {
        factors.back().second++;
        x /= p;
      }while(x % p == 0);
    }
  }
  if (x > 1) {
    factors.emplace_back(x, 1);
  }
  return factors;
}

template<typename T>
vector<T> divisors_from_factors (const vector<pair<T, int>> &factors) {
  vector<T> divisors = {1};
  for (auto &[p, cnt] : factors) {
    int sz = (int) divisors.size();
    for (int i = 0; i < sz; ++i) {
      T cur = divisors[i];
      for (int j = 0; j < cnt; ++j) {
        cur *= p;
        divisors.push_back(cur);
      }
    }
  }
  sort(divisors.begin(), divisors.end());
  return divisors;
}

} // namespace factorizer

using namespace factorizer;