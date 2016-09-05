
/* File generated by gen_cfile.py. Should not be modified. */

#include "ObjDict.h"
#include "dcf.h"
/**************************************************************************/
/* Declaration of mapped variables                                        */
/**************************************************************************/
UNS16 MOTOR_STATUS[] =		/* Mapped at index 0x2000, subindex 0x01 - 0x04 */
  {
    0x0,	/* 0 */
    0x0,	/* 0 */
    0x0,	/* 0 */
    0x0	    /* 0 */
  };
INTEGER32 MOTOR_POSTION[] =		/* Mapped at index 0x2001, subindex 0x01 - 0x04 */
  {
    0x0,	/* 0 */
    0x0,	/* 0 */
    0x0,	/* 0 */
    0x0	/* 0 */
  };
UNS8 A20_IN_Status;
UNS8 A20_Run_Status;

UNS8 A20_OUT_Status;//输出状态获取
/**************************************************************************/
/* Declaration of value range types                                       */
/**************************************************************************/

#define valueRange_EMC 0x9F /* Type for index 0x1003 subindex 0x00 (only set of value 0 is possible) */
UNS32 ObjDict_valueRangeTest (UNS8 typeValue, void * value)
{
  switch (typeValue) {
    case valueRange_EMC:
      if (*(UNS8*)value != (UNS8)0) return OD_VALUE_RANGE_EXCEEDED;
      break;
  }
  return 0;
}

/**************************************************************************/
/* The node id                                                            */
/**************************************************************************/
/* node_id default value.*/
UNS8 ObjDict_bDeviceNodeId = 0x00;

/**************************************************************************/
/* Array of message processing information */

const UNS8 ObjDict_iam_a_slave = 0;

TIMER_HANDLE ObjDict_heartBeatTimers[1] = {TIMER_NONE};

/*
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

                               OBJECT DICTIONARY

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/

/* index 0x1000 :   Device Type. */
                    UNS32 ObjDict_obj1000 = 0x402;	/* 1026 */
                    subindex ObjDict_Index1000[] =
                     {
                       { RO, uint32, sizeof (UNS32), (void*)&ObjDict_obj1000 }
                     };

/* index 0x1001 :   Error Register. */
                    UNS8 ObjDict_obj1001 = 0x0;	/* 0 */
                    subindex ObjDict_Index1001[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_obj1001 }
                     };

/* index 0x1003 :   Pre-defined Error Field. */
                    UNS8 ObjDict_highestSubIndex_obj1003 = 0; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1003[] =
                    {
                      0x0	/* 0 */
                    };
                    ODCallback_t ObjDict_Index1003_callbacks[] =
                     {
                       NULL,
                       NULL,
                     };
                    subindex ObjDict_Index1003[] =
                     {
                       { RW, valueRange_EMC, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1003 },
                       { RO, uint32, sizeof (UNS32), (void*)&ObjDict_obj1003[0] }
                     };

/* index 0x1005 :   SYNC COB ID. */
                    UNS32 ObjDict_obj1005 = 0x0;	/* 0 */
                    ODCallback_t ObjDict_Index1005_callbacks[] =
                     {
                       NULL,
                     };
                    subindex ObjDict_Index1005[] =
                     {
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1005 }
                     };

/* index 0x1006 :   Communication / Cycle Period. */
                    UNS32 ObjDict_obj1006 = 0x0;	/* 0 */
                    ODCallback_t ObjDict_Index1006_callbacks[] =
                     {
                       NULL,
                     };
                    subindex ObjDict_Index1006[] =
                     {
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1006 }
                     };

/* index 0x1007 :   Synchronous Window Length. */
                    UNS32 ObjDict_obj1007 = 0x0;	/* 0 */
                    subindex ObjDict_Index1007[] =
                     {
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1007 }
                     };

/* index 0x1008 :   Manufacturer Device Name. */
                    UNS8 ObjDict_obj1008[10] = "";
                    subindex ObjDict_Index1008[] =
                     {
                       { RO, visible_string, 10, (void*)&ObjDict_obj1008 }
                     };

