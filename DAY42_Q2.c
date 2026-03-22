#include <stdio.h>
#include <stdlib.h>

int maxHeap[50000], maxSize=0;
int minHeap[50000], minSize=0;

void heapifyUpMax(int i){
    while(i>0){
        int p=(i-1)/2;
        if(maxHeap[p]<maxHeap[i]){
            int t=maxHeap[p]; maxHeap[p]=maxHeap[i]; maxHeap[i]=t;
            i=p;
        } else break;
    }
}

void heapifyDownMax(int i){
    while(2*i+1<maxSize){
        int l=2*i+1, r=2*i+2, largest=i;
        if(l<maxSize && maxHeap[l]>maxHeap[largest]) largest=l;
        if(r<maxSize && maxHeap[r]>maxHeap[largest]) largest=r;
        if(largest!=i){ int t=maxHeap[i]; maxHeap[i]=maxHeap[largest]; maxHeap[largest]=t; i=largest;}
        else break;
    }
}

void heapifyUpMin(int i){
    while(i>0){
        int p=(i-1)/2;
        if(minHeap[p]>minHeap[i]){
            int t=minHeap[p]; minHeap[p]=minHeap[i]; minHeap[i]=t;
            i=p;
        } else break;
    }
}

void heapifyDownMin(int i){
    while(2*i+1<minSize){
        int l=2*i+1, r=2*i+2, smallest=i;
        if(l<minSize && minHeap[l]<minHeap[smallest]) smallest=l;
        if(r<minSize && minHeap[r]<minHeap[smallest]) smallest=r;
        if(smallest!=i){ int t=minHeap[i]; minHeap[i]=minHeap[smallest]; minHeap[smallest]=t; i=smallest;}
        else break;
    }
}

void addNum(int num){
    if(maxSize==0 || num<=maxHeap[0]){
        maxHeap[maxSize++]=num;
        heapifyUpMax(maxSize-1);
    } else {
        minHeap[minSize++]=num;
        heapifyUpMin(minSize-1);
    }
    if(maxSize>minSize+1){
        minHeap[minSize++]=maxHeap[0];
        maxHeap[0]=maxHeap[--maxSize];
        heapifyDownMax(0);
        heapifyUpMin(minSize-1);
    } else if(minSize>maxSize){
        maxHeap[maxSize++]=minHeap[0];
        minHeap[0]=minHeap[--minSize];
        heapifyDownMin(0);
        heapifyUpMax(maxSize-1);
    }
}

double findMedian(){
    if(maxSize>minSize) return (double)maxHeap[0];
    else return ((double)maxHeap[0]+(double)minHeap[0])/2.0;
}

int main(){
    addNum(1);
    addNum(2);
    printf("%.1f\n", findMedian());
    addNum(3);
    printf("%.1f\n", findMedian());
    return 0;
}
