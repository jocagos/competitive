#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(int[2][2]);

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t, cases = 1;
  cin >> t;
  int t2 = t;
  int a[2][2], b[2][2], fin[t2 + 1];

  while(t > 0){
    for(int i = 0; i < 2; ++i){
      for(int j = 0; j < 2; ++j){
	cin >> a[i][j];
      }
    }
    for(int i = 0; i < 2; ++i){
      for(int j = 0; j < 2; ++j){
	cin >> b[i][j];
      }
    }

    bool flag = true;
    int c = 0;

    for(int i = 0; i < 4; ++i){
      flag = true;
      for(int j = 0; j < 2 and flag; ++j){
	for(int k = 0; k < 2 and flag; ++k){
	  if(a[j][k] == b[j][k]){
	    flag = true;
	    c++;
	  } else{
	    flag = false;
	    break;
	  }
	}
	if(!flag){
	  break;
	}
      }
      rotateMatrix(a);
    }
            
    if(c == 4){
      fin[cases] = 1;
    } else{
      fin[cases] = 0;
    }

    c = 0;
    cases++;

    t--;
  }

  for(int i = 1; i <= t2; ++i){
    if(fin[i] == 1){
      cout << "Case #" << i <<": POSSIBLE\n";
    } else{
      cout << "Case #" << i <<": IMPOSSIBLE\n";
    }
  }
  // system("PAUSE");
  return 0;
}

void rotateMatrix(int a[2][2]){
  swap(a[0][0], a[0][1]);
  swap(a[1][0], a[1][1]);
  swap(a[0][0], a[1][1]);
} 
