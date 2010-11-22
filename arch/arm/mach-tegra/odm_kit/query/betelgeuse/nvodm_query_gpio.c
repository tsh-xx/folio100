/*
 * Copyright (c) 2007-2009 NVIDIA Corporation.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of the NVIDIA Corporation nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
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

#include "nvodm_query_gpio.h"
#include "nvodm_services.h"
#include "nvrm_drf.h"
#include "nvodm_query_discovery.h"

#include "linux/input.h"

#define NVODM_ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define NVODM_PORT(x) ((x) - 'a')

#define EEPROM_ID_E1206      0x0C06

// static const NvOdmGpioPinInfo s_vi[] = {
//     {NVODM_PORT('t'), 3, NvOdmGpioPinActiveState_High}, // EN_VDDIO_SD
// };

static const NvOdmGpioPinInfo s_display[] = {

//     // TO DO: Verify these settings for harmony.
// 
//     /* Panel 0 -- sony vga */
//     { NVODM_PORT('m'), 3, NvOdmGpioPinActiveState_Low },
//     { NVODM_PORT('b'), 2, NvOdmGpioPinActiveState_Low },
//     { NVODM_PORT('n'), 4, NvOdmGpioPinActiveState_Low },
//     { NVODM_PORT('j'), 3, NvOdmGpioPinActiveState_Low },
//     { NVODM_PORT('j'), 4, NvOdmGpioPinActiveState_Low },
//     // this pin is not needed for ap15
//     {NVODM_GPIO_INVALID_PORT, NVODM_GPIO_INVALID_PIN,
//         NvOdmGpioPinActiveState_Low},
// 
//     /* Panel 1 -- samtek */
//     {NVODM_GPIO_INVALID_PORT, NVODM_GPIO_INVALID_PIN,
//         NvOdmGpioPinActiveState_Low},
//     {NVODM_GPIO_INVALID_PORT, NVODM_GPIO_INVALID_PIN,
//         NvOdmGpioPinActiveState_Low},
//     {NVODM_GPIO_INVALID_PORT, NVODM_GPIO_INVALID_PIN,
//         NvOdmGpioPinActiveState_Low},
//     {NVODM_GPIO_INVALID_PORT, NVODM_GPIO_INVALID_PIN,
//         NvOdmGpioPinActiveState_Low},
// 
//     /* Panel 2 -- sharp wvga */
//     { NVODM_PORT('v'), 7, NvOdmGpioPinActiveState_Low },
// 
//     /* Panel 3 -- sharp qvga */
//     { NVODM_PORT('n'), 6, NvOdmGpioPinActiveState_High },   // LCD_DC0
//     { NVODM_PORT('n'), 4, NvOdmGpioPinActiveState_Low },    // LCD_CS0
//     { NVODM_PORT('b'), 3, NvOdmGpioPinActiveState_Low },    // LCD_PCLK
//     { NVODM_PORT('b'), 2, NvOdmGpioPinActiveState_Low },    // LCD_PWR0
//     { NVODM_PORT('e'), 0, NvOdmGpioPinActiveState_High },   // LCD_D0
//     { NVODM_PORT('e'), 1, NvOdmGpioPinActiveState_High },   // LCD_D1
//     { NVODM_PORT('e'), 2, NvOdmGpioPinActiveState_High },   // LCD_D2
//     { NVODM_PORT('e'), 3, NvOdmGpioPinActiveState_High },   // LCD_D3
//     { NVODM_PORT('e'), 4, NvOdmGpioPinActiveState_High },   // LCD_D4
//     { NVODM_PORT('e'), 5, NvOdmGpioPinActiveState_High },   // LCD_D5
//     { NVODM_PORT('e'), 6, NvOdmGpioPinActiveState_High },   // LCD_D6
//     { NVODM_PORT('e'), 7, NvOdmGpioPinActiveState_High },   // LCD_D7
//     { NVODM_PORT('f'), 0, NvOdmGpioPinActiveState_High },   // LCD_D8
//     { NVODM_PORT('f'), 1, NvOdmGpioPinActiveState_High },   // LCD_D9
//     { NVODM_PORT('f'), 2, NvOdmGpioPinActiveState_High },   // LCD_D10
//     { NVODM_PORT('f'), 3, NvOdmGpioPinActiveState_High },   // LCD_D11
//     { NVODM_PORT('f'), 4, NvOdmGpioPinActiveState_High },   // LCD_D12
//     { NVODM_PORT('f'), 5, NvOdmGpioPinActiveState_High },   // LCD_D13
//     { NVODM_PORT('f'), 6, NvOdmGpioPinActiveState_High },   // LCD_D14
//     { NVODM_PORT('f'), 7, NvOdmGpioPinActiveState_High },   // LCD_D15
//     { NVODM_PORT('m'), 3, NvOdmGpioPinActiveState_High },   // LCD_D19
// 
//     /* Panel 4 -- auo */
//     { NVODM_PORT('v'), 7, NvOdmGpioPinActiveState_Low },

    /* Panel 5 -- firefly p1138 lvds interface */
    { NVODM_PORT('b'), 2, NvOdmGpioPinActiveState_High },   // Enable (LVDS_SHTDN_N) (LO:OFF, HI:ON)
    { NVODM_PORT('w'), 0, NvOdmGpioPinActiveState_High },   // EN_VDD_BL
    { NVODM_PORT('b'), 5, NvOdmGpioPinActiveState_High },   // LCD_BL_EN
    { NVODM_PORT('c'), 6, NvOdmGpioPinActiveState_High },   // EN_VDD_PNL
    { NVODM_PORT('b'), 4, NvOdmGpioPinActiveState_High },   // LCD_BL_PWM
};

