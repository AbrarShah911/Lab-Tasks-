#include <stdio.h>

int checkRope(int rope){

    if(rope == 0){ //Checking if the rope length is 0.
        return 0;
    }

    if(rope<0){ //Checking if the rope cut is an invalid cut.
        return -1;
    }

    int cutFor1 = checkRope(rope-1); 
    int cutFor2 = checkRope(rope-2);
    int cutFor3 = checkRope(rope-3);

    // Finding the maximum in all the cuts that were made
    int maxCut = (cutFor1 > cutFor2) ? (cutFor1 > cutFor3 ? cutFor1 : cutFor3) : (cutFor2 > cutFor3 ? cutFor2 : cutFor3);

    if(maxCut == -1){
        return -1;
    }else{
        return maxCut + 1;
    }
}


int main(){

    int rope = 50;
    int result = checkRope(rope);

    if (result == -1) {
        printf("The rope cannot be cut into pieces of length 1, 2, or 3.\n");
    } else {
        printf("The maximum number of pieces the rope can be cut into is: %d\n", result);
    }

    return 0;
}