/* index 0x1009 :   Manufacturer Hardware Version. */
                    UNS8 ObjDict_obj1009[10] = "";
                    subindex ObjDict_Index1009[] =
                     {
                       { RO, visible_string, 10, (void*)&ObjDict_obj1009 }
                     };

/* index 0x100A :   Manufacturer Software Version. */
                    UNS8 ObjDict_obj100A[10] = "";
                    subindex ObjDict_Index100A[] =
                     {
                       { RO, visible_string, 10, (void*)&ObjDict_obj100A }
                     };

/* index 0x100C :   Guard Time */
                    UNS16 ObjDict_obj100C = 0x0;   /* 0 */

/* index 0x100D :   Life Time Factor */
                    UNS8 ObjDict_obj100D = 0x0;   /* 0 */

/* index 0x1014 :   Emergency COB ID. */
                    UNS32 ObjDict_obj1014 = 0x80;	/* 128 */
                    subindex ObjDict_Index1014[] =
                     {
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1014 }
                     };

/* index 0x1016 :   Consumer Heartbeat Time. */
                    UNS8 ObjDict_highestSubIndex_obj1016 = 4; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1016[] =
                    {
                      0x014000,
                      0x024000,	/* 0 */
                      0x034000,
                      0x044000,
                    };
                    subindex ObjDict_Index1016[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1016 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1016[0] },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1016[1] },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1016[2] },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1016[3] }
                     };

/* index 0x1017 :   Producer Heartbeat Time. */
                    UNS16 ObjDict_obj1017 = 0x0;	/* 0 */
                    ODCallback_t ObjDict_Index1017_callbacks[] =
                     {
                       NULL,
                     };
                    subindex ObjDict_Index1017[] =
                     {
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1017 }
                     };

/* index 0x1018 :   Identity. */
                    UNS8 ObjDict_highestSubIndex_obj1018 = 4; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1018_Vendor_ID = 0x0;	/* 0 */
                    UNS32 ObjDict_obj1018_Product_Code = 0x0;	/* 0 */
                    UNS32 ObjDict_obj1018_Revision_Number = 0x0;	/* 0 */
                    UNS32 ObjDict_obj1018_Serial_Number = 0x0;	/* 0 */
                    subindex ObjDict_Index1018[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1018 },
                       { RO, uint32, sizeof (UNS32), (void*)&ObjDict_obj1018_Vendor_ID },
                       { RO, uint32, sizeof (UNS32), (void*)&ObjDict_obj1018_Product_Code },
                       { RO, uint32, sizeof (UNS32), (void*)&ObjDict_obj1018_Revision_Number },
                       { RO, uint32, sizeof (UNS32), (void*)&ObjDict_obj1018_Serial_Number }
                     };

