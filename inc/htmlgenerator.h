/*!
 * @header      htmlgenerator.h
 * @abstract    All functions responsible for generating html
 * @discussion  This file contains all declarations for
 *              use in htmlgenerator.c. These methods are responsible
 * 		for generating a variety of demo grids and writing them
 * 		to an html template
 * @version     0.0.2 May 13 2015
 * @author      Dan White <dwhite@teddyray.net>
 * @see         htmlgenerator.c
 * @link        Dan White's Development Portal <http://teddyray.net>
*/

/*!
 * @function    create_frac_col
 * @abstract    Create fractional columns based on dividing the total number of columns
 * @discussion  This function accepts a file pointer and an integer value for total
 * 		number of columns. It will then divide the total number of columns in half
 * 		until it reaches zero, delegating the calculated values to generate_frac_divs
 * @see  	generate_frac_divs
 * @param       FILE  *fp	Pointer to a FILE.
 * @param       int numcol	Total number of columns
 * @result      Dimensions for fractional divs are sent to create_frac_col
*/
void create_frac_col(FILE *fp, int numcol);

/*!
 * @function    generate_frac_divs
 * @abstract    Generate and number fractional divs for html template
 * @discussion  This function accepts a file pointer, total number of columns, a count 
 * 		and a integer value to assign to column divs.
 * 		It will loop and write column divs depending on the parameters
 * 		passed in to a file pointer.
 * @see  	create_frac_col
 * @param       FILE  *fp	Pointer to a FILE.
 * @param  	int numcol	Total number of columns
 * @param       int count	Total count of gridrows to create
 * @param  	int value	value for col div
 * @result      Column div definitions are written to a file pointer.
*/
void generate_frac_divs(FILE *fp, int numcol, int count, int value);

/*!
 * @function    create_div_grid
 * @abstract    Create a basic div grid that counts up and down from the total number of columns
 * @discussion  This function accepts a file pointer and a integer for
 * 		the total number of columns. It then counts up to and down from
 * 		the passed in number of columns, writing an alternating div grid
 * 		to a file pointer.
 * @param       FILE  *fp	Pointer to a FILE.
 * @param  	int numcol	Total number of columns
 * @result      Alternating divs from lowest to highest index are written to a file pointer.
*/
void create_div_grid(FILE *fp, int numcol);
