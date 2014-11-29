/*
 * The average procedure receives an array of real
 * numbers and returns the average of their
 * values. This toy service handles a maximum of
 * 200 numbers.
 */
const MAXAVGSIZE  = 200;
const MAXRESSIZE  = 800;
struct input_data {
  double input_data<200>;
};
struct output_data {
  int out_data<MAXRESSIZE>;
  int count;
};


typedef struct input_data input_data;
typedef struct output_data output_data;

program ITPP {
    version ITPPVERS {
        double AVERAGE(input_data) = 1;
	output_data ORDERS() = 2;
    } = 2;
} = 130397;

