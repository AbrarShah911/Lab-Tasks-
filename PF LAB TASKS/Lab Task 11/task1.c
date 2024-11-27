#include <stdio.h>
#include <stdbool.h>

typedef struct Rectangle
{
    float width;
    float height;
}Rectangle;

bool check(Rectangle exampleRectangle){
    if(exampleRectangle.height > 0.0 && exampleRectangle.width >0.0){
        return true;
    }else{
        return false;
    }
}

float calculateArea(Rectangle exampleRectangle){
    if(check(exampleRectangle)){
        float area = exampleRectangle.height * exampleRectangle.width;
        return area;
    }else{
        printf("The width or height is huh??");
        return 0.0;
    }
}

int main(){
    Rectangle myRectangle;

    myRectangle.width = 7.6;
    myRectangle.height = 14.93;

    float area = calculateArea(myRectangle);
    printf("%.4f",area);
    return 0;
}