/* index 0x1280 :   Client SDO 1 Parameter. */
                    UNS8 ObjDict_highestSubIndex_obj1280 = 3; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1280_COB_ID_Client_to_Server_Transmit_SDO = 0x601;	/* 1537 */
                    UNS32 ObjDict_obj1280_COB_ID_Server_to_Client_Receive_SDO = 0x581;	/* 1409 */
                    UNS8 ObjDict_obj1280_Node_ID_of_the_SDO_Server = 0x1;	/* 1 */
                    subindex ObjDict_Index1280[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1280 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1280_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1280_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1280_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1281 :   Client SDO 2 Parameter. */
                    UNS8 ObjDict_highestSubIndex_obj1281 = 3; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1281_COB_ID_Client_to_Server_Transmit_SDO = 0x602;	/* 1538 */
                    UNS32 ObjDict_obj1281_COB_ID_Server_to_Client_Receive_SDO = 0x582;	/* 1410 */
                    UNS8 ObjDict_obj1281_Node_ID_of_the_SDO_Server = 0x2;	/* 2 */
                    subindex ObjDict_Index1281[] =
                     {
                       { RO, uint8, sizeof (UNS8),  (void*)&ObjDict_highestSubIndex_obj1281 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1281_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1281_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1281_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1282 :   Client SDO 3 Parameter. */
                    UNS8 ObjDict_highestSubIndex_obj1282 = 3; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1282_COB_ID_Client_to_Server_Transmit_SDO = 0x603;	/* 1539 */
                    UNS32 ObjDict_obj1282_COB_ID_Server_to_Client_Receive_SDO = 0x583;	/* 1411 */
                    UNS8 ObjDict_obj1282_Node_ID_of_the_SDO_Server = 0x3;	/* 3 */
                    subindex ObjDict_Index1282[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1282 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1282_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1282_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1282_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1283 :   Client SDO 4 Parameter. */
                    UNS8 ObjDict_highestSubIndex_obj1283 = 3; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1283_COB_ID_Client_to_Server_Transmit_SDO = 0x604;	/* 1540 */
                    UNS32 ObjDict_obj1283_COB_ID_Server_to_Client_Receive_SDO = 0x584;	/* 1412 */
                    UNS8 ObjDict_obj1283_Node_ID_of_the_SDO_Server = 0x4;	/* 4 */
                    subindex ObjDict_Index1283[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1283 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1283_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1283_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1283_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1400 :   Receive PDO 1 Parameter. */
                    UNS8 ObjDict_highestSubIndex_obj1400 = 6; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1400_COB_ID_used_by_PDO = 0x181;	/* 385 */
                    UNS8 ObjDict_obj1400_Transmission_Type = 0xFF;	/* 255 */
                    UNS16 ObjDict_obj1400_Inhibit_Time = 0x64;	/* 100 */
                    UNS8 ObjDict_obj1400_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 ObjDict_obj1400_Event_Timer = 0xA;	/* 10 */
                    UNS8 ObjDict_obj1400_SYNC_start_value = 0x0;	/* 0 */
                    subindex ObjDict_Index1400[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1400 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1400_COB_ID_used_by_PDO },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1400_Transmission_Type },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1400_Inhibit_Time },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1400_Compatibility_Entry },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1400_Event_Timer },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1400_SYNC_start_value }
                     };

/* index 0x1401 :   Receive PDO 2 Parameter. */
                    UNS8 ObjDict_highestSubIndex_obj1401 = 6; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1401_COB_ID_used_by_PDO = 0x182;	/* 386 */
                    UNS8 ObjDict_obj1401_Transmission_Type = 0xFF;	/* 255 */
                    UNS16 ObjDict_obj1401_Inhibit_Time = 0x64;	/* 100 */
                    UNS8 ObjDict_obj1401_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 ObjDict_obj1401_Event_Timer = 0xA;	/* 10 */
                    UNS8 ObjDict_obj1401_SYNC_start_value = 0x0;	/* 0 */
                    subindex ObjDict_Index1401[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1401 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1401_COB_ID_used_by_PDO },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1401_Transmission_Type },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1401_Inhibit_Time },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1401_Compatibility_Entry },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1401_Event_Timer },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1401_SYNC_start_value }
                     };

/* index 0x1402 :   Receive PDO 3 Parameter. */
                    UNS8 ObjDict_highestSubIndex_obj1402 = 6; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1402_COB_ID_used_by_PDO = 0x183;	/* 387 */
                    UNS8 ObjDict_obj1402_Transmission_Type = 0xFF;	/* 255 */
                    UNS16 ObjDict_obj1402_Inhibit_Time = 0x64;	/* 100 */
                    UNS8 ObjDict_obj1402_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 ObjDict_obj1402_Event_Timer = 0xA;	/* 10 */
                    UNS8 ObjDict_obj1402_SYNC_start_value = 0x0;	/* 0 */
                    subindex ObjDict_Index1402[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1402 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1402_COB_ID_used_by_PDO },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1402_Transmission_Type },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1402_Inhibit_Time },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1402_Compatibility_Entry },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1402_Event_Timer },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1402_SYNC_start_value }
                     };

