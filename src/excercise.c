#include <stdio.h>
#include <math.h>
#include <string.h>


float rectangles(int count,  float a, float b){
    
        
    double h = (b - a)/count ;
        
    double sum = 0,area = 0;
    double height = 0, lenght = 0;

    for (int k = 1; k <= count;k++){
        lenght = h*k;
           
        height = sin(lenght-h/2);
            
        area = h * height;
        sum +=  area;
            

    }
        
    return sum;
        
    

    
    

}

float simpson(int count , float a, float b){

    
        
        
    double h = (b - a)/count ;
        
        
    double sum = 0,area = 0;
    double height = 0, lenght = 0;

    for (int k = 0; k  < count; k++){
         
        lenght = h*k;
          
        if (k % 2 == 0 ){

            height = 2 * sin(lenght);
        }
        else {
            height = 4 * sin(lenght);
        }
            
            
        area = h/3 * height;
            
        sum +=  area;
        
        
        
    }

    
    return sum;

}

void array_output(int* arr, int len, float a, float b){
    

    
    printf("INTERVAL: [ %f ; %f ]\n",a,b);
    printf("************Results************ \n");
    printf("---Simpson Method---\n");
    for (int n = 0; n < len; n++){
        int element = arr[n];
        printf("#%d %.5f \n",n,simpson(element,a,b));
    }
        
    printf("---Rectangles Method---\n");
    for (int n = 0; n < len; n++){
        int element = arr[n];
        printf("#%d %.5f \n",n,rectangles(element,a,b));
    }
        
        


    
   
    
}

int main(){
    float a,b;

    int arr[] = {6,10 ,20, 50, 100, 500, 1000};
    
    
    printf("Введите промежуток: \n ");
    scanf("%f %f",&a,&b);
    
    array_output(arr,7,a,b);

    

    return 0;
}