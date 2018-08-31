/*
 * File:        display.c
 * Author:      Sam Faull
 * Description: 
 */

#include "oled.h"
#include "display.h"
#include <stdio.h>
#include "state_process.h"

#define ARRAY_SIZE(x) ( sizeof(x) / sizeof((x)[0]) ) 
#define MAX_ITEMS 3

void display_drawMenu(menu_t *menu)
{
    printf("DISPLAY: %s \n", menu->Item[0]);

    int i;
    const uint8_t temp[3] = {15, 31, 47};
    
    oled_clear();
    oled_println(menu->Heading);
    for (i=0; i<MAX_ITEMS; i++)
    {
        char item = menu->Item[menu->FirstDisplayedItem + i];
        //char item[30];
        //strcpy(item, menu->Item[menu->FirstDisplayedItem + i]);
        printf("DISPLAYED: %s \n", *menu->Item[menu->FirstDisplayedItem + i]);
        oled_println(menu->Item[menu->FirstDisplayedItem + i]);
    }

    oled_draw_rect(0,temp[menu->SelectedPosition],126,16);
    oled_update();
}

void display_nextMenuPosition(menu_t *menu)
{
    if(menu->SelectedPosition < MAX_ITEMS-1 && menu->SelectedPosition < display_menuSize(menu)-2)
        menu->SelectedPosition++;
    else if ((menu->FirstDisplayedItem + MAX_ITEMS) > ARRAY_SIZE(menu->Item) || strlen(menu->Item[menu->FirstDisplayedItem + MAX_ITEMS]) > 0)
        menu->FirstDisplayedItem++;
    else
        return;
    
    display_drawMenu(menu);
}

void display_prevMenuPosition(menu_t *menu)
{
    if(menu->SelectedPosition > 0)
        menu->SelectedPosition--;
    else if (menu->FirstDisplayedItem > 0)
        menu->FirstDisplayedItem--;
    else
        return;
    
    display_drawMenu(menu);
}

int display_menuSize(menu_t *menu)
{
    int i;
    for(i=0; i<ARRAY_SIZE(menu->Item); i++)
    {
        if (menu->Item[i] == NULL)
            break;
    }
    return i+1;
}