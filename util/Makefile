#
# Copyright 2009, Bernd H Stramm
#


# what to make
#
TARGET= libberndsutil.a

ARCHIVE = $(TARGET).tar.gz

# what to make it from
#
LOCALSRC= confdict.cpp uniqueid.cpp coord.cpp fault.cpp vec2.cpp

LOCALHDR= confdict.h uniqueid.h fault.h coord.h berndsutil.h vec2.h


# some hints how to make it
#
SRC=$(LOCALSRC)
DOC= 


HDR= $(LOCALHDR)

CXX= g++
CXXFLAGS= -g -O2 -Wall -Wno-long-long -pedantic

CXXOBJ=$(LOCALSRC:.cpp=.o)

OBJ= $(CXXOBJ)

all: $(TARGET)

new: clean all

install:
	install $(HDR) $(HOME)/include
	install $(TARGET) $(HOME)/lib


doc:
	doxygen

filelist:
	echo "" > filelist
	for f in $(SRC) $(HDR) ; do \
	    echo $$f >> filelist ; \
	    done


dep:  Makefile $(SRC) $(HDR)
	echo "" > dep
	for f in $(SRC) ; do \
	   $(CXX)  -MM $$f >> dep; \
	   done

$(TARGET): $(OBJ) Makefile
	ar rcs $(TARGET) $(OBJ)

$(ARCHIVE): $(SRC) $(HDR) Makefile $(DOC)
	tar zcvf $(ARCHIVE) $(SRC) $(HDR) $(DOC) Makefile
	@ls -l $(ARCHIVE)

newtar:
	rm $(ARCHIVE)
	make tar

tar: $(ARCHIVE)

backup: tar

clean:
	rm $(OBJ) $(TARGET)
	rm dep

unixify:
	dos2unix $(SRC) $(HDR) Makefile

.SUFFIXES:

%.o: %.cpp Makefile
	$(CXX) -c $(CXXFLAGS)  $<

# depedencies, created by "make dep" about
#

include dep

