SUMMARY = "Transmission is a BitTorrent client w/ a built-in Ajax-Powered Webif GUI."
SECTION = "network"
HOMEPAGE = "www.transmissionbt.com/"
DEPENDS = "gtk+ gnutls openssl gettext libtool intltool-native curl glib-2.0-native libevent"
LICENSE = "GPLv2"
INC_PR = "r2"

SRC_URI = "https://transmission.cachefly.net/transmission-${PV}.tar.xz;name=archive \
           file://init \
           file://config"

INITSCRIPT_NAME = "transmission"
INITSCRIPT_PARAMS = "defaults 60 "

inherit autotools update-rc.d gettext

do_install_append() {
    install -d ${D}${sysconfdir}/init.d
    install -m 0755 ${WORKDIR}/init ${D}${sysconfdir}/init.d/transmission
    install -d ${D}${sysconfdir}/default
    install -m 0755 ${WORKDIR}/config ${D}${sysconfdir}/default/transmission-daemon
    install -d ${D}${localstatedir}/lib/transmission-daemon
}

PACKAGES += "${PN}-gui ${PN}-client"

FILES_${PN} = "${bindir}/transmission-daemon ${datadir}/transmission ${sysconfdir} ${localstatedir}/lib/${PN}-daemon"
FILES_${PN}-client = "${bindir}/transmission-cli ${bindir}/transmission-remote ${bindir}/transmission-edit ${bindir}/transmission-show ${bindir}/transmission-create"
FILES_${PN}-gui += "${bindir}/transmission ${datadir}/icons ${datadir}/applications ${datadir}/pixmaps"
CONFFILES_${PN} = "${sysconfdir}/default/transmission-daemon"