/* index 0x1403 :   Receive PDO 4 Parameter. */
                    UNS8 ObjDict_highestSubIndex_obj1403 = 6; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1403_COB_ID_used_by_PDO = 0x184;	/* 388 */
                    UNS8 ObjDict_obj1403_Transmission_Type = 0xFF;	/* 255 */
                    UNS16 ObjDict_obj1403_Inhibit_Time = 0x64;	/* 100 */
                    UNS8 ObjDict_obj1403_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 ObjDict_obj1403_Event_Timer = 0xA;	/* 10 */
                    UNS8 ObjDict_obj1403_SYNC_start_value = 0x0;	/* 0 */
                    subindex ObjDict_Index1403[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1403 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1403_COB_ID_used_by_PDO },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1403_Transmission_Type },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1403_Inhibit_Time },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1403_Compatibility_Entry },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1403_Event_Timer },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1403_SYNC_start_value }
                     };

/* index 0x1600 :   Receive PDO 1 Mapping. */
                    UNS8 ObjDict_highestSubIndex_obj1600 = 2; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1600[] =
                    {
                      0x20000110,	/* 536871176 */
                      0x20010120	/* 536936736 */

                    };
                    subindex ObjDict_Index1600[] =
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1600 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1600[0] },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1600[1] }
                     };

/* index 0x1601 :   Receive PDO 2 Mapping. */
                    UNS8 ObjDict_highestSubIndex_obj1601 = 2; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1601[] =
                    {
                      0x20000210,	/* 536871440 */
                      0x20010220	/* 536936968 */
                    };
                    subindex ObjDict_Index1601[] =
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1601 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1601[0] },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1601[1] }
                     };

/* index 0x1602 :   Receive PDO 3 Mapping. */
                    UNS8 ObjDict_highestSubIndex_obj1602 = 2; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1602[] =
                    {
                      0x20000310,	/* 536871696 */
                      0x20010320	/* 536937248 */
                    };
                    subindex ObjDict_Index1602[] =
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1602 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1602[0] },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1602[1] }
                     };

/* index 0x1603 :   Receive PDO 4 Mapping. */
                    UNS8 ObjDict_highestSubIndex_obj1603 = 2; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1603[] =
                    {
                      0x20020108,	/* 536871952 */
                      0x20020208,	/* 536937504 */
                      0x20020308
                    };
                    subindex ObjDict_Index1603[] =
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1603 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1603[0] },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1603[1] },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1603[2] }
                     };

/* index 0x1800 :   Transmit PDO 1 Parameter. */
                    UNS8 ObjDict_highestSubIndex_obj1800 = 6; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1800_COB_ID_used_by_PDO = 0x180;	/* 384 */
                    UNS8 ObjDict_obj1800_Transmission_Type = 0x1;	/* 0 */
                    UNS16 ObjDict_obj1800_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 ObjDict_obj1800_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 ObjDict_obj1800_Event_Timer = 0x0;	/* 0 */
                    UNS8 ObjDict_obj1800_SYNC_start_value = 0x0;	/* 0 */
                    ODCallback_t ObjDict_Index1800_callbacks[] =
                     {
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                     };
                    subindex ObjDict_Index1800[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1800 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1800_COB_ID_used_by_PDO },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1800_Transmission_Type },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1800_Inhibit_Time },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1800_Compatibility_Entry },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1800_Event_Timer },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1800_SYNC_start_value }
                     };

