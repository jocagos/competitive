#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <utility>

using namespace std;

pair<auto, auto> minSame;

int main(){
  int n;
  scanf("%d ", &n);
  vector<int> nums(n);
  for( int i = 0; i < n; ++i ) scanf("%d", &nums[i]);
  auto minLIdx = min_element(nums.begin(), nums.end());
  auto minRIdx = min_element(minLIdx+1, nums.end());
  while( *minLIdx == *minRIdx ){
    nums.erase(minLIdx);
    *minRIdx *= 2;
    n = nums.size();
    minLIdx = min_element(nums.begin(), nums.end());
    minRIdx = min_element(minLIdx+1, nums.end());
  }
  printf("%d\n", nums.size());
  for( int i = 0; i < nums.size(); ++i ) printf("%d%s", nums[i], (i+1 == nums.size() ? "\n" : " ") );
  return 0;
}
