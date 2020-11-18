#include <bits/stdc++.h>
using namespace std;
string s;
int puntosIzq, puntosDer, last=1, juegosDer, juegosIzq;
//last es 1 si saca izq, 2 si saca der
int main(){
  cin >> s;
  for(int i=0; i<s.size(); i++){
    if(s[i]=='S'){
      if(last==1) puntosIzq++;
      if(last == 2) puntosDer++;
    }else{
      if(s[i]=='R'){
	if(last==1){
	  last = 2;
	  puntosDer++;
	} else{
	  puntosIzq++;
	  last = 1;
	}
      }else{
	if(juegosIzq==2){
	  cout << juegosIzq << " (winner) - " << juegosDer << '\n';
	  return 0;
	}
	if(juegosDer==2){
	  cout << juegosIzq << " - "<< juegosDer <<  " (winner)" <<'\n';
	  return 0;
	}
	if(last==1){
	  cout << juegosIzq << ' ' << '(' << puntosIzq << "*) - " << juegosDer << " (" << puntosDer << ')' << '\n';
	}
	if(last==2){
	  cout << juegosIzq << ' ' << '(' << puntosIzq << ") - " << juegosDer << " (" << puntosDer << "*)" << '\n';
	}
      }
    }
    if(((puntosIzq>=5||puntosDer>=5)&&abs(puntosIzq-puntosDer)>=2)||(puntosIzq==10||puntosDer==10)){
      if(puntosIzq>puntosDer){
	juegosIzq++;
	last = 1;
      }else{
	juegosDer++;
	last = 2;
      }
      puntosIzq = 0;
      puntosDer = 0;
    }
  }
}
