/* User code: This file will not be overwritten by TASTE. */

#include "imagesender.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>


asn1SccBase_samples_frame_Frame currentFrame;   // Current image being sent
asn1SccDataChunk chunk;                         // Current chunk
size_t currentOffset = 0;                       // Next image byte to be sent
uint32_t next = 0;                              // Next chunk index to be sent
bool sending = FALSE;                           // Flag: sending an image


void imagesender_startup()
{
}

void imagesender_PI_setFrameToSend(const asn1SccBase_samples_frame_Frame *IN_frame)
{
    // Discard if previous image not sent
    if (sending)
    {
        fprintf(stderr, "ImageSender: requested send before previous image was completed; image discarded.\n");
        return;
    }
    
    // Copy image and restart counters
    memcpy((void*)&currentFrame, (void*)IN_frame, sizeof(asn1SccBase_samples_frame_Frame));
    currentOffset = 0;
    next = 0;
    sending = TRUE;
}

void imagesender_PI_chunkTrigger()
{
    // If not sending, do nothing
    if (!sending)
    {
        return;
    }
    
    // Prepare chunk
    chunk.index = next;
    if (currentOffset + chunkBytes < sizeof(asn1SccBase_samples_frame_Frame))
    {
        chunk.chunkSize = chunkBytes;
    }
    else
    {
        // End of image
        chunk.chunkSize = sizeof(asn1SccBase_samples_frame_Frame) - currentOffset;
        sending = FALSE;
    }
    chunk.totalSize = sizeof(asn1SccBase_samples_frame_Frame);
    memcpy((void*)&chunk.data, (void*)&currentFrame + currentOffset, chunk.chunkSize);
    
    // Update counters
    next++;
    currentOffset += chunk.chunkSize;
    
    // Send chunk
    imagesender_RI_sendChunk(&chunk);
}

