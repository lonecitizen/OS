#include <stdio.h>

int T, D, W, K, film[13][20], ans;

void init(){
  scanf("%d %d %d", &D, &W, &K);
  ans = 2e9;
  for(int i = 0; i < D; i++){
    for(int j = 0; j < W; j++){
      scanf("%d", &film[i][j]);
    }
  }
}
void dfs(int row, int cnt, int injected_row[13]){
  //check condition
  if(row > D)
    return;

  int count;
  int good_column = 0;
  for(int i = 0; i < W; i++){
    count = 1;
    for(int j = 0; j < D-1; j++){
      if(film[j][i] == film[j+1][i]) count++;
      else count = 1;

//      if(injected_row[2] == 0 && injected_row[5] == 1 && i == 3)
//	printf("count : %d\n", count);
      if(count == K){
	good_column++;
/*	if(good_column == W) {
	  printf("Inject target row : %d\nInject count : %d\nGood Column : %d\nInjected row : ", row, cnt, good_column);
	  for(int k = 0; k < D; k++) printf("%d ", injected_row[k]);
	  printf("\n");
	}*/break;
      }
    }
  }

  if(good_column == W && cnt < ans){ //no more injection necessary
    ans = cnt;
    return;
  }

  int temp[20];
  for(int i = 0; i < W; i++)
    temp[i] = film[row][i]; //row backup

//DEBUG
printf("---------------------------------------------------------------------------\n");      
printf("Inject target row : %d\nInject count : %d\nGood Column : %d\nInjected row : ", row, cnt, good_column);
  for(int k = 0; k < D; k++) printf("%d ", injected_row[k]);
  printf("\n");
printf("---------------------------------------------------------------------------\n");      
printf("\n");
if(injected_row[2] == 0 && injected_row[5] == 1){
  for(int q = 0; q < D; q++){
    for(int w = 0; w < W; w++){
      printf("%d ", film[q][w]);
    }
    printf("\n");
  }
}


  dfs(row + 1, cnt, injected_row); //row skip injection

  if(injected_row[row] == 2){
    injected_row[row] = 0; //row injection with A
    for(int i = 0; i < W; i++) film[row][i] = 0;
    dfs(row + 1, cnt + 1, injected_row);
    injected_row[row] = 2;
    for(int i = 0; i < W; i++) film[row][i] = temp[i];
  }
  if(injected_row[row] == 2){
    injected_row[row] = 1; //row injection with B
    for(int i = 0; i < W; i++) film[row][i] = 1;
    dfs(row + 1, cnt + 1, injected_row);
    injected_row[row] = 2;
    for(int i = 0; i < W; i++) film[row][i] = temp[i];  
  }

  //dfs(row + 1, cnt, injected_row); //row skip injection
  //injection necessary
  //data process
  //dfs call
  //data recovery
}
int main(){
  int injected_row[13] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  scanf("%d", &T);
  for(int i = 0; i < T; i++){
    init();

    dfs(0, 0, injected_row);
  
    printf("#%d %d\n", i+1, ans);
  }
}
