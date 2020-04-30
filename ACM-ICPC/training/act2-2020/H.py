import sys

# Esta funcion calcula el valor y nos devuelve el siguiente punto valido
# porque buscamos un punto que sea divisible entre 4 de forma perfecta
def get_closest_match( n ):
    # obtenemos el punto actual, esto es por derivar la formula
    val = (3 * n + 1) * n // 2
    # luego, si no es divisible entre 4, buscamos el que siga
    while val % 4 != 0:
        n += 1 # aumentamos el n
        val += 3 * n - 1 # y le anadimos la distancia al que sigue
    return n # entonces ya que es valido lo devolvemos

n = int(sys.stdin.readline()) # leemos el n
print(get_closest_match(n)) # imprimimos el mas cercano que es valido
