#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ob(int in){
    if(in>0){
        ob(in/2);
        printf("%d",in%2);
    }
}
int main(){
    //movl 21 ,&eax
    //21=01 0101
    //01(virtual page number)
    //0101(offset)
    //---|
    //vp2|frame page 0   
    //---|
    //   |frame page 1
    //---|
    //vp0|2
    //---|
    //vp1|3
    //---|
    int pageTable[]={2,3,0};
    int shift=0b0100;
    int offMask=0b001111;
    int vpnMask=0b110000;
    
    int address=0b010101;

    int offset=(address&offMask);
    int vpn=(address&vpnMask)>>shift;
    int PhysAddr=(pageTable[vpn]<<shift)+offset;
   
    ob(PhysAddr);
    return 0;
}
