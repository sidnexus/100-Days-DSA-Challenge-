#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){return a>b?a:b;}

int main() {
    int n;
    scanf("%d",&n);
    char task[1000];
    int freq[26]={0};
    for(int i=0;i<n;i++){
        scanf("%s",task);
        freq[task[0]-'A']++;
    }
    int cooldown;
    scanf("%d",&cooldown);
    int maxFreq=0,countMax=0;
    for(int i=0;i<26;i++){
        if(freq[i]>maxFreq){
            maxFreq=freq[i];
            countMax=1;
        } else if(freq[i]==maxFreq){
            countMax++;
        }
    }
    int res=max((maxFreq-1)*(cooldown+1)+countMax,n);
    printf("%d",res);
    return 0;
}
