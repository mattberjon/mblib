LIBRARY_NAME = mblib

SOURCES	= src/
ABSTRACTIONS	= abs/*.pd
EXAMPLES = examples/*.pd
BUILD = /tmp/build

CC = gcc
CSYM=$(NAME)
EXT := $(shell uname -s | sed -e 's/^[lL]/pd_l/' | sed -e 's/MINGW.*/dll/')

INSTALL = install
INSTALL_PROGRAM = $(INSTALL) -p -m 644
INSTALL_DATA = $(INSTALL) -p -m 644
INSTALL_DIR     = $(INSTALL) -p -m 755 -d

ifeq ($(EXT), pd_linux)
LDFLAGS =  -export_dynamic -shared -L/usr/local/lib
LD = ld
LIBS = -lpthread -lc -lm
CFLAGS = -O2 -Wall -funroll-loops -fomit-frame-pointer -fPIC -DPD \
	-W -Wshadow -Wstrict-prototypes \
	-Wno-unused -Wno-parentheses -Wno-switch
endif

ifeq ($(EXT), dll)
LDFLAGS = --export-dynamic -shared
CFLAGS = -DPD -DNT -W3 -WX -Werror -Wno-unused -mms-bitfields \
				 -Wno-parentheses -Wno-switch -O6 -funroll-loops -fomit-frame-pointer
OS = windows
PD_PATH = $(%CommonProgramFiles%)\Pd
endif

INCLUDE = -I. -I$(PDPATH)/src 

SRC = $(wildcard $(SOURCES)*.c)
OBJ = $(SRC:.c=.o)

$(NAME).$(EXT): $(OBJ)
	$(LD) $(LDFLAGS) -o $@ $(OBJ) $(LIBS)
	strip --strip-unneeded $@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $?

$(LIB): $(OBJ)
	$(AR) r $@ $?
	$(AR) s $@

clean:
	rm -f $(BUILD)/*.o $(BUILD)/*.*~

mrproper:
	rm -f $(BUILD)/*.o $(BUILD)/*.$(EXT)

install: $(NAME).$(EXT)
	if ! test -d  ../lib; then mkdir  ../lib;fi
	cp $(NAME).$(EXT) ../lib
