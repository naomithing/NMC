#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

//Structure to store the start and end points of each slice in a thread.
struct ThreadSlice {
    long long start;
    long long end;
};

//Thread function to compute the sum for the formula in different threads.
void *computePi(void *args) {
    long long i, start, end;
    struct ThreadSlice *slice = args;
    start = slice->start;
    end = slice->end;
    
    //Dynamically allocate memory for partial sum
    double *partialSum = malloc(sizeof(double));
    *partialSum = 0; //Initialize partial sum to 0.
	
	//Compute the sum part of the Leibniz formula.
    for (i = start; i <= end; i++) {
        *partialSum += pow(-1, i) / ((2 * i) + 1);
    }
	
	//Exit thread bu returning the partial sum to the calling fucntion.
    pthread_exit((void *)partialSum);
}

//Function to perform the calculation of Pi using the Leibniz formula and multithreading.
void calculatePi() {
    void *partialSum;
    double totalSum;
    int i, numThreads;
    long long numIterations;
    char choice;

    printf("\n Calculating Pi(%c) using Leibniz formula and multithreading", 227);
	
	//Display the Leibniz formula for PI.
    printf("\n\nLeibniz formula for PI:\n\n\t\t%c %c n=0  (-1)^n / (2*n + 1) = %c/4", 236, 228, 227);

	//Input for the number of iterations of the formula
    printf("\n\nEnter the number of iterations for the formula: ");
    scanf("%lld", &numIterations);
	
	//Input for the number of threads to be used
    printf("Enter the number of threads: ");
    scanf("%d", &numThreads);

	//Calculate remainder to evenly distribute among thread slices if any
    int remainder = numIterations % numThreads;
    long long slicedVal[numThreads];

	//Distribute slices evenly excluding the remainder, if any
    for (i = 0; i < numThreads; i++) {
        slicedVal[i] = numIterations / numThreads;
    }

	//Distribute the remainder iterations evenly among slices, if any
    for (i = 0; i < remainder; i++) {
        slicedVal[i] = slicedVal[i] + 1;
    }

	//Arrays to store the start and end points for each thread.
    long long startPt[numThreads], endPt[numThreads];

	//Allocate start and end points for each thread
    for (i = 0; i < numThreads; i++) {
        if (i == 0) {
            startPt[i] = 0; //Start point for the first thread (starting the calculation of pi from 0).
        } else {
            startPt[i] = endPt[i - 1] + 1; //Start points of other threads
        }
        endPt[i] = startPt[i] + slicedVal[i] - 1; //End points of threads
    }

    pthread_t threads[numThreads]; //Thread array variable
    struct ThreadSlice slice[numThreads]; //Structure initialization

	//Create threads and assign start and end points to each thread
    for (i = 0; i < numThreads; i++) {
        slice[i].start = startPt[i];
        slice[i].end = endPt[i];
        pthread_create(&threads[i], NULL, computePi, &slice[i]);
    }


    totalSum = 0;

	//Join threads to ensure all threads are completed
    for (i = 0; i < numThreads; i++) {
        pthread_join(threads[i], &partialSum);
        totalSum += *(double *)partialSum; //Add the values to the partial sum returned from the thread functions
    }
	
	//Display the estimated value of PI with the given number of iterations
    printf("\n\nThe estimated value of PI with %lld iterations: ", numIterations);
    printf("\n\n\t%c = %.14lf\n", 227, totalSum * 4); //Print the value of PI by multiplying the total sum by 4

    free(partialSum); //Free the dynamically allocated partial sum variable.
}

//Function to ask the user if they want to perform more calculations for the value of PI
void askForMoreCalculations() {
    char choice;

    printf("\nDo you want to calculate the value of PI(%c) with a different number of iterations? (y/n): ", 227);
    scanf(" %c", &choice);

	//Conditions based on user's choice
    if (choice == 'Y' || choice == 'y') {
        calculatePi();
    } else if (choice == 'N' || choice == 'n') {
        exit(0);
    } else {
        printf("\nPlease enter either 'y' or 'n'.");
        askForMoreCalculations();
    }
}

/*main function to initiate the calculation of PI, display results,
and handle user interaction.*/
int main() {
    calculatePi(); //Call function to perform initial PI calculation
    
	//Ask the user if they want to perform more calculations for the value of PI.
	askForMoreCalculations();

    return 0;
}
