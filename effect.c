/*
 * File:        effect.c
 * Author:      Sam Faull
 * Description:
 */

#include "effect.h"
#include <stdbool.h>
#include <stdio.h>

effect_t fx[FX_COUNT];

void effects_init(void)
{       
    fx[0].Name = "Delay";
    fx[0].Parameter[0].Name = "Delay Time";
    fx[0].Parameter[0].Unit = "ms";
    fx[0].Parameter[0].Value = 1000;
    fx[0].Parameter[1].Name = "Feedback";
    fx[0].Parameter[1].Unit = "%";
    fx[0].Parameter[1].Value = 25;
    fx[0].Enabled = false;

    fx[1].Name = "Distortion";
    fx[1].Parameter[0].Name = "Symmetric";
    fx[1].Parameter[0].Unit = "";
    fx[1].Parameter[0].Value = 0;
    fx[1].Parameter[1].Name = "Gain";
    fx[1].Parameter[1].Unit = "%";
    fx[1].Parameter[1].Value = 50;
    fx[1].Enabled = false;
    
    fx[2].Name = "Tremolo";
    fx[2].Parameter[0].Name = "Frequency";
    fx[2].Parameter[0].Unit = "Hz";
    fx[2].Parameter[0].Value = 4;
    fx[2].Enabled = false;
    
    fx[3].Name = "Chorus";
    fx[3].Parameter[0].Name = "Frequency";
    fx[3].Parameter[0].Unit = "Hz";
    fx[3].Parameter[0].Value = 2;
    fx[3].Enabled = false;
     
}

effect_t *effect_get_by_index(int i)
{
   effect_t *my = malloc(sizeof(effect_t));
   //*my = fx[i];
   return my;
}