#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>

int main(void) {
  MYSQL mysql;//数据库句柄
  MYSQL_RES* res;//数据库结果集
  MYSQL_ROW row;//记录结构体

  //init
  mysql_init(&mysql);

  //设置字符编码
  mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");

  //连接数据库
  if(mysql_real_connect(&mysql, "127.0.0.1", "root", "123456", "demo", 23306, NULL, 0) == NULL) {
    printf("Error: %s\n", mysql_error(&mysql));
    printf("mysql connect fail!\n");
    exit(-1);
  }

  //查询数据
  int ret = mysql_query(&mysql, "select * from test;");
  printf("ret: %d\n", ret);
  
  //获取结果集
  res = mysql_store_result(&mysql);

  //给ROW赋值
  while(row = mysql_fetch_row(res)) {
    printf("%s   ", row[0]);
    printf("%s   ", row[1]);
    printf("%s   ", row[2]);
    printf("%s   ", row[3]);
    printf("%s   \n", row[4]);
  }

  //释放结果集
  mysql_free_result(res);

  //关闭数据库
  mysql_close(&mysql);

  system("pause");//暂停黑窗口
  return 0;
}