#include <iostream>

int main() {
    static const int N=10;
    double arr[N]={1.1,2.2,3.3,0.6,7.7,4.1,8.8,9.9,10.1,1.3};
    for (int k=1; k<=N;k++) {
        for (int i=0; i<N; i+=1) {
            if (i!=N-1) {
                if (arr[i]>arr[i+1]) {
                    double a=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=a;
                }
            }
        }
    }
    std::cout <<"Array ordinato: "<< arr[0] << " " << arr[1] << " " << arr[2] << " " <<arr[3] << " " <<arr[4] << " " <<arr[5] << " " <<arr[6] << " " <<arr[7] << " " <<arr[8] << " " <<arr[9] << " " << "\n";
    return 0;
}