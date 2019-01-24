MCU=	stm8
DEVICE=	stm8al3188
FLASHER=stlinkv2
CC=	sdcc
MAINSRC=ledblink.c
EXTRASRC=delay.c
RELS=$(EXTRASRC:.c=.rel)
CFLAGS=	-mstm8
LIBS=	-lstm8
IDIR=	-I./libs
ODIR=	./bin
TARGET=	ledblink
IHX=	$(TARGET).ihx

OBJECTS := delay.rel ledblink.rel

.PHONY: all clean

all:	$(IHX)

$(IHX):	$(MAINSRC) $(RELS)
	$(CC) $(CFLAGS) $(MAINSRC) $(RELS) $(LIBS)

.c.rel:
	$(CC) -c $(CFLAGS) $<

.SUFFIXES: .c .rel


clean:
	rm *.ihx *.sym *.asm *.rel *.map *.cdb *.rst

flash: $(IHX)
	stm8flash -cstlinkv2 -pstm8al3188 -w $(IHX)

