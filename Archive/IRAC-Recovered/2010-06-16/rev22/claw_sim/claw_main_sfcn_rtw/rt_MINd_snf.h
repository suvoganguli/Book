#ifndef RTW_HEADER_rt_MINd_snf_h_
#define RTW_HEADER_rt_MINd_snf_h_
#include "rt_nonfinite.h"
#define rt_MINd_snf(a, b)              (( ((a) <= (b)) || rtIsNaN(b) ) ? (a) : (b))
#endif                                 /* RTW_HEADER_rt_MINd_snf_h_ */
