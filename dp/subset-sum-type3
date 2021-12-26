bool subsetSum3(int sum) {
  // another space optimized 
  bool subset[2][sum + 1]; 
  memset(subset, false, sizeof(subset)); 
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      if (j == 0) {
        // A subset with sum 0 is always possible
        subset[i % 2][j] = true;
      }
      else if (i == 0) {
        // If there exists no element no sum is possible
        subset[i % 2][j] = false; 
      }
      else if (a[i - 1] <= j) {
        // if can take last element, take it or dont 2 choices 
        subset[i % 2][j] = subset[(i + 1) % 2][j - a[i - 1]] || subset[(i + 1) % 2][j];
      }
      else {
        // cant take last element as well 
        subset[i % 2][j] = subset[(i + 1) % 2][j];
      }
    }
  } 
  return subset[n % 2][sum / 2];
}
