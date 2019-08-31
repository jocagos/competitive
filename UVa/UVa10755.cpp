#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int i64;
void read()
{
  int A, B, C;
  i64 matrix[30][30][30];
  i64 maxSum = -(1LL << 60);
  cin >> A >> B >> C;
  for(int i = 0; i < A; ++i)
    {
      for(int j = 0; j < B; ++j)
        {
	  for(int k = 0; k < C; ++k)
            {
	      cin >> matrix[i][j][k];
            }
        }
    }
  for(int i = 0; i < A; ++i)
    {
      i64 temp[30][30];
      memset(temp, 0, sizeof temp);
      for(int j = i; j < A; ++j)
        {
	  for(int k = 0; k < B; ++k)
            {
	      for(int l = 0; l < C; ++l)
                {
		  temp[k][l] += matrix[j][k][l];
                }
            }
	  //now we have to find the max 2D range sum in temp[B][C];
	  for(int k = 0; k < B; ++k)
            {
	      i64 innerTemp[30], kadane2[30];
	      memset(innerTemp, 0, sizeof innerTemp);
	      for(int l = k; l < B; ++l)
                {
		  for(int m = 0; m < C; ++m)
                    {
		      innerTemp[m] += temp[l][m];
                    }
		  //Applying Kadane's algorithm for 1D range sum
		  memcpy(kadane2, innerTemp, sizeof innerTemp);
		  for(int m = 0; m < C; ++m)
                    {
		      if(m > 0) kadane2[m] += kadane2[m-1];
		      if(kadane2[m] > maxSum) maxSum = kadane2[m];
		      if(kadane2[m] < 0) kadane2[m] = 0;
                    }
                }
            }

        }
    }
  cout<<maxSum<<'\n';
}
int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for(int i = 0; i < T; ++i)
    {
      read();
      if(i < T-1) cout<<'\n';
    }
  return 0;
}
