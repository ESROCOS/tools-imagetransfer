/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_imagereceiver__
#define __USER_CODE_H_imagereceiver__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void imagereceiver_startup();

void imagereceiver_PI_receiveChunk(const asn1SccDataChunk *);

extern void imagereceiver_RI_setReceivedFrame(const asn1SccBase_samples_frame_Frame *);

#ifdef __cplusplus
}
#endif


#endif
