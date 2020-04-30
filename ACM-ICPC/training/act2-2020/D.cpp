#include <bits/stdc++.h>

using namespace std;

int main(){
  int n {}, k {};
  cin >> n >> k;
  vector<double> dists( n ); // Hacemos un vector de distancias del punto al origen, normalizadas (mas info, distancia en una esfera o en R3)
  for( int i = 0; i < n; ++ i ){ // Recorremos todos los puntos
    double x {}, y {}, z {}; // los guardamos
    cin >> x >> y >> z;
    dists[i] = sqrt( x * x + y * y + z * z ); // almacenamos la distancia al origen que es 0, 0, 0
  }
  sort( dists.begin(), dists.end() ); // Ordenamos las distancias
  // Entonces sencillamente imprimimos la mayor distancia necesaria
  // hasta K, porque es la que necesitamos como radio para cubrir el centro de
  // K nubes minimo
  // Lo hacemos con `setw` para decir que queremos ver 8 digitos
  // y con `fixed` para indicar que es con punto decimal fijo
  cout << setw(8) << fixed << dists[k - 1] << endl;
  return 0;
}
