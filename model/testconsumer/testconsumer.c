/* User code: This file will not be overwritten by TASTE. */

#include "testconsumer.h"
#include <stdio.h>


int count = 0;

void testconsumer_startup()
{
    printf("TestConsumer: starting consumer \n");
}

void testconsumer_PI_receiveFrame(const asn1SccBase_samples_frame_Frame *IN_frame)
{
    count++;
    printf("TestReceiver: received image %d of size %lldx%lld, 1st pixel is %hhd \n",
        count, IN_frame->size_val.width, IN_frame->size_val.height, IN_frame->image.arr[0]);
}

