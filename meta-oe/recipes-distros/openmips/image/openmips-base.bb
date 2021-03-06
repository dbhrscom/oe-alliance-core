SUMMARY = "Base packages require for image."
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/LICENSE;md5=4d92cd373abda3937c2bc47fbc49d690 \
                    file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

ALLOW_EMPTY_${PN} = "1"

PV = "1.0"
PR = "r16"

inherit packagegroup

RDEPENDS_${PN} = "\
    oe-alliance-base \
    openmips-enigma2 \
    openmips-bootlogo \
    openmips-spinner \
    hddtemp \
    dosfstools \
    ntfs-3g \
    ntfsprogs \
    busybox-cron \
    python-imaging \
    ofgwrite \
    rtmpdump \
    libcrypto-compat-0.9.8 \
    ${@base_contains("MACHINE_FEATURES", "singlecore", "", \
    " \
    packagegroup-base-smbfs \
    packagegroup-base-nfs \
    ", d)} \
    packagegroup-base-smbfs-client \
    "
