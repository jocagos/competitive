#include <iostream>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n = 0;
  while( cin >> n, n ){
    // // primer truco: hacer un (o dos) elemento(s) extra igual al inicial (y al final)
    // // en el final e inicio ,respectivamente
    // vector<int> a( n + 2 );
    // for( int i = 1; i <= n; ++ i )
    //   cin >> a[i];
    // a[0] = a[n]; // Asignamos el ultimo al inicio
    // a[n+1] = a[1]; // Asignamos el primero al final
    // // calculamos los picos
    // int peaks = 0;
    // for( int i = 1; i <= n; ++ i ){
    //   if( a[i] < a[i - 1] and a[i] < a[i + 1] ) ++ peaks;
    //   else if( a[i] > a[i - 1] and a[i] > a[i + 1] ) ++ peaks;
    // }
    // cout << peaks << '\n';
    /* ******************************************************************************** */
    // segundo truco: Utilizamos mejor los indices, con una formula especial
    // Basicamente:
    // * (0 - 1) % n = (-1 + n) % n = (n - 1) % n
    // * ((n-1) + 1) % n = 0 % n
    vector<int> a( n ); // vector de n elementos
    for( int i = 0; i < n; ++ i ) cin >> a[i];
    int peaks = 0;
    for( int i = 0; i < n; ++ i ){
      if( a[i] < a[(i - 1 + n)%n] and a[i] < a[(i + 1)%n] ) ++ peaks; // minimo local
      else if( a[i] > a[(i - 1 + n)%n] and a[i] > a[(i + 1)%n] ) ++ peaks; // maximo local
    }
    cout << peaks << '\n';
  }
  return 0;
}
