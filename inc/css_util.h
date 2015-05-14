/*!
 * @header      css_util.h
 * @abstract    All general CSS utility functions
 * @discussion  This file contains all declarations for CSS utility functions
 *              which may be of use to any program that needs to do responsive
 * 		conversions.
 * @version     0.0.2 May 13 2015
 * @author      Dan White <dwhite@teddyray.net>
 * @see         css_util.c
 * @link        Dan White's Development Portal <http://teddyray.net>
*/
 
 /*! @define D_PRECISION   Maximum number precision points to be returned by float function */
#define D_PRECISION 3

/*!
 * @function    convertpx_to_em
 * @abstract    convert hard pixel dimensions to ems
 * @discussion  This function accepts an integer in hard pixel dimensions 
 * 		to convert and a document baseline for the given Stylesheet. 
 * 		It will then return the appropriate value in ems.
 * @param       int num			Number to convert in pixel dimensions
 * @param       int baseline	Document baseline to calculate ems
 * @return     	float
*/
float convertpx_to_em(int num, int baseline);

/*!
 * @function    convertpx_to_perc
 * @abstract    convert hard pixel dimensions to percentages
 * @discussion  This function accepts a target integer in hard pixel dimensions 
 * 		to convert and it's parent element width. It will then
 * 		calculate the appropriate percentage and return it in a float value.
 * @param       float target		Number to convert in pixel dimensions
 * @param       int parentWidth		Total width to divide target by
 * @return     	float
*/
float convertpx_to_perc(float target, int parentWidth);

/*!
 * @function    f_round
 * @abstract    Round a float to a specified precision point.
 * @discussion  This function accepts a float value and an integer value
 * 		to round the given float to and return it. 
 * @param       float target		Number to convert in pixel dimensions
 * @param       int parentWidth		Total width to divide target by
 * @return     	float
*/
float f_round(float fval, int n);