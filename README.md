c-responsive-css-grid-generator
=================================
Author: Dan White

This is a cross-platform C command-line program to generate fully responsive mobile-first css grid templates in percentages and ems from hard pixel values.

It will ask the user for a few simple document properties and dimensions much like creating a new document with columns, margins and gutters in InDesign. Then like magic it translates the input into a responsive css and html template for creating a flexible, cross-browser friendly, bulletproof responsive layout without all the clutter brought with using frameworks like Bootstrap. Not only can the user specify any odd or even column assortment and gutter arrangement they want, but the grid this application generates even leaves the flexibility for backgrounds and other elements to expand past content breakpoints, by wrapping them around the grid rows for filler on really large displays, televisions, etc.

This project was born out of wanting to make use of some of the things I have been learning with C lately to turn into a valuable web tool that eliminates a nice chunk of front-end build time sitting around with 3 calculators, laboriously cutting and pasting only to have maybe made a miscalculation by .001% somewhere and having to redo it.

### Version
0.0.2

### Pre-compiled Downloads

If you don't want to compile the application, but would like to see it in action, grab one of my pre-compiled downloads for your OS.

- [Windows](http://teddyray.net/download/applications/css-grid-generator-0.0.2/css-grid-generator-0.0.2-win.zip)
- [Linux](http://teddyray.net/download/applications/css-grid-generator-0.0.2/css-grid-generator-0.0.2-linux.tar.gz)
- [OS X](http://teddyray.net/download/applications/css-grid-generator-0.0.2/css-grid-generator-0.0.2-macosx.zip) 
***Note:** When running from OS X open terminal first and navigate to the file executing with `./gridgenerator` due to permissions and how terminal opens at `~` when clicking on the executable through the finder will make the application fail.

## Installation
In order to compile use make. 

**Note for OS X:** When compiling on OS X make sure to use gcc from somewhere like homebrew as I had Issues successfully compiling with Apple's gcc linked clang.

```
make gridgenerator
```

Clean up the object files from compiling

```
make clean
```

## Usage

This grid generator is highly influenced by InDesign and accepts the same type of inputs for creating a Document. In the `bin/created_grid` directory I have included a generated a standard 960/1200px 12 column grid css and html file using the values:
``` 
Number of oolumns
>12
Number of desktop breakpoints (5 maximum)
>2
Enter Desktop breakpoint 1
>768
Desktop Breakpoint 1 Document width
>960
Document Left/Right Margins
>10
Document Gutter width
>20
Enter Desktop breakpoint 2
>1200
Desktop Breakpoint 2 Document width
>1200
Document Left/Right Margins
>15
Document Gutter width
>30
```

## Known Issues
This program has been an exercise for learning how to program in C and apply it to a custom application that I could actually use. That being said, there are a few issues as I am new to C and still applying what I learn on the daily.

- The user is expected to enter input accurately, I have not provided any real validation yet.
- Since this grid generator is mobile first, that means it won't work on IE <= 8 because it doesn't understand media queries.

## Todo

- [ ] Making a few changes to allow selecting a desktop grid as the default styles outside of the media queries to support IE <= 8 for those who need it.
- [ ] I am starting to play with the sqlite3 library in order to add a local database to save new grids or recall old ones.
- [ ] Input validation.
- [ ] More effective makefile to create dependent directories and delete old ones from compiling.

### Legal
This code is released under the [GNU General Public License version 2](http://www.gnu.org/licenses/gpl-2.0.txt).

Author & copyright (c) 2015: [Dan White](http://teddyray.net)