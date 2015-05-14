/*!
 * @header      main.h
 * @abstract    All main function declarations
 * @discussion  This file contains all declarations for main
 *              and is the entry point for Grid Generator, a fully
 * 		responsive CSS/HTML template generator.
 * @version     0.0.2 May 13 2015
 * @author      Dan White <dwhite@teddyray.net>
 * @see         main.c
 * @link        Dan White's Development Portal <http://teddyray.net>
*/

/*! @define VERSION   Current working version of Grid Generator */
#define VERSION "0.0.2"

/*!
 * @function    output_intro
 * @abstract    Outputs the program intro.
 * @discussion  This is a method that welcomes the user and
 * 		briefly explains the program
 * @result      Intro and basic instructions are displayed in console.
*/
void output_intro();

/*!
 * @function    output_outro
 * @abstract    Outputs the program outro.
 * @discussion  This is a method that tells the user where the output templates
 * 		are located and then displays the program closing before exit
 * @result      Outro and closing are displayed in console.
*/
void output_outro();

/*!
 * @function    output_css
 * @abstract    Outputs css to a file pointer
 * @discussion  This is a method that accepts a pointer to a Stylesheet.
 * 		It opens up a few file pointers to some css templates and combines them 
 * 		with generated css into a new file pointer.
 * @param  	Stylesheet *sty     Pointer to a Stylesheet
 * @result	File pointer templates and generated css are combined into a new file pointer.
*/
void output_css(Stylesheet *sty);

/*!
 * @function    output_html_tpl
 * @abstract    Outputs html template to a file pointer
 * @discussion  This is a method that accepts a pointer to a Stylesheet.
 * 		It opens up a few file pointers to some html templates and combines them 
 * 		with generated html into a new file pointer.
 * @param  	Stylesheet *sty		Pointer to a Stylesheet
 * @result	File pointer templates and generated html are combined into a new file pointer.
*/
void output_html_tpl(Stylesheet *sty);

/*!
 * @function    combine_file
 * @abstract    Combines one file pointer with another
 * @discussion  This is a method that accepts two file pointers,
 * 		a source and destination. If either pointer is NULL,
 * 		an error message is displayed about being unable to write 
 * 		to the files. If the data is good, the source file pointer
 * 		will be read character by character into the destination file
 * 		pointer.
 * @param       FILE *dest_fp		Pointer to destination file
 * @param  	FILE *source_fp		Pointer to the file to combine
 * @result	Contents from the source file pointer are now in the destination file pointer.
*/
void combine_file(FILE *dest_fp, FILE *source_fp);
