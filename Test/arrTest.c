//数组
#include <stdio.h>
#include <windows.h>

//冒泡排序
void bubble_sort(int arr_mp[],int sz){//int* arr_mp
  //printf("%d, %p\n",*arr_mp, arr_mp);
  //确定冒泡排序的趟数
  for(int i=0; i < sz -1; i++){
    int flag = 1;//假设这一趟要排序的数据已经有序, 加上这个进行算法优化，对已经有序的序列不再进行比较操作
    //每一趟冒泡排序
    int j = 0;
    for(j=0; j < sz - 1 - i; j++) {
      if(arr_mp[j] > arr_mp[j+1]){
        int tmp = arr_mp[j];
        arr_mp[j] = arr_mp[j+1];
        arr_mp[j+1] = tmp;
        flag = 0; //本趟排序的数据其实不完全有序
      }
    }
    if(flag == 1) {
      break;
    }
  }
  
}
int main() {

  //定义数组
  char ch[5][6];
  int arr[] = {0,1,2,3,4,5,6,8};
  int arr2[][4] = {{1,2,3,4},{5,6,7,8}};
  double arr_4[2][4];
  int arr5[3][4] = {1,2,3,4};
  int arr6[3][4] = {{1,2,3}, {4,5}};//不完全初始化

  //数据地址应用
  int arr_sz = sizeof(arr)/sizeof(arr[0]);
  printf("arr_sz = %d\n", arr_sz);
  //1. sizeof(数组名)–数组名表示整个数组，sizeof(数组名)计算的是整个数组的大小，单位是字节。
  //2．&数组名，数组名代表整个数组，&数组名，取出的是整个数组的地址。
  //除此1,2两种情况之外，所有的数组名都表示数组首元素的地址
  printf("-------arr address-------\n");
  printf("arr:     %p\n", arr);//数组第一个元素的地址
  printf("&arr[0]: %p\n", &arr[0]);//数组第一个元素的地址
  printf("&arr:    %p\n", &arr);//数组的地址, 数组开始的位置
  printf("\n");
  printf("arr:          %p\n", arr);//数组第一个元素的地址
  printf("arr + 1:      %p\n", arr+1);
  printf("&arr[0]:      %p\n", &arr[0]);//数组第一个元素的地址
  printf("&arr[0] + 1:  %p\n", &arr[0]+1);
  printf("&arr:         %p\n", &arr);//数组的地址, 数组开始的位置
  printf("&arr + 1:     %p\n", &arr+1);
  printf("-------------------\n");

  //使用数组
  printf("\n\n------for arr--------\n");
  int arr3[3][4] = {{1,2,3}, {4,5}};//不完全初始化
  int i = 0;
  for(i = 0; i < 3; i++) {
    int j = 0;
    for(j = 0; j < 4; j++) {
      //printf("%d\t", arr3[i][j]);
      printf("&arr3[%d][%d]=%p,value=%d\t",i,j,&arr3[i][j], arr3[i][j]);
    }
    printf("\n");
  }


  //数组作为函数参数
  //冒泡排序
  printf("\n\n------bubble sort--------\n");
  int arr_mp[] = {6,8,7,9,0,1,4,5,2,3};
  int sz = sizeof(arr_mp)/sizeof(arr_mp[0]);
  printf("arr_mp sz = %d\n", sz);
  //排成升序
  //arr_mp是数组，我们对数组arr_mp进行传参，实际上传递过去的是数组arr_mp首元素的地址
  bubble_sort(arr_mp, sz);
  for(int i = 0; i <sz; i++) {
    printf("%d ",arr_mp[i]);
  }
  printf("\n");



  
  return 0;
}