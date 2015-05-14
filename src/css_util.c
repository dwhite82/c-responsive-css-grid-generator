/*!
 * @file      	css_util.c
 * @abstract    Assorted small css utility functions
 * @discussion  This file contains all source code for css_util.
 * 		It is a place for small, direct utility functions
 * 		for use with any programs that may need to do responsive
 * 		CSS conversions.
 * @version     0.0.2 May 13 2015
 * @author      Dan White <dwhite@teddyray.net>
 * @see         css_util.h#
 * @link        Dan White's Development Portal <http://teddyray.net>
*/

#include <stdio.h>
#include <stdlib.h>
#include <css_util.h>


/* convert px int to ems */
float convertpx_to_em(int num, int baseline){
    // if body font-size = 100%, baseline = 16px
    float em;
	
    em = num/(float)baseline;
    return f_round(em,D_PRECISION);
}

/* convert px to percentage */
float convertpx_to_perc(float target, int parentWidth){
    float perc;

    perc = (target/(float)parentWidth) * 100;
    return f_round(perc,D_PRECISION);
}

/* Round a float to a specific precision */
float f_round(float fval, int n){
    char format[32], f_buf[64];
    char *p_str;
	
    sprintf(format, "%%.%df", n);
    sprintf(f_buf, format, fval);
         
    return ((float)strtod(f_buf, &p_str));
}
