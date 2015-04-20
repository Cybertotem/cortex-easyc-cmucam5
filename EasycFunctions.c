// EasycFunctions.c : implementation file
#include "Main.h"
#include "PixyLib.h"

// *** easyC block function proxies ***

// Replaces Initialize()
void _Initialize()
{
	RegisterRepeatingTimer(1000, RefreshDebugOutput);
     //OpenSerialPort(DEFAULT_PIXY_PORT, DEFAULT_PIXY_BAUD_RATE);
     OpenSerialPortEx(
     	DEFAULT_PIXY_PORT,
     	DEFAULT_PIXY_BAUD_RATE,
     	USART_WORD_LENGTH_8B,
     	USART_STOP_BITS_1,
     	USART_PARITY_NO,
     	USART_HARDWARE_FLOW_CONTROL_NONE,
     	USART_MODE_RX);
}

// Replaces Autonomous()
void _Autonomous()
{
}

// Frame counter for debugging
long i=0;
long last_i=0;

// Replaces OperatorControl()
void _OperatorControl()
{
       int curr, prev=0;
       
       // My updates to sample
       PixyInit();
     
    while(1) // Insert your RC code below
    {
       curr = PixyGetStart();
       if (prev && curr) // two start codes means start of new frame
         //printf("%d", i++);
         i++;
       prev = curr;
    }
}

// Background process to read Pixy output
void PixyReaderTask()
{
}

// Outputs debug info to the easyC Terminal Window
void RefreshDebugOutput()
{
	long fps = i - last_i;
	last_i = i;
	PrintToScreen("Frames: %ld\n", fps);
}





