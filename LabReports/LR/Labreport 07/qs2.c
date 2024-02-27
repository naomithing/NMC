#include <stdio.h>
#include "lodepng.h"
void main(){
	unsigned int w,h;
    unsigned char *pixels;
    unsigned error;
    error = lodepng_decode32_file(&pixels, &w, &h, "Doraemon.png");
    printf("%s", lodepng_error_text(error));
    
    int i;
    for (i=0; i<h*w*4; i=i+4){
        int grey = (pixels[i]+pixels[i+1]+pixels[i+2])/3;
        pixels[i] = grey; 
        pixels[i+1] = grey;
        pixels[i+2]= grey;
    }
    lodepng_encode32_file("grey.png",pixels,w,h);
}