static const NvOdmGpioPinInfo s_hdmi[] =
{
    /* hdmi hot-plug interrupt pin */
    { NVODM_PORT('n'), 7, NvOdmGpioPinActiveState_High },    // HDMI HPD
};

// static const NvOdmGpioPinInfo s_crt[] =
// {
//     /* crt hot-plug interrupt pin */
//     { NVODM_PORT('x'), 2, NvOdmGpioPinActiveState_Low }, // VGA_DET#
// };

static const NvOdmGpioPinInfo s_sdio[] = {
    {NVODM_PORT('i'), 5, NvOdmGpioPinActiveState_Low},    // Card Detect for SDIO instance 2
    /* High for WP and low for read/write */
    {NVODM_PORT('h'), 1, NvOdmGpioPinActiveState_High},    // Write Protect for SDIO instance 2 
};

// static const NvOdmGpioPinInfo s_sdio3[] = {
//     {NVODM_PORT('h'), 2, NvOdmGpioPinActiveState_Low},    // Card Detect for SDIO instance 3
//     /* High for WP and low for read/write */
// 
//     {NVODM_PORT('h'), 3, NvOdmGpioPinActiveState_High},    // Write Protect for SDIO instance 3
// };

// static const NvOdmGpioPinInfo s_NandFlash[] = {
//     {NVODM_PORT('c'), 7, NvOdmGpioPinActiveState_High}, // Raw NAND WP_N
// };

// static const NvOdmGpioPinInfo s_spi_ethernet[] = {
//     {NVODM_PORT('c'), 1, NvOdmGpioPinActiveState_Low}   // DBG_IRQ
// };

static const NvOdmGpioPinInfo s_Bluetooth[] = {
    {NVODM_PORT('u'), 0, NvOdmGpioPinActiveState_Low}   // BT_RST#
};

static const NvOdmGpioPinInfo s_Wlan[] = {
    {NVODM_PORT('k'), 5, NvOdmGpioPinActiveState_Low},  // WF_PWDN#
    {NVODM_PORT('k'), 6, NvOdmGpioPinActiveState_Low}   // WF_RST#
};

// static const NvOdmGpioPinInfo s_Power[] = {
//     // lid open/close, High = Lid Closed
//     {NVODM_PORT('u'), 5, NvOdmGpioPinActiveState_High},
//     // power button
//     {NVODM_PORT('v'), 2, NvOdmGpioPinActiveState_Low}
// };

static const NvOdmGpioPinInfo s_WakeFromKeyBoard[] = {
    {NVODM_PORT('a'), 0, NvOdmGpioPinActiveState_Low}   // EC Keyboard Wakeup
};

// // Gpio based keypad
// static const NvOdmGpioPinKeyInfo s_GpioPinKeyInfo[] = {
//     {KEY_MENU, 10, NV_TRUE},
//     {KEY_HOME, 10, NV_TRUE},
//     {KEY_BACK, 10, NV_TRUE},
//     {KEY_F3, 10, NV_TRUE},
//     {KEY_F4, 10, NV_TRUE},
//     {KEY_MENU, 10, NV_TRUE},
// };


// // Gpio based keypad
// static const NvOdmGpioPinInfo s_GpioKeyBoard[] = {
//     {NVODM_PORT('q'), 0, NvOdmGpioPinActiveState_Low, (void *)&s_GpioPinKeyInfo[0]},
//     {NVODM_PORT('q'), 1, NvOdmGpioPinActiveState_Low, (void *)&s_GpioPinKeyInfo[1]},
//     {NVODM_PORT('q'), 2, NvOdmGpioPinActiveState_Low, (void *)&s_GpioPinKeyInfo[2]},
//     {NVODM_PORT('q'), 3, NvOdmGpioPinActiveState_Low, (void *)&s_GpioPinKeyInfo[3]},
//     {NVODM_PORT('q'), 4, NvOdmGpioPinActiveState_Low, (void *)&s_GpioPinKeyInfo[4]},
//     {NVODM_PORT('v'), 2, NvOdmGpioPinActiveState_Low, (void *)&s_GpioPinKeyInfo[5]},
// };

