/*!
 * @file      	htmlgenerator.c
 * @abstract    All html generation functions
 * @discussion  This file contains all source code for htmlgenerator.
 * 		Its specialty is in generating a small variety of responsive
 * 		column definitions into an html template.
 * @version     0.0.2 May 13 2015
 * @author      Dan White <dwhite@teddyray.net>
 * @see         htmlgenerator.h#
 * @link        Dan White's Development Portal <http://teddyray.net>
*/
#include <stdio.h>
#include <htmlgenerator.h>

/* Create a few fractional columns based on dividing the total number of columns in half */
void create_frac_col(FILE *fp, int numcol){
    for(int i = numcol; i >= numcol/2; i /= 2){
        generate_frac_divs(fp, numcol, numcol/i, i);

        if(numcol/i != numcol){
            generate_frac_divs(fp, numcol, i, numcol/i);
        }
    }
}

/* Generate and number fractional divs for html template */
void generate_frac_divs(FILE *fp, int numcol, int count, int value){
    fprintf(fp,"\n\t\t<div class=\"gridrow\">\n");
    for(int i = 1; i <= count; i++){
        if(i == count && numcol % 2 != 0 && i < numcol && count + i != 2){
            fprintf(fp,"\t\t\t<div class=\"col%d\">col%d</div>\n",value+1,value+1);
        }else if(count + i > 2){
            fprintf(fp,"\t\t\t<div class=\"col%d\">col%d</div>\n",value,value);
        }
    }
    fprintf(fp,"\t\t</div>\n");
}

/* Create a basic div grid that counts up and down from the total number of columns */
void create_div_grid( FILE *fp, int numcol){
    for (int i=1, j=numcol-1; i<=numcol && j>=0; i++, j--) {
        fprintf(fp,"\n\t\t<div class=\"gridrow\">\n");
        fprintf(fp,"\t\t\t<div class=\"col%d\">col%d</div>\n",i,i);
        if(j > 0){
            fprintf(fp,"\t\t\t<div class=\"col%d\">col%d</div>\n",j,j);
        }
        fprintf(fp,"\t\t</div>\n");
    }
}