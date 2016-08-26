#ifndef __CANOPENDICTCONFIG__
#define __CANOPENDICTCONFIG__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "canfestival.h"
#include "applicfg.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void CanopenInit(void);

UNS8 Get_HeartbetError(UNS8 heartbeatID);
UNS8 Clean_HeartbetError(UNS8 heartbeatID);
#ifdef __cplusplus
}
#endif

#endif /* __CANOPENOBJDICTCONFIG__ */

/******************* (C) COPYRIGHT 2015 Personal Electronics *****END OF FILE****/
