/*!
 * @file      	main.c
 * @abstract    All main functions
 * @discussion  This file contains all source code for main
 *              and is the entry point for Grid Generator, a fully
 *              responsive CSS/HTML template generator.
 * @version     0.0.2 May 13 2015
 * @author      Dan White <dwhite@teddyray.net>
 * @see         main.h#
 * @link        Dan White's Development Portal <http://teddyray.net>
*/

#include <stdio.h>
#include <stdlib.h>
#include <cssgenerator.h>
#include <htmlgenerator.h>
#include <main.h>

int main(int argc, char *argv[]){

    Stylesheet stylesheet;

    output_intro();

    stylesheet = input_stylesheet();

    output_css(&stylesheet);
    output_html_tpl(&stylesheet);
    output_outro();

    return 0;
}

void output_intro(){
    printf("+==============================================================+\n");
    printf("|         Welcome to the Responsive CSS Grid Generator         |\n");
    printf("+==============================================================+\n");
    printf("                                    By Dan White  Version %s\n\n", VERSION);

    printf("Enter values in desired pixels to create a fully responsive grid\n");
    printf("template in percentages and ems.\n\n");

    printf("Press <enter> to continue...\n");
    getchar();
}	

void output_outro(){
    printf("\nSuccessfully completed stylesheet and html template\n");
    printf("They are located in the /created_grid directory\n\n");
    printf("Press <enter> to exit...");
    getchar();
    getchar();
	
}

/* Output css grid template */
void output_css(Stylesheet *sty){
    FILE *cssHeader_fp, *css_fp;

    cssHeader_fp = fopen("../res/shead", "r");
    css_fp = fopen ("../created_grid/style.css", "w+");

    combine_file(css_fp, cssHeader_fp);
    fclose(cssHeader_fp);

    create_stylesheet(css_fp, sty);

    fclose(css_fp);
	
}

/* Output demo html template */
void output_html_tpl(Stylesheet *sty){
    FILE *idx_fp, *htmlHeader_fp, *htmlFooter_fp;

    htmlHeader_fp = fopen("../res/header", "r");
    htmlFooter_fp = fopen("../res/footer", "r");

    idx_fp = fopen ("../created_grid/index.html", "w+");

    combine_file(idx_fp, htmlHeader_fp);
    fclose(htmlHeader_fp);

    create_frac_col(idx_fp, sty->numcol);
    create_div_grid(idx_fp, sty->numcol);

    combine_file(idx_fp ,htmlFooter_fp);
    fclose(htmlFooter_fp);

    fclose(idx_fp);
	
}

/* Combine files */
void combine_file(FILE *dest_fp, FILE *source_fp){
    char ch;

    if(dest_fp == NULL || source_fp == NULL){
        puts("ERROR: Could not open files");
    exit(0);
    }

    while((ch = fgetc(source_fp)) != EOF ){
        fputc(ch,dest_fp);
    }
}