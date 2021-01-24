// Usa C++11, tomenlo en cuenta
// y no usa vector, pero si cambian constexpr a const, compila sin c++11

// Declaramos las variables de uso y los arreglos
constexpr int MAXSIZE = 1000001; // tamano max
// arreglos: pa de padres, ra de rangos, set_size de tamanos
int pa[MAXSIZE], ra[MAXSIZE], set_size[MAXSIZE];
// numero de conjuntos distintos
int num_sets = MAXSIZE;

// Inicializa el UFDS, desde el indice IDX (por si empieza en otro valor
void init( int n, int idx = 0 ){
  num_sets = n + idx; // asignamos el numero de conjuntos
  // a cada conjunto
  for( int i = 0; i < num_sets; ++ i ){
    pa[i] = i; // son su propio padre inicialmente
    ra[i] = set_size[i] = 1; // el rango y tamano son 1
  }
}

// Buscamos un conjunto I, 
int find_set( int i ){
  // Si su padre es el mismo, entonces devolvemos ese mismo I
  // Pero si no, buscamos a su padre y lo devolvemos, recursivo
  return pa[i] == i ? i : pa[i] = find_set( pa[i] );
}

// pregunta si son del mismo conjunto I y J, lo que hace es
// encontrar el padre de cada uno y compararlos, si son iguales es TRUE, de otro modo es FALSE
bool is_same_set( int i, int j ){
  return find_set( i ) == find_set( j );
}

// Une (o pregunta) dos conjuntos I y J
bool union_set( int i, int j ){
  // Si no estan unidos ya
  if( not is_same_set( i, j ) ){
    // Reducimos el numero de conjuntos distintos, porque se unen
    num_sets --;
    // encontramos a sus padres y los unimos
    int x = find_set( i ), y = find_set( j );
    // Si uno tiene mas rango, es el representante
    if( ra[x] > ra[y] ){
      pa[y] = x; // aqui es representante
      set_size[x] += set_size[y]; // y juntamos los tamanos
    }
    // Si no, el otro es el representante
    else{
      pa[x] = y;
      set_size[y] += set_size[x];
      // si sus rangos son iguales, que el otro tenga mas rango
      if( ra[x] == ra[y] ) ra[y] ++;
    }
    // y devolvemos que se unieron con exito
    return true;
  }
  // Si ya estaban unidos, la union no se pudo, entonces FALSE
  return false;
}

// Tamano de cada conjunto
int size_of_set( int i ){
  return set_size[find_set( i )];
}
