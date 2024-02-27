#include <stdio.h>
#include "lodepng.h"
void main(){
	unsigned int w,h;
    unsigned char *pixels;
    unsigned error;
    error = lodepng_decode32_file(&pixels, &w, &h, "Doraemon.png");
    printf("%s", lodepng_error_text(error));
    
    int i;
    for(i=0;i<h*w*4;i=i+4){
        pixels[i] = 255 - pixels[i];
        pixels[i+1] = 255 - pixels[i+1];
        pixels[i+2] = 255 - pixels[i+2];
    }
    lodepng_encode32_file("negative.png",pixels, w,h);
}
