#include <rpc/rpc.h>
#include "itpp.h"
#include <stdio.h>

static double sum_avg;
static output_data od;

double * average_2(input_data *input,
   CLIENT *client) {

  double *dp = input->input_data.input_data_val;
  u_int i;
  sum_avg = 0;
  for(i=1;i<=input->input_data.input_data_len;i++) {
    sum_avg = sum_avg + *dp; dp++;
  }
  sum_avg = sum_avg /
   input->input_data.input_data_len;
  return(&sum_avg);
}

output_data * orders_2(void * emptyp, CLIENT *client)
{
  int *e ;
  output_data * kacke;
  kacke = &od;
  e = &(kacke->out_data.out_data_val);
  int i = 0;
  FILE *fp = fopen("/ITPdata/data.rpcmods","r");
  char c;
  while((c = fgetc(fp)) != EOF&&i < 800){
	*e=(int)c;
	e++;
	i++;
  }
  kacke->count=i;
  fclose(fp);
  return(kacke);
}


output_data * orders_2_svc(void* zzzzz, struct svc_req *svc)
{
CLIENT *client;
return(orders_2(client,client));
}

double * average_2_svc(input_data *input,
   struct svc_req *svc) {
  CLIENT *client;
  return(average_2(input,client));
}

