#!/bin/sh

export FILES="
$AUTOPROJ_CURRENT_ROOT/install/types/base/base.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/base/taste-extended.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/base/taste-types.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/userdefs/datachunk/userdefs-base.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/userdefs/datachunk/userdefs-DataChunk.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/datachunk/DataChunk.asn "
echo "Updating DataView.aadl"
taste-update-data-view $FILES

