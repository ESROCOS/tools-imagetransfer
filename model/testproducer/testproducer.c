/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

/* User code: This file will not be overwritten by TASTE. */

#include "testproducer.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

asn1SccBase_samples_frame_Frame frame;
int count = 0;

void testproducer_startup()
{
    printf("TestProducer: initialize frame\n");
    
    // Initialize frame
    frame.time.microseconds = 0;
    frame.received_time.microseconds = 0;
    frame.attributes.nCount = 0;
    frame.size_val.height = 480;
    frame.size_val.width = 640;
    frame.data_depth = 8;
    frame.pixel_size = 1;
    frame.row_size = frame.size_val.width * frame.pixel_size;
    frame.frame_mode = asn1Sccbase_samples_frame_frame_mode_t_mode_grayscale;
    frame.frame_status = asn1Sccbase_samples_frame_frame_status_t_status_valid;
    
    frame.image.nCount = frame.size_val.height * frame.size_val.width * frame.pixel_size;
    
    // Check size just in case (multiply x8 to account for integer withd in TASTE)
    if ((size_t)frame.image.nCount * 8 > sizeof(frame.image.arr))
    {
        printf("[ERROR] TestProducer: image size in userdefs-base.asn doesn't match test image size. Exiting...\n");
        exit(1);
    }
    
    memset(frame.image.arr, 63, frame.image.nCount);

    printf("TestProducer: initialized image of size %lldx%lld, 1st pixel is %hhd\n",
        frame.size_val.width, frame.size_val.height, frame.image.arr[0]);

    printf("TestProducer: starting producer \n");
}


void testproducer_PI_trigger()
{
    printf("TestProducer: sending image %d \n", ++count);
    testproducer_RI_sendFrame(&frame);
}

