# H2020 ESROCOS Project
# Company: GMV Aerospace & Defence S.A.U.
# Licence: GPLv2

esrocos_build_taste(imagetransfer
    SOURCES
    imagereceiver
    imagesender
    testconsumer
    testproducer
    BINARIES
    binary.c/binaries/x86_partition
    DEPENDS
    imagetransfer_types
)
