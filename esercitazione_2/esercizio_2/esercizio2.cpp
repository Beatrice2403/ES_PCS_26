#include <iostream>
#include <cmath>


int main() {
    static const int N=10;
    double arr[N]={1.1,2.2,3.3,0.6,7.7,4.1,8.8,9.9,10.1,1.3};
    double min=arr[0];
    double max=arr[0];
    double sum=0.0;
    double sommaquadrati=0.0;
    for (int i=0; i<N; i+=1) {
        if (min>arr[i]) {
            min=arr[i];
        }
        if (max<arr[i]) {
            max=arr[i];
        }
        sum=sum+arr[i];
        sommaquadrati= sommaquadrati+arr[i]*arr[i];
    }
    double media=sum/N;
    double mediaquadrati=sommaquadrati/N;
    double deviazionestandard=sqrt(mediaquadrati-media*media);
    std::cout <<"Minimo: "<< min << "\n";
    std::cout <<"Massimo: "<< max << "\n";
    std::cout <<"Media: "<< media << "\n";
    std::cout <<"Deviazione standard: "<< deviazionestandard << "\n";

    return 0;
}