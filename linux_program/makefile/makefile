OBJS1 = hw_01_wifiset.o hw_02_getstate.o hw_03_wpstate.o wifi_testool_1.o

INCLUDES=./include

LIBDIRS=

#SMBLIBPATH=

#EXTRA_LDFLAGS =-L${SMBLIBPATH} -Wl,-rpath,${SMBLIBPATH} -Wl,-rpath-link,${SMBLIBPATH} 

#LINKEDSHLIBS +=-lmount
#LINKEDSHLIBS +=-lblkid 
#LINKEDSHLIBS +=-luuid

#LIBS=libmount.a libblkid.a libuuid.a
#LIBS=-lmount -lblkid -luuid 
#LIBS+= libnetsnmp.a
#LIBS+=-lssl -lcrypto

CFLAGS=-g -Wall -I$(INCLUDES) -DHAVE_EVP_MD_CTX_CREATE -DNETSNMP_USE_OPENSSL -DNETSNMP_DISABLE_MD5

#CC=arm-linux-gnueabihf-gcc 
CC=gcc
srcdir = .
top_srcdir = .
  
ALL = wifi_testool_1
all: $(ALL)

wifi_testool_1: $(OBJS1)
	$(CC) $(CLAGS) $(EXTRA_LDFLAGS) -o wifi_testool_1 $(OBJS1) $(LIBS)

%.o: %.c %.h
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	rm -f *.o
	rm -f $(ALL)

