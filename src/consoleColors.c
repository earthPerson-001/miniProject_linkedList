#include <stdio.h>
#include "consolecolors.h"


//Functions for changing colors

//red
void red () 
{
  printf("\033[1;31m");
}

//green
void green () 
{
  printf("\033[1;32m");
}

//yellow
void yellow()
{
    printf("\033[1;33m");
}

//blue
void blue ()
{
  printf("\033[1;34m");
}

//cyan
void cyan()
{
    printf("\033[1;36m");
}

//purple
void purple()
{
    printf("\033[1;35m");
}

//function for resetting the color
void reset () {
  printf("\033[0m");
}
