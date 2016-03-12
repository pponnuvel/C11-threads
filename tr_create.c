#include<stdio.h>
#include<stdlib.h>
#include<threads.h>

#define TRDS 4

struct add {
	size_t start;
	size_t end;
	size_t tot;
};

int func(void *arg)
{
   struct add *v = arg;
   size_t i = 0;
   v->tot = 0;

   for(i=v->start; i<=v->end; i++)
      v->tot+=i;

   printf("[%zu, %zu]: %zu\n", v->start, v->end,  v->tot);
   return 0;
}

int main(int argc, char **argv)
{
   thrd_t t[TRDS];
   size_t i;
   struct add a[TRDS];
   size_t gt = 0;
   int ep = 0;

   if( argc != 2 ) { 
      puts("An integer argument must be passed");
      exit(1); 
   }

   size_t in = (size_t)atoi(argv[1]);

   for(i=0;i<TRDS;i++) {
      a[i].start = i*(in/TRDS) + 1;
      if(i == (TRDS-1)) {
         ep = in - TRDS*(in/TRDS); //In case of odd number, the last thread will do an extra addition
      }
      a[i].end = a[i].start + in/TRDS - 1 + ep;
      thrd_create(&t[i], func, &a[i]);
   }

   for(i=0;i<TRDS; i++) {
      thrd_join(t[i], 0);
      gt += a[i].tot;
   }
   
   printf("n*(n+1)/2 = %zu Grand Total: %zu \n", in*(in+1)/2, gt);

   return 0;
}

