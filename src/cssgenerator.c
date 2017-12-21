/*!
 * @file      	cssgenerator.c
 * @abstract    All html generation functions
 * @discussion  This file contains all source code for cssgenerator.
 * 		It is responsible for converting and generating all user
 * 		input from hard pixel values to fully responsive grid definitions.
 * @version     0.0.2 May 13 2015
 * @author      Dan White <dwhite@teddyray.net>
 * @see         cssgenerator.h#
 * @link        Dan White's Development Portal <http://teddyray.net>
*/

#include <stdio.h>
#include <stdlib.h>
#include <cssgenerator.h>
#include <css_util.h>

/* get stylesheet breakpoints */
Stylesheet input_stylesheet(){
    Stylesheet s;

    s.baseline = BASELINE;

    printf("Number of columns\n>");
    scanf("%d", &s.numcol);
    printf("Number of desktop breakpoints (5 maximum)\n>");
    scanf("%d", &s.breakpointCount);

    for(int i = 0; i < s.breakpointCount; i++){	
        printf("Enter Desktop breakpoint %d\n>", i+1);
        scanf("%d", &s.breakpoints[i]);
        printf("Desktop Breakpoint %d ", i+1);
        s.doc[i] = input_doc();
        s.grid[i] = create_grid(&s.doc[i], s.numcol);
    }
    return s;
}

/* get document dimensions */
Document input_doc(){
    Document d;
    printf("Document width\n>");
    scanf("%d", &d.width);
    printf("Document Left/Right Margins\n>");
    scanf("%d", &d.lrMargins);
    printf("Document Gutter width\n>");
    scanf("%d", &d.gutter);

    return d;
}

/* Set up the actual grid */
Grid create_grid(Document *doc, int numcol){
    Grid g;
    g.contentWidth = doc->width - doc->lrMargins*2;
    g.totalGutterWidth = doc->gutter * (numcol-1);
    g.totalColWidth = g.contentWidth - g.totalGutterWidth;
    g.marginCount = numcol-1;
    g.margin = doc->gutter;

    g.colWidth = f_round((float)g.totalColWidth/numcol,D_PRECISION);
    g.nextCol = g.colWidth + doc->gutter;
    return g;
}

/* Create the stylesheet itself */
void create_stylesheet(FILE *fp, Stylesheet *sty){
    for(int i = 0; i < sty->breakpointCount; i++){
        if(i == 0){
            fprintf(fp, "\n\n.gridrow {\n\tmargin: 0 auto;\n\tpadding: 0 %g%%; /* %dpx/%dpx */\n\tclear:both;\n}\n"
                ,convertpx_to_perc(sty->doc[i].lrMargins, sty->doc[i].width), sty->doc[i].lrMargins, sty->doc[i].width);
            create_default_css(fp, &sty->grid[i]);
        }
        // Start media queries
        if(i == sty->breakpointCount-1){
            fprintf(fp,"/* %gem = %dpx/%dpx */\n"
                ,convertpx_to_em(sty->breakpoints[i], BASELINE), sty->breakpoints[i], BASELINE);
            fprintf(fp,"@media all and (min-width:%gem){\n\n", convertpx_to_em(sty->breakpoints[i],BASELINE));
        }else{
            fprintf(fp,"/* %gem = %dpx/%dpx;\t%gem = %dpx/%dpx */\n"
                ,convertpx_to_em(sty->breakpoints[i], BASELINE), sty->breakpoints[i], BASELINE
                ,convertpx_to_em(sty->breakpoints[i+1]-1, BASELINE), sty->breakpoints[i+1]-1, BASELINE);
            fprintf(fp,"@media all and (min-width:%gem) and (max-width:%gem){\n\n"
                ,convertpx_to_em(sty->breakpoints[i], BASELINE),convertpx_to_em(sty->breakpoints[i+1]-1, BASELINE));
        }

        create_row_css(fp, &sty->doc[i]);
        create_marg_css(fp, &sty->grid[i]);
        create_cols_css(fp, &sty->grid[i]);
        fprintf(fp, "}\n\n");
    }
}

/* Create gridrow definitions for a breakpoint */
void create_row_css( FILE *fp, Document *doc){
    fprintf(fp, "\t.grid-container {\n\t\tpadding:0;\n\t}\n");
    fprintf(fp, "\t.gridrow {\n\t\tmax-width: %gem; /* %dpx/%dpx */\n\t\tpadding:0 %g%%; /* %dpx/%dpx */\n\t}\n"
        ,convertpx_to_em(doc->width, BASELINE), doc->width, BASELINE, convertpx_to_perc(doc->lrMargins, doc->width),doc->lrMargins,doc->width);
    fprintf(fp, "\t.gridrow [class^=\"col\"] {\n\t\tmargin-bottom: %gem; /* %dpx/%dpx */\n\t}\n\n"
        ,convertpx_to_em(doc->gutter, BASELINE), doc->gutter, BASELINE);	
    fprintf(fp, "\t.gridrow :last-child[class^=\"col\"] {\n\t\tmargin: 0 0 %gem 0; /* %dpx/%dpx */\n\t}\n"
        ,convertpx_to_em(doc->gutter, BASELINE), doc->gutter, BASELINE);
}

/* Create default css for main mobile breakpoint before media queries */
void create_default_css(FILE *fp, Grid *grid){
    fprintf(fp, "\n.gridrow [class^=\"col\"] {\n\tmargin-bottom: %gem; /* %dpx/%dpx */\n}\n\n"
        ,convertpx_to_em(grid->margin, BASELINE), grid->margin, BASELINE);	
    fprintf(fp, ".gridrow :last-child[class^=\"col\"] {\n\tmargin: 0 0 %gem 0; /* %dpx/%dpx */\n}\n\n"
        ,convertpx_to_em(grid->margin, BASELINE), grid->margin, BASELINE);

    for(int i = 0; i <= grid->marginCount; i++){
        if(i == grid->marginCount){
            fprintf(fp, ".col%d { width: 100%%; margin:0;}\n\n",i+1);
        }else if(i == grid->marginCount-1){
            fprintf(fp, ".col%d { \n\tfloat: none;\n\twidth: 100%%;\n\tmargin: 0 %g%% 0 0; /* %dpx/%dpx */\n}\n"
                ,i+1,convertpx_to_perc(grid->margin, grid->contentWidth), grid->margin, grid->contentWidth);
        }else{
            fprintf(fp, ".col%d,\n",i+1);
        }		
    }
}

/* Create percentage based gutter definition for all columns */
void create_marg_css(FILE *fp, Grid *grid){
    for(int i = 0; i < grid->marginCount; i++){
        if(i == grid->marginCount-1){
            fprintf(fp, "\t.col%d{\n\t\tfloat: left;\n\t\tmargin: 0 %g%% 0 0; /* %dpx/%dpx */\n\t}\n\n"
                ,i+1, convertpx_to_perc(grid->margin, grid->contentWidth), grid->margin, grid->contentWidth);
        }else{
            fprintf(fp, "\t.col%d,\n",i+1);
        }		
    }
}

/* Create percentage based column definitions */
void create_cols_css( FILE *fp, Grid *grid){
    for(int i = 0; i <= grid->marginCount; i++){
        if(i == grid->marginCount){
            fprintf(fp, "\t.col%d { width: %d%%; margin:0;}\n",i+1,100);
        }else{
            fprintf(fp, "\t.col%d { width: %g%%; } /* %gpx/%dpx */\n"
                ,i+1,convertpx_to_perc(grid->colWidth, grid->contentWidth), grid->colWidth, grid->contentWidth);
        }		
        grid->colWidth += grid->nextCol;
    }
}
