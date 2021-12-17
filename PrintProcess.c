#include <stdio.h>
#include <pthread.h>

//Linux多线程编程之创建两个子线程,分别执行子线程函数(注意编译方式)

/*
int pthread_join(pthread_t thread, void **retval);
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
void pthread_exit(void *retval);
pthread_t pthread_self(void);
*/


//线程1执行函数
void *pthread_1(void *arg)
{
    printf("pthread 1 run...\n");
    int i =2;
    while(i--){
        printf("thread1 i =%d\n",i);
        sleep(1);
    }
    pthread_exit(NULL);
    return NULL;
}

//线程2执行函数
void  *pthread_2(void *arg)
{
    printf("pthread 2 run..\n");

    sleep(3);
    printf("pthread 2 exit\n");

    pthread_exit(NULL);
    return NULL;
}

int main(void)
{
    //打印线程id号
    printf("main thread tid = 0x%x\n",pthread_self());

    //创建子线程1
    pthread_t tid1;//定义子线程标识符
    pthread_create(&tid1,NULL,pthread_1,NULL);//pthread_1即线程执行函数

    //创建子线程2
    pthread_t tid2;//定义子线程标识符
    pthread_create(&tid2,NULL,pthread_2,NULL);//pthread_2即线程执行函数

    //阻塞等待子线程结束，回收子线程结束8kb物理内存
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    printf("child pthread exit\n");

    //sleep(5);
    printf("main pthread exit\n");
    pthread_exit(NULL);  //结束主线程    

    return 0;
}

