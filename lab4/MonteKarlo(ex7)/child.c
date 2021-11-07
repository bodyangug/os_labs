#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>


const float a=-1.0f;
const float b=1.0f;
const float c=-1.0f;
const float d=1.0f;


float my_random (float a, float b) 
{
    float y;
    int x;
    x = rand(); 
    y = a + (x * (b - a)) / RAND_MAX; 
    return y;
}


int main(int argc,char** argv){
    if(argc<2)return -1;
    srand(time(NULL));
    int n=atoi(argv[1]);
    int cnt=0;
    float x,y;
    for(int i=0;i<n;i++){
        x=my_random(a,b);
        y=my_random(c,d);
        if(sqrt(x*x+y*y)<=1.0f)cnt++;
    }
    fprintf(stdout,"Cnt = %d\n",cnt);
    return cnt;
}
