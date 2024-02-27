#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "lodepng.h"

//Structure to hold the start points, end points, width, and height of the image slice for each thread
struct PixelThreads{
	int start, end;
	unsigned int width, height;
};

//Global arrays to hold the original and blurred images
unsigned char *origImg;
unsigned char *blurredImg;

//Function to apply blur to a portion of the image assigned to a thread
void *applyBlur(void *args){
	int i, k, l, div, R, G, B;
	struct PixelThreads *threads = args;
	int start = threads->start, end = threads->end;
	unsigned int width = threads->width, height = threads->height;
	
	for(i=start; i<=end; i++){
		R=G=B=0;
		
		//Logic for calculating average color values based on neighbouring pixels
		if(i==0){
			R += origImg[i+4]+origImg[i+(width*4)]+origImg[(width*4)+i+4]+origImg[i];
			G += origImg[i+5]+origImg[i+(width*4)+1]+origImg[(width*4)+i+5]+origImg[i+1];
			B += origImg[i+6]+origImg[i+(width*4)+2]+origImg[(width*4)+i+6]+origImg[i+2];
			div = 4;
		}
		else if(i == ((width*4)-4)){
			R += origImg[i-4] + origImg[i+(width*4)] + origImg[(width*4)+i-4] + origImg[i];
			G += origImg[i-3] + origImg[i+(width*4)+1] + origImg[(width*4)+i-3] + origImg[i+1];
			B += origImg[i-2] + origImg[i+(width*4)+2] + origImg[(width*4)+i-2] + origImg[i+2];
			div = 4; 
		}
		//taking average for the BOTTOM LEFT CORNER pixel of the image
		else if(i == (width*4*(height-1))){
			R += origImg[i+4] + origImg[i-(width*4)] + origImg[i-(width*4)+4] + origImg[i];
			G += origImg[i+5] + origImg[i-(width*4)+1] + origImg[i-(width*4)+5] + origImg[i+1];
			B += origImg[i+6] + origImg[i-(width*4)+2] + origImg[i-(width*4)+6] + origImg[i+2];	
			div = 4;
		}
		//taking average for the BOTTOM RIGHT CORNER pixel of the image
		else if(i == ((width*height*4)-4)){
			R += origImg[i-4] + origImg[i-(width*4)] + origImg[i-(width*4)-4] + origImg[i];
			G += origImg[i-3] + origImg[i-(width*4)+1] + origImg[i-(width*4)-3] + origImg[i+1];
			B += origImg[i-2] + origImg[i-(width*4)+2] + origImg[i-(width*4)-2] + origImg[i+2];
			div = 4;
		}
		//taking average for the LEFT COLUMN pixels of the image 
		else if((i%(width*4)) == 0){
			for(k=i-(width*4); k<=(i+(width*4)); k+= (width*4)){
				for(l=k; l<=k+4; l+=4){
					R += origImg[l];
					G += origImg[l+1];
					B += origImg[l+2];
				}
			}
			div = 6; //as the pixel is surrounded by 5 other pixels
		}
		//taking average for the RIGHT COLUMN pixels of the image
		else if((i%(width*4)) == ((width*4)-4)){
			for(k=(i-(width*4)); k<=(i+(width*4)); k+=(width*4)){
				for(l=k; l>=(k-4); l-=4){
					R += origImg[l];
					G += origImg[l+1];
					B += origImg[l+2];
				}
			}
			div = 6;
		}
		//taking average for the TOP ROW pixels of the image
		else if(i!=0 && i<((width*4)-4)){
			for(k=0; k<=(width*4); k += (width*4)){
				for(l=i-4; l<=(i+4); l+=4){
					R += origImg[k+l];
					G += origImg[k+l+1];
					B += origImg[k+l+2];
				}
			}
			div = 6;
		}
		//taking average for the BOTTOM ROW pixels of the image
		else if(i > (width*4*(height-1)) && i < ((width*height*4)-4)){
			for(k=(-(width*4)); k<=0; k+=(width*4)){
				for(l=(i-4); l<=(i+4); l+=4){
					R += origImg[k+l];
					G += origImg[k+l+1];
					B += origImg[k+l+2];
				}
			}
			div = 6;
		}
		//taking average for ALL OTHER pixels of the image
		else {
			for(k=(i-4); k<=(i+4); k+=4){
				for(l=(k-(width*4)); l<=(k+(width*4)); l+=(width*4)){
					R += origImg[l];
					G += origImg[l+1];
					B += origImg[l+2];
				}
			}
			div = 9;
		}
		
		//Assigning the blurred values to the new image array
		blurredImg[i] = R/div;
		blurredImg[i+1] = G/div;
		blurredImg[i+2] = B/div;
		blurredImg[i+3] = origImg[i + 3]; //Copying alpha value
	}
	
	pthread_exit(0);
}

int main(){
	int i, numThreads;
	unsigned int error, width, height;
	unsigned char *png;
	char inputFile[100], outputFile[100];
	
	//Reading input file name from the user
	printf("\n Gaussian Blur with multithreading. \n");
	printf("\n\nEnter an input file name: ");
	scanf("%s", inputFile);
	
	//Decoding the image file into the originalImage array
	error = lodepng_decode32_file(&origImg, &width, &height, inputFile);
	
	if(error){
		printf("\nError in decoding image %u: %s\n", error, lodepng_error_text(error));
		exit(0);
	}
	printf("\nImage dimensions: %d X %d \n Total number of pixels: %d\n", height, width, width*height);
	
	//Allocating memory for the blurred image array
	blurredImg = malloc((width*height)*sizeof(int));
	
	//Reading the number of threads from the user
	printf("Enter the number of threads: ");
	scanf("%d", &numThreads);
	
	//Calculating the number of pixels to be processed by each thread	
	int remainder = (width*height)%numThreads;
	int slicedVal[numThreads];
		
	for(i=0; i<numThreads; i++){
		slicedVal[i] = (width*height)/numThreads;
	}
		
	for(i=0; i<remainder; i++){
		slicedVal[i]=slicedVal[i]+1;
	}
	
	//Calculating start and end points for each thread	
	int startPts[numThreads], endPts[numThreads];
		
	for(i=0; i<numThreads; i++){
		if(i==0){
			startPts[i]=0;
		}else{
			startPts[i]=endPts[i-1]+4;
		}
		endPts[i]=startPts[i]+(slicedVal[i]*4)-4;
	}
	
	//Creating thread array and structure array to pass thread parameters
	pthread_t threads[numThreads];
	struct PixelThreads slice[numThreads];
	
	//Creating threads and assigning tasks to each thread
	for(i=0; i<numThreads; i++){
		slice[i].start = startPts[i];
		slice[i].end = endPts[i];
		slice[i].width = width;
		slice[i].height = height;
		pthread_create(&threads[i], NULL, applyBlur, &slice[i]);
	}
	
	//Joining threads to wait for their completion
	for(i = 0; i<numThreads; i++){
		pthread_join(threads[i], NULL);
	}
	
	//Saving the blurred image to an output file
	printf("\n\t\t Image Blurred \n\n\n Enter an output file name to save the blurred image: ");
	scanf("%s", outputFile);
	size_t pngSize;
	error = lodepng_encode32(&png, &pngSize, blurredImg, width, height);
	
	if(!error){
		lodepng_save_file(png, pngSize, outputFile);
	}else{
		printf("Error in encoding image %u: %s\n", error, lodepng_error_text(error));
	}
	
	printf("\n\nThe blurred image '%s' has been saved in the same directory.\n\n", outputFile);
	
	//Freeing memory
	free(origImg);
	free(blurredImg);
	
	return 0;
}
