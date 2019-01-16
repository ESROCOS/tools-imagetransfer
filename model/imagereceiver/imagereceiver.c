/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

/* User code: This file will not be overwritten by TASTE. */

#include "imagereceiver.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>


asn1SccBase_samples_frame_Frame currentFrame;   // Image being received
size_t currentOffset = 0;                       // Current offset in the image
uint32_t next = 0;                              // Next chunk to receive


void imagereceiver_startup()
{
}

void imagereceiver_PI_receiveChunk(const asn1SccDataChunk *IN_chunk)
{
    // Check chunk sequence
    if (IN_chunk->index != next)
    {
        if (0 == IN_chunk->index)
        {
            // Starting new image: reset counters
            currentOffset = 0;
            next = 0;
        }
        else
        {
            // Out of sequence: print error and discard
            fprintf(stderr, "ImageReceiver: received out-of-sequence image segment; discarded.\n");
            return;
        }
    }
    
    // Append chunk to image
    memcpy((void*)&currentFrame + currentOffset, (void*)&IN_chunk->data, IN_chunk->chunkSize);
    currentOffset += IN_chunk->chunkSize;
    next++;
    
    // Check if image completed
    if (currentOffset >= IN_chunk->totalSize)
    {
        // Reset counters
        currentOffset = 0;
        next = 0;
        
        // Output image
        imagereceiver_RI_setReceivedFrame(&currentFrame);
    }
}