/* index 0x1801 :   Transmit PDO 2 Parameter. */
                    UNS8 ObjDict_highestSubIndex_obj1801 = 6; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1801_COB_ID_used_by_PDO = 0x280;	/* 640 */
                    UNS8 ObjDict_obj1801_Transmission_Type = 0x0;	/* 0 */
                    UNS16 ObjDict_obj1801_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 ObjDict_obj1801_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 ObjDict_obj1801_Event_Timer = 0x0;	/* 0 */
                    UNS8 ObjDict_obj1801_SYNC_start_value = 0x0;	/* 0 */
                    ODCallback_t ObjDict_Index1801_callbacks[] =
                     {
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                     };
                    subindex ObjDict_Index1801[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1801 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1801_COB_ID_used_by_PDO },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1801_Transmission_Type },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1801_Inhibit_Time },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1801_Compatibility_Entry },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1801_Event_Timer },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1801_SYNC_start_value }
                     };

/* index 0x1802 :   Transmit PDO 3 Parameter. */
                    UNS8 ObjDict_highestSubIndex_obj1802 = 6; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1802_COB_ID_used_by_PDO = 0x380;	/* 896 */
                    UNS8 ObjDict_obj1802_Transmission_Type = 0x0;	/* 0 */
                    UNS16 ObjDict_obj1802_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 ObjDict_obj1802_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 ObjDict_obj1802_Event_Timer = 0x0;	/* 0 */
                    UNS8 ObjDict_obj1802_SYNC_start_value = 0x0;	/* 0 */
                    ODCallback_t ObjDict_Index1802_callbacks[] =
                     {
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                     };
                    subindex ObjDict_Index1802[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1802 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1802_COB_ID_used_by_PDO },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1802_Transmission_Type },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1802_Inhibit_Time },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1802_Compatibility_Entry },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1802_Event_Timer },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1802_SYNC_start_value }
                     };

/* index 0x1803 :   Transmit PDO 4 Parameter. */
                    UNS8 ObjDict_highestSubIndex_obj1803 = 6; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1803_COB_ID_used_by_PDO = 0x480;	/* 1152 */
                    UNS8 ObjDict_obj1803_Transmission_Type = 0x0;	/* 0 */
                    UNS16 ObjDict_obj1803_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 ObjDict_obj1803_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 ObjDict_obj1803_Event_Timer = 0x0;	/* 0 */
                    UNS8 ObjDict_obj1803_SYNC_start_value = 0x0;	/* 0 */
                    ODCallback_t ObjDict_Index1803_callbacks[] =
                     {
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                       NULL,
                     };
                    subindex ObjDict_Index1803[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1803 },
                       { RW, uint32, sizeof (UNS32), (void*)&ObjDict_obj1803_COB_ID_used_by_PDO },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1803_Transmission_Type },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1803_Inhibit_Time },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1803_Compatibility_Entry },
                       { RW, uint16, sizeof (UNS16), (void*)&ObjDict_obj1803_Event_Timer },
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_obj1803_SYNC_start_value }
                     };

/* index 0x1A00 :   Transmit PDO 1 Mapping. */
                    UNS8 ObjDict_highestSubIndex_obj1A00 = 0; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1A00[] =
                    {
                    };
                    subindex ObjDict_Index1A00[] =
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1A00 }
                     };

/* index 0x1A01 :   Transmit PDO 2 Mapping. */
                    UNS8 ObjDict_highestSubIndex_obj1A01 = 0; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1A01[] =
                    {
                    };
                    subindex ObjDict_Index1A01[] =
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1A01 }
                     };

/* index 0x1A02 :   Transmit PDO 3 Mapping. */
                    UNS8 ObjDict_highestSubIndex_obj1A02 = 0; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1A02[] =
                    {
                    };
                    subindex ObjDict_Index1A02[] =
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1A02 }
                     };

/* index 0x1A03 :   Transmit PDO 4 Mapping. */
                    UNS8 ObjDict_highestSubIndex_obj1A03 = 0; /* number of subindex - 1*/
                    UNS32 ObjDict_obj1A03[] =
                    {
                    };
                    subindex ObjDict_Index1A03[] =
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1A03 }
                     };

