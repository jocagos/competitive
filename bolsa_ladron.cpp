
/*Powered by: Daniel Vallejo Aldana
  Licenciatura en computación */
#include<iostream>
#include<cstdlib>
#include <utility> // para incluir 'pair<T, U>'
#include <vector> // para incluir 'vector<T>'
using namespace std;
typedef struct{
    char name;
    int size;
    int val;
} Item;
#define N 5
#define MAXBOLSA 300
int maximos[MAXBOLSA];
static pair<int, vector<char>> maximoConocido[MAXBOLSA]; // Lo hacemos global y que guarde PAREJAS para que 'first' sea el valor máximo, 'second' un vector de configuración.
Item items[N];
int knap (int cap)
{
    int i,space,max,t;
    int maxi=-1;
    for(i=0,max=0;i<N;i++)
    {
        if((space= cap-items[i].size)>=0)
        if((t=knap(space)+items[i].val)>max)
        {
            max=t; 
            maxi=i;
        }
    }
        return max;
    
}
pair<int, vector<char>> knapReloaded(int cap) //el problema de la bolsa del ladron con programación dinámica 
{
    int i,space,max,maxi=-1,t;
    int desconocido=0;
    Item itemConocido[MAXBOLSA];
    vector<char> config;
    if(maximoConocido[cap].first!=desconocido) return maximoConocido[cap];
    for(i=0,max=0;i<N;i++)
    {
        space = cap - items[i].size; // Separé estas líneas
        if(space >= 0)
        {
            pair<int, vector<char>> ivc = knapReloaded(space);
            t = ivc.first + items[i].val; // Igual
            config = ivc.second;
            if(t>max)
            {
                max=t; 
                maxi=i;
            }
        }
    }
    bool inserted = false;
    maximoConocido[cap].first=max;
    for( i = 0; i < 5; ++i )
        if( max == items[i].val ){
            maximoConocido[cap].second.push_back(items[i].name);
            inserted = true;
            break;
        }
    // Buscar el valor máximo para ese subvalor
    pair<int, vector<char>> ans;
    if( !inserted ) ans.second = config;
    
    // En teoría esto debería guardarlas pero no lo hace bien
    // Hay que leer bien las llamadas recursivas entonces pues parece que esto da una respuesta incorrecta
    // Una solución que se me ocurre es iterar a través de los objetos y comparar el valor de max con el de un objeto
    // Si es igual a un objeto, hacer 'push_back' del nombre a 'maximoConocido[cap].second'
    // Si no, es lo que faltaría, u omitirse o 'arreglar' el vector de chars
    // De ese modo, en teoría, tendríamos los nombres de los objetos por cada posición del memo
    itemConocido[cap]=items[maxi];
    ans.first = max;
    return ans;
}

/*
int Config(int cap, int idx, int* arreglo) //el problema de la bolsa del ladron con programación dinámica 
{
    int i,space,max,maxi=-1,t;
    int desconocido=0;
    static int maximoConocido[MAXBOLSA];
    static char maximizador[MAXBOLSA];
    Item itemConocido[MAXBOLSA];
    if(maximoConocido[cap]!=desconocido) return maximoConocido[cap];
    for(i=0,max=0;i<N;i++)
    {
     if((space= cap-items[i].size)>=0)
        if((t=Config(space)+items[i].val)>max)
        {
            max=t; 
            maxi=i;
        }
    }
        maximoConocido[cap]=max;
        itemConocido[cap]=items[maxi];
        maximizador[cap]=items[maxi].name;
        return max;
}
*/
int main ()
{
    int maxValue=0;
    int maxValue1=0;
    // fill
    items[0].name='A'; items[0].size= 3; items[0].val=  4;
    items[1].name='B'; items[1].size= 4; items[1].val=  5;
    items[2].name='C'; items[2].size= 7; items[2].val= 10;
    items[3].name='D'; items[3].size= 8; items[3].val= 11;
    items[4].name='E'; items[4].size= 9; items[4].val= 13;
    maxValue = knapReloaded(17).first;
    //int maxim=Config(17);
    cout << "config_val: " << maxValue << "\tall_configs_up_to_config_val: ";
    for( int i = 0; i <= 17; ++i )
    {
        cout << "val = " << maximoConocido[i].first << "\ti = " << i << ": ";
        for( int j = 0; j < maximoConocido[i].second.size(); ++j)
            cout << maximoConocido[i].second[j] << " ";
        cout << endl;
    }
    cout << endl;
    //maxValue1=knap(170);
    //cout<<endl<<" Monto maximo del robo :"<<maxValue<<endl;
    //cout<<maxim;
    //cout<<endl<<maxValue1<<endl;
    return 0;
}