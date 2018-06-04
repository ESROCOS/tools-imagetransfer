/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_imagesender__
#define __USER_CODE_H_imagesender__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void imagesender_startup();

void imagesender_PI_setFrameToSend(const asn1SccBase_samples_frame_Frame *);

void imagesender_PI_chunkTrigger();

extern void imagesender_RI_sendChunk(const asn1SccDataChunk *);

#ifdef __cplusplus
}
#endif


#endif
