#include "itpp.h"
#include <stdlib.h>

void
averageprog_1( char* host, int argc, char *argv[])
{
   CLIENT *clnt;
   double  *result_1, *dp, f;
   output_data *od;
      char *endptr;
      int i;


   clnt = clnt_create(host, ITPP,
   ITPPVERS, "udp");
   if (clnt == NULL) {
      clnt_pcreateerror(host);
      exit(1);
   }
   od = orders_2(&clnt, clnt);
   if (od == NULL) {
      clnt_perror(clnt, "call failed:");
   }
   clnt_destroy( clnt );
   int *acords = od->out_data.out_data_val;
   	   for(int z = 0; z < od->count;z++){
   		   putc(*acords,stdout);
   		   acords++;
   	   }
}


main( int argc, char* argv[] )
{
   char *host;

   if(argc < 2) {
     printf(
      "usage: %s server_host ...\n",
      argv[0]);
      exit(1);
   }
        if(argc > MAXAVGSIZE + 2) {
          printf("Two many input values\n");
          exit(2);
        }
   host = argv[1];
   averageprog_1( host, argc, argv);
}
