#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <bits/pthreadtypes.h>
#include <unistd.h>
#include <pthread.h>

// Estructura que contiene, por cada thread, su índice y su identificador
typedef struct threadInfo {
  pthread_t thread;
  int index;

} threadInfo_t;

// Callback que ejecuta el thread
void* sleepIndex(void* index) {
  threadInfo_t* info = (threadInfo_t*)index;
  printf("I am thread %i, I will sleep now \n", info->index);
  sleep(info->index);

  return NULL;
}

int main(int argc, char *argv[]) {
  // Comprobar que tiene al menos un argumento de llamada
  if(argc < 2) {
    printf("Must indicate number of threads as argument");
    return 1;
  }

  // Almacena el número de threads a crear
  int NUM_THREADS = atoi(argv[1]);

  // Array con la información de los threads a crear
  threadInfo_t* pthreads = (threadInfo_t *)malloc(NUM_THREADS * sizeof(threadInfo_t));

  for(int i = 0; i < NUM_THREADS; ++i) {

    // Crear el thread
    pthread_t thread;
    pthreads[i].index = i;
    int exitCode = pthread_create(&thread, PTHREAD_CREATE_JOINABLE, sleepIndex, &pthreads[i]);

    // Comprobar que se ha creado correctamente
    if(exitCode != 0) {
      printf("Failed at creating thread, exit code was %i", exitCode);
      return 1;
    }

    // Almacenar el thread
    pthreads[i].thread = thread;
  }

  for(int i = 0; i < NUM_THREADS; ++i) {
    // Esperar a que el thread iésimo termine
    pthread_join(pthreads[i].thread, NULL);
    printf("Thread %i is done \n", i);
  }

  // Liberar memoria dinámica
  free(pthreads);

  return 0;
}