/* index 0x2000 :   Mapped variable MOTOR_STATUS */
                    UNS8 ObjDict_highestSubIndex_obj2000 = 4; /* number of subindex - 1*/
                    subindex ObjDict_Index2000[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj2000 },
                       { RW, uint16, sizeof (UNS16), (void*)&MOTOR_STATUS[0] },
                       { RW, uint16, sizeof (UNS16), (void*)&MOTOR_STATUS[1] },
                       { RW, uint16, sizeof (UNS16), (void*)&MOTOR_STATUS[2] },

                     };

/* index 0x2001 :   Mapped variable MOTOR_POSTION */
                    UNS8 ObjDict_highestSubIndex_obj2001 = 4; /* number of subindex - 1*/
                    subindex ObjDict_Index2001[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj2001 },
                       { RW, int32, sizeof (INTEGER32), (void*)&MOTOR_POSTION[0] },
                       { RW, int32, sizeof (INTEGER32), (void*)&MOTOR_POSTION[1] },
                       { RW, int32, sizeof (INTEGER32), (void*)&MOTOR_POSTION[2] },

                     };
/* index 0x2002 :   Mapped variable A20 */
                    UNS8 ObjDict_highestSubIndex_obj2002 = 4; /* number of subindex - 1*/
                    subindex ObjDict_Index2002[] =
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj2002 },
                       { RW, uint8, sizeof (UNS8), (void*)&A20_IN_Status},
                       { RW, uint8, sizeof (UNS8),      (void*)&A20_Run_Status },
                       { RW, uint8, sizeof (UNS8),      (void*)&A20_OUT_Status }
                     };
////dcf
                    UNS8  motor_1 [20] = {0x02,0x00,0x00,0x00,
                                          0x40,0x60,0x00,0x02,0x00,0x00,0x00,0x06,0x00,
                                          0x40,0x60,0x00,0x02,0x0f,0x00,0x00,0x0f,0x00};
                  //  UNS32  motor_2 [4] =  { 4,0x6061,0x00, 2,0x00,0x00};
                    UNS8 ObjDict_highestSubIndex_obj2100 = 2; /* number of subindex - 1*/
                    UNS32 *NOID_1= motor_1;
                 //   UNS32 *NOID_2= motor_2;
                     subindex ObjDict_Index2100[] =
                     {
                       { RO, uint8,  sizeof (UNS8), (void*)&ObjDict_highestSubIndex_obj1802 },
                       { RW, uint32, sizeof (UNS8)*20, (void*)&NOID_1 },
                    //   { RW, uint32, sizeof (UNS32)*4, (void*)&NOID_2 },
                     };

/**************************************************************************/
/* Declaration of pointed variables                                       */
/**************************************************************************/

