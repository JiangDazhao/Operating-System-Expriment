#include <stdio.h>
#include <pthread.h>

//Linux���̱߳��֮�����������߳�,�ֱ�ִ�����̺߳���(ע����뷽ʽ)

/*
int pthread_join(pthread_t thread, void **retval);
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
void pthread_exit(void *retval);
pthread_t pthread_self(void);
*/


//�߳�1ִ�к���
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

//�߳�2ִ�к���
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
    //��ӡ�߳�id��
    printf("main thread tid = 0x%x\n",pthread_self());

    //�������߳�1
    pthread_t tid1;//�������̱߳�ʶ��
    pthread_create(&tid1,NULL,pthread_1,NULL);//pthread_1���߳�ִ�к���

    //�������߳�2
    pthread_t tid2;//�������̱߳�ʶ��
    pthread_create(&tid2,NULL,pthread_2,NULL);//pthread_2���߳�ִ�к���

    //�����ȴ����߳̽������������߳̽���8kb�����ڴ�
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    printf("child pthread exit\n");

    //sleep(5);
    printf("main pthread exit\n");
    pthread_exit(NULL);  //�������߳�    

    return 0;
}

