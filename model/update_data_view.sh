export FILES="
$AUTOPROJ_CURRENT_ROOT/install/types/base/base.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/base/taste-extended.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/base/taste-types.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/userdefs/datachunk/userdefs-base.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/userdefs/datachunk/userdefs-DataChunk.asn \
$AUTOPROJ_CURRENT_ROOT/install/types/datachunk/DataChunk.asn "
echo "Updating DataView.aadl"
taste-update-data-view $FILES


#--! InputASN1FileChecksum:6bf664b31ce9ca6fd89af52cea7ea0f2:/home/esrocos/esrocos_workspace/tools/imagetransfer/model/DataView.asn:
