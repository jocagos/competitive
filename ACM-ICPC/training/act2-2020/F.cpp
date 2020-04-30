#include <iostream>
// Libreria de herramientas en contenedores
#include <algorithm>
#include <vector>
// Contenedor optimizado para guardar bits nada mas y revisar rapidamente algunas cosas como si fueran mascaras de bits
#include <bitset>

using namespace std;
constexpr int MAXN = 100100;
int n {}, c {};
bitset<MAXN> used( 0 ); // Mascara de bits que nos indica cuales han sido usados

int main(){
  cin >> n >> c;
  vector<int> w( n ); // vector de enteros que indica los pesos
  for( int i = 0; i < n; ++ i ){
    cin >> w[i]; // leemos los pesos
  }
  sort( w.begin(), w.begin() + n ); // los ordenamos
  int amount {}; // para contar
  for( int i = 0; i < n; ++ i ){
    if( used[i] ) // si ya ha sido utilizado, lo saltamos
      continue;
    used[i] = 1; // si no, lo marcamos utilizado
    // luego hacemos una busqueda binaria del mejor que le quede
    // tal que ese peso mas otro peso queden lo mas cercanos
    // posible a la capacidad
    int pos = lower_bound( w.rbegin(), w.rend(), c - w[i], greater<int>() ) - w.rbegin();
    // Esto nos deja una posicion valida, pues si no encuentra, es invalida
    for( pos; pos < n and used[n - pos - 1]; ++ pos );
    if( pos != n ) // si la posicion es valida
      if( w[i] + w[n - pos - 1] <= c ) // y ademas la suma es menor o igual a la capacidad
	used[n - pos - 1] = 1; // marcala como usada
    amount ++; //aumentamos la cuenta
  }
  cout << amount << endl;
  return 0;
}