const indextable ObjDict_objdict[] =
{
  { (subindex*)ObjDict_Index1000,sizeof(ObjDict_Index1000)/sizeof(ObjDict_Index1000[0]), 0x1000},
  { (subindex*)ObjDict_Index1001,sizeof(ObjDict_Index1001)/sizeof(ObjDict_Index1001[0]), 0x1001},
  { (subindex*)ObjDict_Index1003,sizeof(ObjDict_Index1003)/sizeof(ObjDict_Index1003[0]), 0x1003},
  { (subindex*)ObjDict_Index1005,sizeof(ObjDict_Index1005)/sizeof(ObjDict_Index1005[0]), 0x1005},
  { (subindex*)ObjDict_Index1006,sizeof(ObjDict_Index1006)/sizeof(ObjDict_Index1006[0]), 0x1006},
  { (subindex*)ObjDict_Index1007,sizeof(ObjDict_Index1007)/sizeof(ObjDict_Index1007[0]), 0x1007},
  { (subindex*)ObjDict_Index1008,sizeof(ObjDict_Index1008)/sizeof(ObjDict_Index1008[0]), 0x1008},
  { (subindex*)ObjDict_Index1009,sizeof(ObjDict_Index1009)/sizeof(ObjDict_Index1009[0]), 0x1009},
  { (subindex*)ObjDict_Index100A,sizeof(ObjDict_Index100A)/sizeof(ObjDict_Index100A[0]), 0x100A},
  { (subindex*)ObjDict_Index1014,sizeof(ObjDict_Index1014)/sizeof(ObjDict_Index1014[0]), 0x1014},
  { (subindex*)ObjDict_Index1016,sizeof(ObjDict_Index1016)/sizeof(ObjDict_Index1016[0]), 0x1016},
  { (subindex*)ObjDict_Index1017,sizeof(ObjDict_Index1017)/sizeof(ObjDict_Index1017[0]), 0x1017},
  { (subindex*)ObjDict_Index1018,sizeof(ObjDict_Index1018)/sizeof(ObjDict_Index1018[0]), 0x1018},
  { (subindex*)ObjDict_Index1280,sizeof(ObjDict_Index1280)/sizeof(ObjDict_Index1280[0]), 0x1280},
  { (subindex*)ObjDict_Index1281,sizeof(ObjDict_Index1281)/sizeof(ObjDict_Index1281[0]), 0x1281},
  { (subindex*)ObjDict_Index1282,sizeof(ObjDict_Index1282)/sizeof(ObjDict_Index1282[0]), 0x1282},
  { (subindex*)ObjDict_Index1283,sizeof(ObjDict_Index1283)/sizeof(ObjDict_Index1283[0]), 0x1283},
  { (subindex*)ObjDict_Index1400,sizeof(ObjDict_Index1400)/sizeof(ObjDict_Index1400[0]), 0x1400},
  { (subindex*)ObjDict_Index1401,sizeof(ObjDict_Index1401)/sizeof(ObjDict_Index1401[0]), 0x1401},
  { (subindex*)ObjDict_Index1402,sizeof(ObjDict_Index1402)/sizeof(ObjDict_Index1402[0]), 0x1402},
  { (subindex*)ObjDict_Index1403,sizeof(ObjDict_Index1403)/sizeof(ObjDict_Index1403[0]), 0x1403},
  { (subindex*)ObjDict_Index1600,sizeof(ObjDict_Index1600)/sizeof(ObjDict_Index1600[0]), 0x1600},
  { (subindex*)ObjDict_Index1601,sizeof(ObjDict_Index1601)/sizeof(ObjDict_Index1601[0]), 0x1601},
  { (subindex*)ObjDict_Index1602,sizeof(ObjDict_Index1602)/sizeof(ObjDict_Index1602[0]), 0x1602},
  { (subindex*)ObjDict_Index1603,sizeof(ObjDict_Index1603)/sizeof(ObjDict_Index1603[0]), 0x1603},
  { (subindex*)ObjDict_Index1800,sizeof(ObjDict_Index1800)/sizeof(ObjDict_Index1800[0]), 0x1800},
  { (subindex*)ObjDict_Index1801,sizeof(ObjDict_Index1801)/sizeof(ObjDict_Index1801[0]), 0x1801},
  { (subindex*)ObjDict_Index1802,sizeof(ObjDict_Index1802)/sizeof(ObjDict_Index1802[0]), 0x1802},
  { (subindex*)ObjDict_Index1803,sizeof(ObjDict_Index1803)/sizeof(ObjDict_Index1803[0]), 0x1803},
  { (subindex*)ObjDict_Index1A00,sizeof(ObjDict_Index1A00)/sizeof(ObjDict_Index1A00[0]), 0x1A00},
  { (subindex*)ObjDict_Index1A01,sizeof(ObjDict_Index1A01)/sizeof(ObjDict_Index1A01[0]), 0x1A01},
  { (subindex*)ObjDict_Index1A02,sizeof(ObjDict_Index1A02)/sizeof(ObjDict_Index1A02[0]), 0x1A02},
  { (subindex*)ObjDict_Index1A03,sizeof(ObjDict_Index1A03)/sizeof(ObjDict_Index1A03[0]), 0x1A03},
  { (subindex*)ObjDict_Index2000,sizeof(ObjDict_Index2000)/sizeof(ObjDict_Index2000[0]), 0x2000},
  { (subindex*)ObjDict_Index2001,sizeof(ObjDict_Index2001)/sizeof(ObjDict_Index2001[0]), 0x2001},
 { (subindex*)ObjDict_Index2002,sizeof(ObjDict_Index2002)/sizeof(ObjDict_Index2002[0]), 0x2002},
    { (subindex*)ObjDict_Index2100,sizeof(ObjDict_Index2100)/sizeof(ObjDict_Index2100[0]), 0x2100},
};

