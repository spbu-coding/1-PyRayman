#include <stdio.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265


float calculate_by_rectangles_method(int num_of_rect,  float leftborder, float rightborder){
        
    double step = (leftborder - rightborder)/num_of_rect ;    
    double sum = 0,area = 0;
    double height = 0, lenght = 0;

    for (int k = 1; k <= num_of_rect;k++){
        lenght = step*k;
        height = sin(lenght-step/2);    
        area = step * height;
        sum +=  area;   
    }
        
    return sum;

}

float calculate_by_simpson(int num_of_rect , float leftborder, float rightborder){

    double step = (rightborder - leftborder)/num_of_rect ;
    double sum = 0,area = 0;
    double height = 0, lenght = 0;

    for (int k = 0; k  < num_of_rect; k++){
         
        lenght = step*k;
          
        if (k % 2 == 0 ){
            height = 2 * sin(lenght);
        }
        else {
            height = 4 * sin(lenght);
        }   

        area = step/3 * height;         
        sum +=  area;
  
    }
    return sum;

}

void array_output(int* arr, int len, float leftborder, float rightborder){
    

    
    printf("\n INTERVAL: [ %f ; %f ]\n \n",leftborder,rightborder);
    printf("\t \t \t ************Results************ \n \n");
    printf(" |Number of Rectangles| \t |Rectangles Method| \t |Simpson Method|\n");
    for (int n = 0; n < len; n++){
        int element = arr[n];
        printf(" %d  \t \t \t \t  %.5f   \t \t  %.5f \n",element,calculate_by_rectangles_method(element,leftborder,rightborder),calculate_by_simpson(element,leftborder,rightborder));
    }
        
    
        
}

int main(){
    float leftborder,rightborder = -1;

    int arr[] = {6,10 ,20, 50, 100, 500, 1000};
    printf("Введите промежуток: \n ");
    scanf("%f %f",&leftborder, &rightborder);
    while (leftborder >= PI || leftborder < 0 || rightborder > PI || rightborder <= 0 || leftborder >= rightborder)
    {

        
        if (leftborder < 0 || leftborder >= PI )
        {
            printf("the left border must be in the interval [0,PI] \n Try again:\n");
            scanf("%f",&leftborder);
        }
        else if(rightborder <= 0 || rightborder > PI )
        {
            printf("the right border must be in the interval [0,PI]. \n Try again:\n");
            scanf("%f",&rightborder);

        }
        else if(rightborder <= leftborder)
        {
            printf("the left border must be less than the right border \n Try again:\n");
            scanf("%f %f",&leftborder,&rightborder);
        }
        
        
        
    }

    
    array_output(arr,7,leftborder,rightborder);

    return 0;
}