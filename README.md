# Multi-precision PMNS with CIOS reduction

CURRENTLY IN CONSTRUCTION

This folder contains the code used to measure cycle counts in the relevant tables in the "Multi-precision PMNS with CIOS reduction" paper. You will need GCC and GnuMP to compile the codes. For the performances to be accurate on intel processors the Turbo Boost® needs to be disabled. For linux we provide the script "disableturboboost.sh" to disable the turbo boost. To run it:
> chmod +x disableturboboost.sh && sudo ./disableturboboost.sh

To run the benchmark for table 5:
> make table5

Similarly, to run the benchmark for table 6 (your processor needs the cpuflag avx512ifma or the code won't run):
> make table6

Similarly, to run the benchmark for table 8 (your processor needs the cpuflag avx512ifma or the code won't run):
> make table8

We also make a multi-precision PMNS generation code available as well as an accompanying parameter generation script. To use them, you will need the SageMath library which can be found here: http://www.sagemath.org/
