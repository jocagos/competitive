#include <iostream>

// Complejidad: O(T * log(N * K))
// Solucion: Formulazo matematico con modulos

using namespace std;
constexpr long long MOD = 1000000007;

/*
N  | 0 | 1 | 2 | 3 | 4 | 5 | 6 <--- K
 ------------------------------

  1| 3 | 6 | 9 | 12| 15| 18| 21
  2| 6 | 12| 18|   |   |   |
  3| 10|   |   |   |   |   |
  4| 15|   |   |   |   |   |
  5| 21|   |   |   |   |   |
  6| 28|   |   |   |   |   |

N -> (N+1)(N+2)/2
K -> (K + 1)
// COSAS A NOTAR: ALGEBRA MODULAR
// Si yo tengo a * b / c
// NO ES IGUAL A: (a % MOD) * (b % MOD) / (c % MOD)
N (numeros naturales) NO definen division, solo PRODUCTO y ADICION
Z (numeros enteros) NO define division PERO SI PRODUCTO Y ADICION (y RESTA porque hay elementos OPUESTOS por adicion)
// Si yo quiero hacer a * b / c para un anillo M
// Primero hago a / c o b / c, FUERA DEL ANILLO, y luego multiplico
// Luego, ahora si multiplico:
// a * b / c => (((a / c) % MOD) * (b % MOD)) % MOD
 */

long long solve( long long k, long long n ){
  n = (n + 1) % MOD;
  long long start = ( k % 2LL ? k + 1 : k + 2 );
  start /= 2;
  start *= ( k % 2LL ? k + 2 : k + 1 );
  start %= MOD;
  return (start * n) % MOD;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n {}, k {};
  int tc {};
  cin >> tc;
  while( tc -- ){
    cin >> n >> k;
    cout << solve(n, k) << '\n';
  }
  return 0;
}
