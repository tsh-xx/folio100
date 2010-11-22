/*
 * Copyright (c) 2009 NVIDIA Corporation.
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
 
#ifndef MIC2826_REG_HEADER
#define MIC2826_REG_HEADER

#if defined(__cplusplus)
extern "C"
{
#endif

#define MIC2826_REG_INVALID              ~0x0
#define MIC2826_REG_ADDR_ENABLE          0x00
#define MIC2826_REG_ADDR_STATUS          0x01
#define MIC2826_REG_ADDR_BUCK            0x02
#define MIC2826_REG_ADDR_LD01            0x03
#define MIC2826_REG_ADDR_LD02            0x04
#define MIC2826_REG_ADDR_LD03            0x05

#define MIC2826_REG_ENABLE_BK            0x1
#define MIC2826_REG_ENABLE_LDO1          0x2
#define MIC2826_REG_ENABLE_LDO2          0x4
#define MIC2826_REG_ENABLE_LDO3          0x8
#define MIC2826_REG_ENABLE_SEQCNT       ~0x10
#define MIC2826_REG_ENABLE_POAF         ~0x20

#define MIC2826_REG_DISABLE_BK          ~0x1
#define MIC2826_REG_DISABLE_LDO1        ~0x2
#define MIC2826_REG_DISABLE_LDO2        ~0x4
#define MIC2826_REG_DISABLE_LDO3        ~0x8
#define MIC2826_REG_DISABLE_SEQCNT       0x10
#define MIC2826_REG_DISABLE_POAF         0x20

#define MIC2826_REG_STATUS_BK            0x1
#define MIC2826_REG_STATUS_LDO1          0x2
#define MIC2826_REG_STATUS_LDO2          0x4
#define MIC2826_REG_STATUS_LDO3          0x8
#define MIC2826_TSD_STATUS_TSD           0x10
#define MIC2826_REG_STATUS_UVLO          0x20
#define MIC2826_REG_STATUS_TSD_NORMAL   ~0x10
#define MIC2826_REG_STATUS_UVLO_NORMAL  ~0x20

#define MIC2826_REG_STATUS_INT_EN        0x40
#define MIC2826_REG_STATUS_INT_DIS      ~0x40

#define MIC2826_BUCK_OUT_VOLTAGE_0800    0x00  //0.800 V
#define MIC2826_BUCK_OUT_VOLTAGE_0825    0x01  //0.825 V
#define MIC2826_BUCK_OUT_VOLTAGE_0850    0x02  //0.850 V
#define MIC2826_BUCK_OUT_VOLTAGE_0875    0x03  //0.875 V
#define MIC2826_BUCK_OUT_VOLTAGE_0900    0x04  //0.900 V
#define MIC2826_BUCK_OUT_VOLTAGE_0925    0x05  //0.925 V
#define MIC2826_BUCK_OUT_VOLTAGE_0950    0x06  //0.950 V
#define MIC2826_BUCK_OUT_VOLTAGE_0975    0x07  //0.975 V
#define MIC2826_BUCK_OUT_VOLTAGE_1000    0x08  //1.000 V
#define MIC2826_BUCK_OUT_VOLTAGE_1025    0x09  //1.025 V
#define MIC2826_BUCK_OUT_VOLTAGE_1050    0x0A  //1.050 V
#define MIC2826_BUCK_OUT_VOLTAGE_1075    0x0B  //1.075 V
#define MIC2826_BUCK_OUT_VOLTAGE_1100    0x0C  //1.100 V
#define MIC2826_BUCK_OUT_VOLTAGE_1125    0x0D  //1.125 V
#define MIC2826_BUCK_OUT_VOLTAGE_1150    0x0E  //1.150 V
#define MIC2826_BUCK_OUT_VOLTAGE_1175    0x0F  //1.175 V
#define MIC2826_BUCK_OUT_VOLTAGE_1200    0x10  //1.200 V
#define MIC2826_BUCK_OUT_VOLTAGE_1250    0x11  //1.250 V
#define MIC2826_BUCK_OUT_VOLTAGE_1300    0x12  //1.300 V
#define MIC2826_BUCK_OUT_VOLTAGE_1350    0x13  //1.350 V
#define MIC2826_BUCK_OUT_VOLTAGE_1400    0x14  //1.400 V
#define MIC2826_BUCK_OUT_VOLTAGE_1450    0x15  //1.450 V
#define MIC2826_BUCK_OUT_VOLTAGE_1500    0x16  //1.500 V
#define MIC2826_BUCK_OUT_VOLTAGE_1550    0x17  //1.550 V
#define MIC2826_BUCK_OUT_VOLTAGE_1600    0x18  //1.600 V
#define MIC2826_BUCK_OUT_VOLTAGE_1650    0x19  //1.650 V
#define MIC2826_BUCK_OUT_VOLTAGE_1700    0x1A  //1.700 V
#define MIC2826_BUCK_OUT_VOLTAGE_1750    0x1B  //1.750 V
#define MIC2826_BUCK_OUT_VOLTAGE_1800    0x1C  //1.800 V

#define MIC2826_LDO_OUT_VOLTAGE_0800     0x00  //0.800 V
#define MIC2826_LDO_OUT_VOLTAGE_0850     0x0B  //0.850 V
#define MIC2826_LDO_OUT_VOLTAGE_0900     0x14  //0.900 V
#define MIC2826_LDO_OUT_VOLTAGE_0950     0x1D  //0.950 V
#define MIC2826_LDO_OUT_VOLTAGE_1000     0x25  //1.000 V
#define MIC2826_LDO_OUT_VOLTAGE_1050     0x2E  //1.050 V
#define MIC2826_LDO_OUT_VOLTAGE_1100     0x37  //1.100 V
#define MIC2826_LDO_OUT_VOLTAGE_1150     0x3E  //1.150 V
#define MIC2826_LDO_OUT_VOLTAGE_1200     0x45  //1.200 V
#define MIC2826_LDO_OUT_VOLTAGE_1250     0x4B  //1.250 V
#define MIC2826_LDO_OUT_VOLTAGE_1300     0x51  //1.300 V
#define MIC2826_LDO_OUT_VOLTAGE_1350     0x57  //1.350 V
#define MIC2826_LDO_OUT_VOLTAGE_1400     0x5C  //1.400 V
#define MIC2826_LDO_OUT_VOLTAGE_1450     0x60  //1.450 V
#define MIC2826_LDO_OUT_VOLTAGE_1500     0x65  //1.500 V
#define MIC2826_LDO_OUT_VOLTAGE_1550     0x69  //1.550 V
#define MIC2826_LDO_OUT_VOLTAGE_1600     0x6D  //1.600 V
#define MIC2826_LDO_OUT_VOLTAGE_1650     0x72  //1.650 V
#define MIC2826_LDO_OUT_VOLTAGE_1700     0x78  //1.700 V
#define MIC2826_LDO_OUT_VOLTAGE_1750     0x75  //1.750 V
#define MIC2826_LDO_OUT_VOLTAGE_1800     0x85  //1.800 V
#define MIC2826_LDO_OUT_VOLTAGE_1850     0x8B  //1.850 V
#define MIC2826_LDO_OUT_VOLTAGE_1900     0x90  //1.900 V
#define MIC2826_LDO_OUT_VOLTAGE_1950     0x95  //1.950 V
#define MIC2826_LDO_OUT_VOLTAGE_2000     0x9A  //2.000 V
#define MIC2826_LDO_OUT_VOLTAGE_2050     0x9F  //2.050 V
#define MIC2826_LDO_OUT_VOLTAGE_2100     0xA3  //2.100 V
#define MIC2826_LDO_OUT_VOLTAGE_2150     0xA7  //2.150 V
#define MIC2826_LDO_OUT_VOLTAGE_2200     0xAB  //2.200 V
#define MIC2826_LDO_OUT_VOLTAGE_2250     0xA0  //2.250 V
#define MIC2826_LDO_OUT_VOLTAGE_2300     0xB3  //2.300 V
#define MIC2826_LDO_OUT_VOLTAGE_2350     0xB7  //2.350 V
#define MIC2826_LDO_OUT_VOLTAGE_2400     0xBA  //2.400 V
#define MIC2826_LDO_OUT_VOLTAGE_2450     0xBD  //2.450 V
#define MIC2826_LDO_OUT_VOLTAGE_2500     0xC1  //2.500 V
#define MIC2826_LDO_OUT_VOLTAGE_2550     0xC3  //2.550 V
#define MIC2826_LDO_OUT_VOLTAGE_2600     0xC6  //2.600 V
#define MIC2826_LDO_OUT_VOLTAGE_2650     0xC9  //2.650 V
#define MIC2826_LDO_OUT_VOLTAGE_2700     0xCB  //2.700 V
#define MIC2826_LDO_OUT_VOLTAGE_2750     0xCE  //2.750 V
#define MIC2826_LDO_OUT_VOLTAGE_2800     0xD1  //2.800 V
#define MIC2826_LDO_OUT_VOLTAGE_2850     0xD3  //2.850 V
#define MIC2826_LDO_OUT_VOLTAGE_2900     0xD5  //2.900 V
#define MIC2826_LDO_OUT_VOLTAGE_2950     0xD8  //2.950 V
#define MIC2826_LDO_OUT_VOLTAGE_3000     0xDA  //3.000 V
#define MIC2826_LDO_OUT_VOLTAGE_3050     0xDC  //3.050 V
#define MIC2826_LDO_OUT_VOLTAGE_3100     0xDE  //3.100 V
#define MIC2826_LDO_OUT_VOLTAGE_3150     0xE0  //3.150 V
#define MIC2826_LDO_OUT_VOLTAGE_3200     0xE3  //3.200 V
#define MIC2826_LDO_OUT_VOLTAGE_3250     0xE6  //3.250 V
#define MIC2826_LDO_OUT_VOLTAGE_3300     0xE8  //3.300 V

#define MIC2826_BUCK_VOLTAGE_OFFSET      800
#define MIC2826_BUCK_VOLTAGE_MIN_MV      800
#define MIC2826_BUCK_VOLTAGE_STEP_MV     25
#define MIC2826_BUCK_VOLTAGE_STEP_25MV   25
#define MIC2826_BUCK_VOLTAGE_STEP_50MV   50
#define MIC2826_BUCK_VOLTAGE_MAX_MV      1800
#define MIC2826_BUCK_REQUESTVOLTAGE_MV   1800

#define MIC2826_LDO_VOLTAGE_OFFSET       800
#define MIC2826_LDO_VOLTAGE_MIN_MV       800
#define MIC2826_LDO_VOLTAGE_STEP_MV      50
#define MIC2826_LDO_VOLTAGE_MAX_MV       3300
#define MIC2826_LDO1_REQUESTVOLTAGE_MV   1800
#define MIC2826_LDO2_REQUESTVOLTAGE_MV   1800
#define MIC2826_LDO3_REQUESTVOLTAGE_MV   1200

#define MIC2826_INVALID_PORT             0xFF


#if defined(__cplusplus)
}
#endif


#endif