static const NvOdmGpioPinInfo s_Battery[] = {
    // Low Battery
    {NVODM_PORT('w'), 3, NvOdmGpioPinActiveState_Low},
};

//GSensor
static const NvOdmGpioPinInfo s_Gsensor[] = {
                {NVODM_PORT('v'), 7, NvOdmGpioPinActiveState_High},
        };
/* Ecompass Daniel 20100805 */
static const NvOdmGpioPinInfo s_Ecompass[] = {
		{NVODM_PORT('v'), 1, NvOdmGpioPinActiveState_High},
	};

static const NvOdmGpioPinInfo s_Docking[] = { 
    //DOCK_IN_DET#
    {NVODM_PORT('v'), 2, NvOdmGpioPinActiveState_Low},
};

static const NvOdmGpioPinInfo s_CapSensor[] = {
    //CAP_INT
    {NVODM_PORT('u'), 1, NvOdmGpioPinActiveState_High},
};

const NvOdmGpioPinInfo *NvOdmQueryGpioPinMap(NvOdmGpioPinGroup Group,
    NvU32 Instance, NvU32 *pCount)
{
//    NvOdmBoardInfo BoardInfo;
    switch (Group)
    {
        case NvOdmGpioPinGroup_Display:
            *pCount = NVODM_ARRAY_SIZE(s_display);
            return s_display;

        case NvOdmGpioPinGroup_Hdmi:
            *pCount = NVODM_ARRAY_SIZE(s_hdmi);
            return s_hdmi;
// 
//         case NvOdmGpioPinGroup_Crt:
//             *pCount = NVODM_ARRAY_SIZE(s_crt);
//             return s_crt;
// 
        case NvOdmGpioPinGroup_Sdio:
            if (Instance == 1)
            {
                *pCount = NVODM_ARRAY_SIZE(s_sdio);
                return s_sdio;
            }
//             else if (Instance == 3)
//             {
//                 *pCount = NVODM_ARRAY_SIZE(s_sdio3);
//                 return s_sdio3;
//             }
            else
            {
                *pCount = 0;
                return NULL;
            }

//         case NvOdmGpioPinGroup_NandFlash:
//             *pCount = NVODM_ARRAY_SIZE(s_NandFlash);
//             return s_NandFlash;

        case NvOdmGpioPinGroup_Bluetooth:
            *pCount = NVODM_ARRAY_SIZE(s_Bluetooth);
            return s_Bluetooth;

        case NvOdmGpioPinGroup_Wlan:
            *pCount = NVODM_ARRAY_SIZE(s_Wlan);
            return s_Wlan;

//         case NvOdmGpioPinGroup_SpiEthernet:
//             if (NvOdmQueryDownloadTransport() ==
//                 NvOdmDownloadTransport_SpiEthernet)
//             {
//                 *pCount = NVODM_ARRAY_SIZE(s_spi_ethernet);
//                 return s_spi_ethernet;
//             }
//             else
//             {
//                 *pCount = 0;
//                 return NULL;
//             }
        
//         case NvOdmGpioPinGroup_Vi:
//             *pCount = NVODM_ARRAY_SIZE(s_vi);
//             return s_vi;

//         case NvOdmGpioPinGroup_Power:
//             *pCount = NVODM_ARRAY_SIZE(s_Power);
//             return s_Power;

        case NvOdmGpioPinGroup_EmbeddedController:
            *pCount = NVODM_ARRAY_SIZE(s_WakeFromKeyBoard);
            return s_WakeFromKeyBoard;

//         case NvOdmGpioPinGroup_keypadMisc:
//             if (NvOdmPeripheralGetBoardInfo(EEPROM_ID_E1206, &BoardInfo))
//             {
//                 *pCount = NVODM_ARRAY_SIZE(s_GpioKeyBoard);
//                 return s_GpioKeyBoard;
//             }
//             *pCount = 0;
//             return NULL;
// 
         case NvOdmGpioPinGroup_Battery:
             *pCount = NVODM_ARRAY_SIZE(s_Battery);
             return s_Battery;
        
        case NvOdmGpioPinGroup_Docking: 
            *pCount = NVODM_ARRAY_SIZE(s_Docking);
            return s_Docking;

        case NvOdmGpioPinGroup_CapSensor: 
            *pCount = NVODM_ARRAY_SIZE(s_CapSensor);
            return s_CapSensor;
       
       case NvOdmGpioPinGroup_Gsensor:
	        *pCount = NVODM_ARRAY_SIZE(s_Gsensor);
	        return s_Gsensor;

        /* Ecompass Daniel 20100805 */
        case NvOdmGpioPinGroup_Ecompass: 
            *pCount = NVODM_ARRAY_SIZE(s_Ecompass);
            return s_Ecompass;    

        default:
            *pCount = 0;
            return NULL;
    }
}