const indextable * ObjDict_scanIndexOD (UNS16 wIndex, UNS32 * errorCode, ODCallback_t **callbacks)
{
    int i;
    *callbacks = NULL;
    switch(wIndex){
        case 0x1000: i = 0;break;
        case 0x1001: i = 1;break;
        case 0x1003: i = 2;*callbacks = ObjDict_Index1003_callbacks; break;
        case 0x1005: i = 3;*callbacks = ObjDict_Index1005_callbacks; break;
        case 0x1006: i = 4;*callbacks = ObjDict_Index1006_callbacks; break;
        case 0x1007: i = 5;break;
        case 0x1008: i = 6;break;
        case 0x1009: i = 7;break;
        case 0x100A: i = 8;break;
        case 0x1014: i = 9;break;
        case 0x1016: i = 10;break;
        case 0x1017: i = 11;*callbacks = ObjDict_Index1017_callbacks; break;
        case 0x1018: i = 12;break;
        case 0x1280: i = 13;break;
        case 0x1281: i = 14;break;
        case 0x1282: i = 15;break;
        case 0x1283: i = 16;break;
        case 0x1400: i = 17;break;
        case 0x1401: i = 18;break;
        case 0x1402: i = 19;break;
        case 0x1403: i = 20;break;
        case 0x1600: i = 21;break;
        case 0x1601: i = 22;break;
        case 0x1602: i = 23;break;
        case 0x1603: i = 24;break;
        case 0x1800: i = 25;*callbacks = ObjDict_Index1800_callbacks; break;
        case 0x1801: i = 26;*callbacks = ObjDict_Index1801_callbacks; break;
        case 0x1802: i = 27;*callbacks = ObjDict_Index1802_callbacks; break;
        case 0x1803: i = 28;*callbacks = ObjDict_Index1803_callbacks; break;
        case 0x1A00: i = 29;break;
        case 0x1A01: i = 30;break;
        case 0x1A02: i = 31;break;
        case 0x1A03: i = 32;break;
        case 0x2000: i = 33;break;
        case 0x2001: i = 34;break;
  case 0x2002: i = 35;break;
        case 0x2100: i = 36;break;

        default:
            *errorCode = OD_NO_SUCH_OBJECT;
            return NULL;
    }
    *errorCode = OD_SUCCESSFUL;
    return &ObjDict_objdict[i];
}

/*
 * To count at which received SYNC a PDO must be sent.
 * Even if no pdoTransmit are defined, at least one entry is computed
 * for compilations issues.
 */
s_PDO_status ObjDict_PDO_status[4] = {s_PDO_status_Initializer,s_PDO_status_Initializer,s_PDO_status_Initializer,s_PDO_status_Initializer};

const quick_index ObjDict_firstIndex = {
  0, /* SDO_SVR */
  13, /* SDO_CLT */
  17, /* PDO_RCV */
  21, /* PDO_RCV_MAP */
  25, /* PDO_TRS */
  29 /* PDO_TRS_MAP */
};

const quick_index ObjDict_lastIndex = {
  0, /* SDO_SVR */
  16, /* SDO_CLT */
  20, /* PDO_RCV */
  24, /* PDO_RCV_MAP */
  28, /* PDO_TRS */
  32 /* PDO_TRS_MAP */
};

const UNS16 ObjDict_ObjdictSize = sizeof(ObjDict_objdict)/sizeof(ObjDict_objdict[0]);

CO_Data ObjDict_Data = CANOPEN_NODE_DATA_INITIALIZER(ObjDict);

