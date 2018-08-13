#include <unistd.h>  //1、linux 头文件
#include<stdio.h>
int main()
{
    int i;
    printf("你");
    fflush(stdout);//强制刷新缓存，输出显示
    for( i=0;i<10;i++ )
    {
        sleep(1);       /*2、linux 使用sleep，参数为秒*/
        printf(".");
        fflush(stdout);//强制刷新缓存，输出显示
    }
    printf("好\n"); /*输出“你”和“好”之间会间隔10秒,并输出10个点*/
    return 0;
}
