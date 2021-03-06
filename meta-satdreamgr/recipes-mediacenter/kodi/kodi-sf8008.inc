SRCDATE = "20190320"

SRC_URI_remove = "file://e2player.patch \
           file://add-gstplayer-support.patch \
"

SRC_URI_append = "http://source.mynonpublic.com/octagon/hiplayer_${SRCDATE}.tar.gz \
    file://hiplayer.patch \
"

SRC_URI[md5sum] = "598dc7d5c56893e4d3ac35b194599a9f"
SRC_URI[sha256sum] = "31dfdcf23d56115267423d6d827af3c606fc1e9f0ffe0bf6ac8fee6b305e1efd"

DEPENDS += "octagon-libs-${MACHINE}"

RDEPENDS_${PN} += "octagon-libs-${MACHINE}"
RDEPENDS_${PN} += "octagon-opengl-${MACHINE}"

do_configure_append() {
        install -d ${D}${libdir}
        install -m 0755 ${WORKDIR}/hiadp.a      ${WORKDIR}/git/xbmc/linux/hisi/
        install -m 0755 ${WORKDIR}/hiplayer.a   ${WORKDIR}/git/xbmc/cores/hiplayer/
}

EXTRA_OECONF += " \
    --with-platform=clap-cortexa15 \
    --with-ffmpeg=stb \
"
