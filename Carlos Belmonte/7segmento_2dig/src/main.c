/* Copyright 2016, Eric Pernia.
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Main example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Main example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * ENP          Eric Pernia
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 2016-04-26   v0.0.1   First version
 */

/*==================[inclusions]=============================================*/

#include "main.h"         /* <= own header */

#include "sAPI.h"         /* <= sAPI header */

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

#define segmentDP DIO32
#define segmentC DIO15
#define segmentD DIO31
#define segmentE DIO14
#define segmentB DIO30
#define segmentA DIO13
#define segmentF DIO29
#define segmentG DIO12
#define unidad DIO16
#define decena DIO17



/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */

 /* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
 
uint8_t uni=0;
uint8_t dec=0;
uint8_t flag=1;
uint8_t x=0;
 
 void enviarDigitos(uint8_t x){
	 uint8_t segmento[9];
	 segmento[0]= 0b01111110;// | 0x7E | 0
	 segmento[1]= 0b00010010;// | 0x12 | 1
	 segmento[2]= 0b10111100;// | 0xBC | 2
	 segmento[3]= 0b10110110;// | 0xB6 | 3
	 segmento[4]= 0b11010010;// | 0xD2 | 4
	 segmento[5]= 0b11100110;// | 0xE6 | 5
	 segmento[6]= 0b11101110;// | 0xEE | 6
	 segmento[7]= 0b00110010;// | 0x32 | 7
	 segmento[8]= 0b11111110;// | 0xFE | 8
	 segmento[9]= 0b11110110;// | 0xF6 | 9
	 

     digitalWrite( segmentDP, (segmento[x] & 0b00000001)); //GPIO0   
	 digitalWrite( segmentC, (segmento[x] & 0b00000010)); //GPIO1
	 digitalWrite( segmentD, (segmento[x] & 0b00000100)); //GPIO2
	 digitalWrite( segmentE, (segmento[x] & 0b00001000)); //GPIO3
	 digitalWrite( segmentB, (segmento[x] & 0b00010000)); //GPIO4
	 digitalWrite( segmentA, (segmento[x] & 0b00100000)); //GPIO5
	 digitalWrite( segmentF, (segmento[x] & 0b01000000)); //GPIO6
	 digitalWrite( segmentG, (segmento[x] & 0b10000000)); //GPIO7
 }
 
int main(void)
{
   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();

   /* Inicializar el conteo de Ticks con resolución de 1ms */
   tickConfig(1,0);

   /* Inicializar DigitalIO */
   digitalConfig( 0, ENABLE_DIGITAL_IO );
   
   	delay_t delayBase;
	delay_t delayCuenta;

   /* Configuración de pines de entrada para
	   Teclas de la CIAA-NXP */
   digitalConfig( TEC1, INPUT );
   digitalConfig( TEC2, INPUT );
   digitalConfig( TEC3, INPUT );
   digitalConfig( TEC4, INPUT );

   /* Configuración de pines de salida para
	   Leds de la CIAA-NXP */
   digitalConfig( segmentDP, OUTPUT ); //GPIO0 - segmento 'h'	   
   digitalConfig( segmentC, OUTPUT ); //GPIO1 - segmento 'c'
   digitalConfig( segmentD, OUTPUT ); //GPIO2 - segmento 'd'
   digitalConfig( segmentE, OUTPUT ); //GPIO3 - segmento 'e'
   digitalConfig( segmentB, OUTPUT ); //GPIO4 - segmento 'b'
   digitalConfig( segmentA, OUTPUT ); //GPIO5 - segmento 'a'
   digitalConfig( segmentF, OUTPUT ); //GPIO6 - segmento 'f'
   digitalConfig( segmentG, OUTPUT ); //GPIO7 - segmento 'g'
   digitalConfig( unidad, OUTPUT ); //unidad  
   digitalConfig( decena, OUTPUT ); //decena

   digitalWrite( segmentDP, 0 ); //GPIO0   
   digitalWrite( segmentC, 0 ); //GPIO1
   digitalWrite( segmentD, 0 ); //GPIO2
   digitalWrite( segmentE, 0 ); //GPIO3
   digitalWrite( segmentB, 0 ); //GPIO4
   digitalWrite( segmentA, 0 ); //GPIO5
   digitalWrite( segmentF, 0 ); //GPIO6
   digitalWrite( segmentG, 0 ); //GPIO7
   digitalWrite( unidad, 1 ); //unidad	
   digitalWrite( decena, 1 ); //unidad	
   
    delayConfig( &delayBase, 10 );
	delayConfig( &delayCuenta, 1000 );
   

   /* ------------- REPETIR POR SIEMPRE ------------- */
	while(1) {		
		if (delayRead(&delayBase))
	   {
		   if (flag)
		   {
			   flag=0;
			   enviarDigitos(uni);	
			   digitalWrite( unidad, 0 ); //unidad	
			   digitalWrite( decena, 1 ); //decena
		   }
		   else
		   {
			   flag=1;
			   enviarDigitos(dec);	
			   digitalWrite( unidad, 1); //unidad	
			   digitalWrite( decena, 0 ); //decena
		   }
	   }
				
	   if (delayRead(&delayCuenta))
	   {
			uni = uni+1;
			if(uni>9){
				uni = 0;
				dec = dec+1;}
				
			if (dec>9){dec=0;} 
	   }		
	}

	/* NO DEBE LLEGAR NUNCA AQUI, debido a que a este
	   programa no es llamado por ningun S.O. */
	return 0 ;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
