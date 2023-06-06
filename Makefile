.POSIX:

XCFLAGS = ${CPPFLAGS} ${CFLAGS} -nostdlib -std=c99 -fPIC -pthread -D_XOPEN_SOURCE=700 \
		  -Wall -Wextra -Wpedantic -Wmissing-prototypes -Wstrict-prototypes \
		  -Wno-unused-parameter
XLDFLAGS = ${LDFLAGS} -shared -Wl,-soname,libatk-1.0.so.0

INCLUDE = -I. -I.. -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include

OBJ = \
	atkaction.o\
	atkcomponent.o\
	atkdocument.o\
	atkeditabletext.o\
	atk-enum-types.o\
	atkgobjectaccessible.o\
	atkhyperlink.o\
	atkhyperlinkimpl.o\
	atkhypertext.o\
	atkimage.o\
	atkmarshal.o\
	atkmisc.o\
	atknoopobject.o\
	atknoopobjectfactory.o\
	atkobject.o\
	atkobjectfactory.o\
	atkplug.o\
	atkprivate.o\
	atkrange.o\
	atkregistry.o\
	atkrelation.o\
	atkrelationset.o\
	atkselection.o\
	atksocket.o\
	atkstate.o\
	atkstateset.o\
	atkstreamablecontent.o\
	atktable.o\
	atktablecell.o\
	atktext.o\
	atkutil.o\
	atkvalue.o\
	atkversion.o\
	atkwindow.o\

all: libatk-1.0.so.0

.c.o:
	${CC} ${INCLUDE} ${XCFLAGS} -c -o $@ $<

libatk-1.0.so.0: ${OBJ}
	${CC} ${INCLUDE} ${XCFLAGS} -o $@ ${OBJ} ${XLDFLAGS}

install: libatk-1.0.so.0
	mkdir -p ${DESTDIR}/usr/lib64
	cp -f libatk-1.0.so.0 ${DESTDIR}/usr/lib64/libatk-1.0.so
	ln -rsf ${DESTDIR}/usr/lib64/libatk-1.0.so ${DESTDIR}/usr/lib64/libatk-1.0.so.0

uninstall:
	rm -f ${DESTDIR}/usr/lib64/libatk-1.0.so.0 ${DESTDIR}/usr/lib64/libatk-1.0.so

clean:
	rm -f libatk-1.0.so.0 ${OBJ}

.PHONY: all clean install uninstall
