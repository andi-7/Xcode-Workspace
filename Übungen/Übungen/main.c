//
//  main.c
//  Übungen (3. Beispiel beim Test)
//
//  Created by Andreas Starzer on 05.06.18.
//  Copyright © 2018 Andreas Starzer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


//Largest Sum of two
int largestSumof2(int len, int arr[len]){
    
    int sum;
    int max1;
    int stelle1=0;
    int max2;
    int i;
    
    max1=arr[0];
    max2=arr[0];
    
    for(i=0;i<=len-1;i++){
        if(arr[i+1]>arr[i]){
            max1=arr[i+1];
            stelle1+=1;
        }
    }
    
    for(i=0;i<=stelle1-1;i++){
        if(arr[i+1]>arr[i]){
            max2=arr[i+1];
        }
    }
    
    for(i=stelle1+1;len-stelle1;i++){
        if(arr[i+1]>arr[i]){
            max2=arr[i+1];
        }
    }
    
    sum=max1+max2;
    return sum;
    
    //Testbeispiel -> muss noch kürzer gehen
}

int *buchstaben(char *str){
    if(!str) return NULL;
    
    int *arr1=calloc(27,sizeof(int));
    int i;
    
    for(i=0; i<strlen(str); i++){
        if(str[i]>='a' && str[i]<='z'){
            arr1[str[i]-'a']+=1;
        } else if(str[i]>='A' && str[i]<='Z') {
            arr1[str[i]-'A']+=1;
        } else {
            arr1[27]+=1;
        }
        i++;
    }
    return arr1;
}





int main(int argc, const char * argv[]) {
  
    
    
    
    
    
    /*
    int arr1[10];
    int i;
   //int j;
    
   
    for(i=0; i<=9; i++) {
        arr1[i]=i+1;
    }
    
    printf("%d\n",largestSumof2(10, arr1));
    
    
    
    for(j=0; j<=9; j++) {
        printf("%d\n",arr1[j]);
    }
    */
    
    
    
    return 0;
}
