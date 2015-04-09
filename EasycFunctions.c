// EasycFunctions.c : implementation file
#include "Main.h"
#include "PixyLib.h"

// *** easyC block function proxies ***

// Replaces Initialize()
void _Initialize()
{
}

// Replaces Autonomous()
void _Autonomous()
{
}

// Replaces OperatorControl()
void _OperatorControl()
{
    while(1) // Insert your RC code below
    {
       int i=0, curr, prev=0;
       
       // My updates to sample
       OpenSerialPort(DEFAULT_PIXY_PORT, DEFAULT_PIXY_BAUD_RATE);
       Wait(50);
       PixyInit();
     
       // look for two start codes back to back
       while(1)
       {
         curr = PixyGetStart();
         if (prev && curr) // two start codes means start of new frame
           printf("%d", i++);
         prev = curr;
       }
    }
}





