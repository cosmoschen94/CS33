#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread(void *vargp);

int main(int argc, char * argv[])
{
  if (argc == 1)
  {
    fprintf(stderr, "Error: no argument\n");
    exit(1);
  }
  
  if (argc == 2)
  {
    char * n = argv[1];
    int nthreads = atoi(n);

    if (nthreads < 1)
    {
      fprintf(stderr, "Error: invalid number of threads\n");
      exit(1);
    }
    
    pthread_t * multithread = malloc(nthreads * sizeof (pthread_t));
    int result;
    for (int i = 0; i < nthreads; i++){
      result = pthread_create(&multithread[i], NULL, thread, NULL);
      if(result)
      {
	  fprintf(stderr, "Error creating thread\n");
	  exit(1);
      }
    }

    for (int i = 0; i < nthreads; i++){
      result = pthread_join(multithread[i], NULL);
      if(result)
	{
	  fprintf(stderr, "Error joining thread\n");
	  exit(1);
	}
    }
    free(multithread);
    exit(0);    
  }

  else{
    fprintf(stderr, "Error: need only one command line argument\n");
    exit(1);
  }
}

void *thread(void *vargp) /* Thread routine */
{
  printf("Hello, world!\n");
  return NULL;
}
