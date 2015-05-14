/*!
 * @header      cssgenerator.h
 * @abstract    All functions responsible for generating css
 * @discussion  This file contains all declarations for
 *              use in cssgenerator.c. These methods are responsible
 *              for accepting user input for basic Document and Stylesheet definitions
 * 		as well as generating all CSS required to complete a Stylesheet.
 * @version     0.0.2 May 13 2015
 * @author      Dan White <dwhite@teddyray.net>
 * @see         cssgenerator.c
 * @link        Dan White's Development Portal <http://teddyray.net>
*/

/*! @define BASELINE   Stylesheet baseline font-size: 100%; = 1em = 16px */
#define BASELINE 16

/*! @define BP_MAX   Maximum number of desktop breakpoints */
#define BP_MAX 5


/*!
 * @struct      Document
 * @abstract    Basic Document Properties.
 * @discussion  This is a struct that holds basic properties used to generate
 *              a grid.
 * @field       width		width of Document in pixel dimensions
 * @field       lrMargins	width of Document left and right margins in pixel dimensions
 * @field	gutter		width of Document gutter/inner margins in pixel dimensions
*/
typedef struct{
    int width;
    int lrMargins;
    int gutter;
} Document;

/*!
 * @struct      Grid
 * @abstract    Properties for CSS grid.
 * @discussion  This is a struct that contains the precise measurements needed
 *              using properties from Document and Stylesheet.
 * @field       contentWidth     	total workable content width after document margins subtracted
 * @field	totalGutterWidth	sum of all gutters for grid in pixel dimensions
 * @field	totalColWidth		sum of all columns for grid in pixel dimensions
 * @field	marginCount		count of total margins in grid
 * @field	margin			basic margin width in pixel dimensions
 * @field	colWidth		basic column width in pixel dimensions
 * @field	nextCol			sum of previous column and gutter
*/
typedef struct{
    int contentWidth;
    int totalGutterWidth;
    int totalColWidth;
    int marginCount;
    int margin;
    float colWidth; 
    float nextCol;
} Grid;

/*!
 * @struct      Stylesheet
 * @abstract    Properties for entire Stylesheet.
 * @discussion  This is a struct that contains the necessary Documents, Grids
 *              and unique properties for an entire responsive Stylesheet.
 * @field       baseline     		Stylesheet baseline.
 * @field       numcol    			Count of columns for Stylesheet
 * @field       breakpointCount     Count of desktop breakpoints
 * @field	breakPoints[]		int array of breakpoint values
 * @field	doc[]				array of Documents
 * @field	grid[]				array of Grids
*/
typedef struct{
    int baseline;
    int numcol;	
    int breakpointCount;
    int breakpoints[BP_MAX];
    Document doc[BP_MAX];
    Grid grid[BP_MAX];
} Stylesheet;

/*!
 * @function    input_stylesheet
 * @abstract    Collect user input for basic Stylesheet dimensions
 * @discussion  This function accepts user input in pixel dimensions to create
 * 		basic Stylesheet dimensions like the column count and breakpoint
 * 		dimensions. Then depending on how many breakpoints are input it
 * 		will call input_doc to collect user input for breakpoint specifics
 * @return     	Stylesheet
*/
Stylesheet input_stylesheet();

/*!
 * @function    input_doc
 * @abstract    Collect user input for each Document in pixel dimensions.
 * @discussion  This function accepts user input in pixel dimensions to create
 * 		a Document for each desktop breakpoint and is called by input_stylesheet
 * @return     	Document
*/
Document input_doc();

/*!
 * @function    create_grid
 * @abstract    Set up the actual grid.
 * @discussion  This function accepts a Document pointer and a number of columns
 * 		for the given Stylesheet. It will then perform necessary calculations
 * 		to generate the responsive grid in ems and percentages from hard
 * 		pixel dimensions previously input by the user.
 * @param       Document *doc	Pointer to a Document
 * @param       int numcol	total number of columns for Stylesheet
 * @return     	Grid
*/
Grid create_grid(Document *doc, int numcol);

/*!
 * @function    create_stylesheet
 * @abstract    Create the entire Stylesheet and write it to a file.
 * @discussion  This function accepts a file pointer and a Stylesheet pointer.
 * 		It will then delegate the data to each method responsible for 
 * 		assembling each section of the complete Stylesheet, from default
 * 		column definitions to desktop breakpoint column definitions for
 * 		each media query.
 * @param       FILE  *fp    		Pointer to a FILE.
 * @param       Stylesheet  *sty	Pointer to a Stylesheet
 * @result      A complete Stylesheet is written to a file pointer.
*/
void create_stylesheet(FILE *fp, Stylesheet *sty);

/*!
 * @function    create_default_css
 * @abstract    Create default css for main mobile breakpoint before media queries.
 * @discussion  This function accepts a file pointer and a Grid pointer.
 * 		It will then calculate and write the default mobile grid and column
 * 		definitions to a file pointer.
 * @see         create_stylesheet
 * @param       FILE  *fp    	Pointer to a FILE.
 * @param       Grid  *grid		Pointer to a Grid
 * @result      Default mobile definitions are written to a file pointer.
*/
void create_default_css(FILE *fp, Grid *grid);

/*!
 * @function    create_row_css
 * @abstract    Create grid row definitions for a given breakpoint.
 * @discussion  This function accepts a file pointer and a Document pointer.
 * 		It will then calculate and write the grid row definitions
 * 		for a given breakpoint
 * @see         create_stylesheet
 * @param       FILE  *fp    	Pointer to a FILE.
 * @param       Document *doc	Pointer to a Document
 * @result      Grid row definitions are written to a file pointer.
*/
void create_row_css(FILE *fp, Document *doc);

/*!
 * @function    create_marg_css
 * @abstract    Create percentage based gutter definition for all columns.
 * @discussion  This function accepts a file pointer and a Grid pointer.
 * 		It will then calculate and write the gutter (margin) definitions
 * 		for a given breakpoint to a file pointer
 * @see         create_stylesheet
 * @param       FILE *fp	Pointer to a FILE.
 * @param       Grid *grid	Pointer to a Grid
 * @result      Column margin definitions are written to a file pointer.
*/
void create_marg_css(FILE *fp, Grid *grid);

/*!
 * @function    create_cols_css
 * @abstract    Create percentage based column definitions.
 * @discussion  This function accepts a file pointer and a Grid pointer.
 * 		It will then calculate and write the column definitions
 * 		for a given breakpoint to a file pointer
 * @see         create_stylesheet
 * @param       FILE *fp	Pointer to a FILE.
 * @param       Grid *grid	Pointer to a Grid
 * @result      Column definitions are written to a file pointer.
*/
void create_cols_css(FILE *fp, Grid *grid);