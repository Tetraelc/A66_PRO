
/* File generated by gen_cfile.py. Should not be modified. */

#ifndef OBJDICT_H
#define OBJDICT_H

#include "data.h"

/* Prototypes of function provided by object dictionnary */
UNS32 ObjDict_valueRangeTest (UNS8 typeValue, void * value);
const indextable * ObjDict_scanIndexOD (UNS16 wIndex, UNS32 * errorCode, ODCallback_t **callbacks);

/* Master node data struct */
extern CO_Data ObjDict_Data;
extern UNS16 MOTOR_STATUS[4];		/* Mapped at index 0x2000, subindex 0x01 - 0x04 */
extern INTEGER32 MOTOR_POSTION[4];		/* Mapped at index 0x2001, subindex 0x01 - 0x04 */
extern UNS8 A20_IN_Status;
extern UNS8 A20_Run_Status;
extern UNS8 A20_OUT_Status;

#endif // OBJDICT_H
