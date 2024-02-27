#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

//Structure to store the start and end points for each thread's slice.
struct ThreadSlice{
	int start;
	int end;
};

int *numArr; //integer pointer globally created. Array to store the read numbers from files
FILE *outputFile;

//Thread function to check for prime numbers within a specified range.
void *checkPrimeThread(void *args){
	int i, j, start, end;
	struct ThreadSlice *thread = args;
	start = thread->start;
	end = thread->end;
	
	//Allocate memory for the prime count of this thread.
	int *primeCount = malloc(sizeof(int));
	*primeCount = 0;
	
	//Loop through the range to find prime numbers
	for(i=start;i<=end;i++){
		for(j=2;j<=numArr[i]-1;j++){
			if(numArr[i]%j==0){
				break;
			}
		}
		
		//If j equals the number, it's prime.
		if(j==numArr[i]){
			fprintf(outputFile, "%d\n", numArr[i]);
			*primeCount += 1;
		}
	}
	
	pthread_exit((void *)primeCount); //Exit the thread, returning the prime count
}

int main(){
	void *primes;
	int i, num, totalNum = 0, numThreads, arrCount = 0, numFiles = 3, totalPrime;
	char eof, inputFile[20];
	
	printf("Finding prime numbers from multiple text files using multithreading.\n\n\n");
	
	
	for(i=1;i<=numFiles;i++){
		sprintf(inputFile, "PrimeData%d.txt", i);
		FILE *currentFile = fopen(inputFile, "r");
		while(1){
			eof = fscanf(currentFile, "%d", &num);
			if(eof == EOF){
				break;
			}
			totalNum++;
		}
		fclose(currentFile);
	}
	
	numArr = malloc(totalNum *sizeof(int));
	printf("The total numbers in the %d files are: %d\n\n", numFiles, totalNum);
	printf("Enter the number of threads: ");
	scanf("%d", &numThreads);
	
	//Read numbers from files and store them in an array
	for(i=1;i<=numFiles;i++){
		sprintf(inputFile, "PrimeData%d.txt", i);
		FILE *currentFile = fopen(inputFile, "r");
		
		while(1){
			eof = fscanf(currentFile, "%d", &numArr[arrCount]);
			arrCount++;
			if(eof==EOF){
				break;
			}
		}
		fclose(currentFile);
	}
	
	outputFile = fopen("PrimeNumbers.txt", "a");
	
	//Determine the slice boundaries for each thread.
	int remainder = totalNum % numThreads;
	int slicedVal[numThreads];
	
	for(i=0; i<numThreads; i++){
		slicedVal[i] = totalNum/numThreads;
	}
	
	//Adjust the slices for my remainder
	for(i=0; i<remainder; i++){
		slicedVal[i]=slicedVal[i]+1;
	}
	
	//Calculate start and end points for each thread.
	int startPts[numThreads], endPts[numThreads];
	
	for(i=0; i<numThreads; i++){
		if(i==0){
			startPts[i]=0;
		}else{
			startPts[i]=endPts[i-1]+1;
		}
		endPts[i] = startPts[i]+slicedVal[i]-1;
	}
	
	//Create threads with specified slices
	pthread_t threads[numThreads];
	struct ThreadSlice threadSlices[numThreads];
	
	for(i=0; i<numThreads; i++){
		//putting the start and end points in the structure to pass to the threads as parameters.
		threadSlices[i].start = startPts[i];
		threadSlices[i].end = endPts[i];
		pthread_create(&threads[i], NULL, checkPrimeThread, &threadSlices[i]); //Creating thread.
	}
	
	totalPrime = 0;
	
	for(i=0; i< numThreads; i++){
		//Join threads and accumulate the total count of prime numbers
		pthread_join(threads[i], &primes);
		totalPrime += *(int*)primes;
	}
	printf("\n\nTotal prime numbers in the %d files: %d\n\n", numFiles, totalPrime);
	printf("Note: All the prime numbers are written in a textfile names 'PrimeNumbers' in the same directory.");
	
	fprintf(outputFile, "\nTotal number of prime number: %d\n", totalPrime);
	
	free(numArr); //freeing dynamically created numArr array.
	free(primes); //freeing dynamically allocated primeCount variable.
	fclose(outputFile); //closing the file pointer.
	
	return 0;
}
