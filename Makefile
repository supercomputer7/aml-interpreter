PROGRAM_OBJS = \
    main.o \
	tables/dsdt.o

OUTPUT = amldecode
CXXFLAGS = -O2 -Wall -Wextra -fno-exceptions
CXXFLAGS += -I./
LDFLAGS = -o amldecode -O2 -lgcc
CXX = gcc
LD = gcc
LINK = gcc

.PHONY: all

all: $(OUTPUT)

.c.o: 
	@echo "C $<"; $(CXX) $(CXXFLAGS) -o $@ -c $<

$(OUTPUT): $(PROGRAM_OBJS)
	@echo "LD $@"; $(LD) $(LDFLAGS) -o $@ $(PROGRAM_OBJS)

clean:
	@echo "CLEAN"; rm -f $(PROGRAM_OBJS)
