# incluimos librerias de sistema para leer datos y mate para funciones matematicas
import sys, math


n = int(sys.stdin.readline()) # leemos la primera linea y la hacemos un int
if n < 10: # si es menor a 10, sencillamente lo imprimimos
    print(n)
else: # si no, obtenemos el numero de digitos
    digits = int(math.floor( math.log10( n ) + 1 )) # aqui
    p = 10 ** (digits - 1) # Obtenemos la potencia de 10 que le pertenece
    lead = n // p # Obtenemos el digito de la izqueirda del numero
    m = n % p # Quitamos los demas digitos
    m -= p // 2 # le restamos la potencia de 10
    # Le restamos la potencia y el valor que nos da estaria entre -p // 2 y p // 2.
    # esto para que nos diga facilmente cual es el mas cercano:
    if m >= 0: # si es positivo o 0, hacia arriba
        print((lead + 1) * p)
    else: # si no, hacia abajo
        print(lead * p)
