#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
/** 
 * 字符串计算
*/

/*----------------------------------------------------------------*/
//1. 替换空格
// 实现一个函数，把字符串 s 中的每个空格替换成"%20"。
char* replaceSpace(char* s){
  int len = strlen(s);
  int blank_count = 0;
  for(int i = 0; i < len; i++) {
    if(s[i] == 32) { //s[i] == ' '
      blank_count++;
    }
  }
  
  int new_len = len + blank_count * 2 + 1;
  char* result = (char*)malloc(sizeof(char) * new_len);

  int i = 0;
  while(*s != '\0') {
    if(*s == 32) {//*s == ' '
      result[i++] = '%';
      result[i++] = '2';
      result[i++] = '0';
    }else {
      result[i++] = *s;
    }
    s++;
  }

  result[i] = '\0';

  return result;
}

char* replaceSpace2(char* s) {
  int len = strlen(s);
  int blank_num = strcspn(s, " ");
  int new_len = len + blank_num * 2 + 1;

  char* result = (char*)malloc(sizeof(char) * new_len);
  memset(result, 0, new_len);
  char* first_addr = result;

  while(*s != '\0') {
    if(*s == 32) {//*s == ' '
      *result = '%';
      result++;
      *result = '2';
      result++;
      *result = '0';
    }else {
      *result = *s;
    }
    s++;
    result++;
  }

  *result = '\0';
  result = first_addr;
  first_addr = NULL;

  return result;
}

/*----------------------------------------------------------------*/
//2. 左旋转字符串
// abcdef => cdefab
char* reverseLeftWords(char* s, int n){
    int len = strlen(s);
    char* str_left = (char*)malloc(sizeof(char) * (n+1));
    for(int i = 0; i < n; i++) {
        str_left[i] = s[i];
    }
    str_left[n] = '\0';
    char* str_new = (char*)malloc(sizeof(char) * (len + 1));
    for(int i = n; i < len; i++) {
        str_new[i-n] = s[i];
    }
    for(int i = 0; i < n; i++) {
        str_new[len-n+i] = str_left[i];
    }
    str_new[len] = '\0';

    return str_new;
}

char* reverseLeftWords2(char* s, int n){
    int len = strlen(s),i = 0;;
    char *ans = malloc(sizeof(char) * (len + 1));
    while(i < len){
      //int j = (n + i++);
      //printf("%c,%d,%d,%d\n",s[j%len],j%len,j,i);
      *(ans++) = s[(n + i++)%len];
    }
    *ans = '\0';
    //printf("ans: %c,%p,%p,%d\n", *ans, ans, ans - len,len);

    return ans - len;
}

/*----------------------------------------------------------------*/
// test main function
int main() {
  printf("-----------replace space------------\n");
  //1. 替换空格
  char str[] = "I encountered some interesting people at the party.";
  printf("str: %s\n", str);
  char* new_str = replaceSpace(str);
  printf("new str = %s\n", new_str);
  while(*new_str != '\0') {
    printf("%c", *new_str);
    new_str++;
  }
  printf("\n\n");
  
  printf("-----------reverse left words------------\n");
  //2. 左旋转字符串
  char s[] = "abcdefghi";
  printf("reverse left words: %s\n", s);
  int k = 2;
  char* new_s = reverseLeftWords2(s, 2);
  printf("reverse left words: %s\n", new_s);

  return 0;
}