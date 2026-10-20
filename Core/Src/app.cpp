#include "app.h"
#include "main.h"
#include "math.h"

#define WAVE_BUFFER 100

uint16_t	dacWaveBuffer[WAVE_BUFFER];
uint16_t	adcBuffer = 0;
int i = 0;


void waveGenerate(void)
{
	for (i = 0; i < WAVE_BUFFER; i++) {
		dacWaveBuffer[i] = (uint16_t)(((sin(i * 2.0 * M_PI / WAVE_BUFFER)) + 1.0) * 2047.5);
	}
}

void App_Init(void)
{

	waveGenerate();


	HAL_TIM_Base_Start(&htim6);


	HAL_DAC_Start_DMA(&hdac1,
						DAC_CHANNEL_1,
						(uint32_t *)dacWaveBuffer,
						WAVE_BUFFER,
						DAC_ALIGN_12B_R);

	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)&adcBuffer, 1);


}

void App_Run(void)
{

}
