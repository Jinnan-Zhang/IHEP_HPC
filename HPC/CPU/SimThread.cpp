#include <iostream>
#include <pthread.h>
/*
A simple example for pthread usage.
author: Jinnan Zhang:jinnan.zhang@ihep.ac.cn

Compile with:

g++ SimThread.cpp -lpthread  -o SimThread.cpp.o

*/

#define NUM_THREAD 10

void *PrintMessage(void *thread_arg);
/*
使用结构传递多个参数
*/
struct data_thread
{
    int thread_id;
    double x_need;
    char *message;
};

int main()
{
    pthread_t thread_id[NUM_THREAD];
    struct data_thread t_data[NUM_THREAD];

    int rc;
    for (int i = 0; i < NUM_THREAD; i++)
    {
        t_data[i].thread_id = i;
        t_data[i].x_need = i * (i + 3);
        t_data[i].message = (char *)"Message Box: Here.";
        rc = pthread_create(&thread_id[i], NULL,
                            PrintMessage, (void *)&t_data[i]);
        if (rc)
        {
            std::cout << "Error:unable to create thread," << rc << std::endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}

void *PrintMessage(void *thread_arg)
{
    struct data_thread *mdata;
    mdata = (struct data_thread *)thread_arg;
    printf("In this thread: %d, x: %f, message: %s\n", mdata->thread_id, mdata->x_need, mdata->message);
    pthread_exit(NULL);
}