#include <iostream>

using namespace std;

int main(){
  // T integrantes, 1 <= T <= 10
  // E_i energia de cada uno, 1 <= E_i <= 100
  // P problemas, 1 a P, 1 <= P <= 100
  // D_i costo, S_i, 1 <= D_i <= 100, 1 <= S_i <= 100
  // Problemas van en orden siempre
  // En cada paso, se decide si se resuelve o no
  // Si se resuelve, se resta energia D_j de E_i del concursante i, con problema j, y se anade el score S_j
  // si no se resuelve, se deja y se mantiene la energia E_i
  /* ********************************************** */
  // 3 3 // T, P
  // 4 2 5 // Energias
  // 2 2 5 // Dificultades
  // 3 2 1 // Puntajes
  // Supongamos P = 3
  // Combinaciones posibles: 2^P
  // 0 0 0
  // 0 0 1
  // 0 1 0
  // 0 1 1
  // 1 0 0
  // 1 0 1
  // 1 1 0
  // 1 1 1
  /* ************ NETWORK FLOW ****************** */
  /*
   * Vamos de un participante a cualquier problema, si el problema se puede resolver por el participante
   * El camino de un participante a un problema cuesta la energia de ese problema
   * Actualizamos las conexiones, cuando cambia la energia
   * Iteramos de participante 1 a T para avanzar, y tratamos de anadir algunos problemas
   * Cortamos los caminos que ya no se pueden recorrer, si un problema se resuelve ya no se puede llegar a el
   * Al final, revisas cuantos problemas tienen conexiones, y sumas sus puntajes
    PARTICIPANTES -> PROBLEMAS <- PUNTAJES
    1    -> E_1 ->    1             D_1
    2    -> E_2 ->    2             D_2
    3    -> E_3 ->    3             D_3
    4    -> E_4 ->    4             D_4
    5    -> E_5 ->    5             D_5
    ...               ...           ...
    T    -> E_i ->    P             D_P
    * Complejidad: O(V^2 * (E + log(V^2))) // Edmond Karp
    * Complejidad: O(E^2 * (V + log(E^2))) // Dinic
   */
  /* *************************** Dynamic Programming ************
   * Establecemos una forma de ver cada caso base
   * Establecemos una forma de ver casos generales con base a casos previos
   * tenemos que recorrer todos los participantes
   * para cada uno, obtener la mejor solucion con base a una solucion global
   * solve( int bitmask_problems, int bitmask_participantes, int score ){
   *   Si ya no hay problemas o participantes, devuelve memo[problemas][participantes] = score;
   *   Intenta anadir el siguiente problema resolvible por el participante disponible
   *   memo[participantes + (actual_disponible ? : )][problemas + (problema_actual)] = max( toma_siguiente(participante, problemas, score), toma_siguiente( participante | participante_actual, problemas | problema_actual, score + score_actual ) )
   * return memo[participantes][problemas] = score;
   *}
   * Complejidad: O(T! * P)
   */
  return 0;
}
