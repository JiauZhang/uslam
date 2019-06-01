VERSION = 0
PATCHLEVEL = 0
SUBLEVEL = 1
PROJECT := uslam

MAKEFLAGS += -rR --no-print-directory

ifeq ("$(origin V)", "command line")
    KBUILD_VERBOSE = $(V)
endif
ifndef KBUILD_VERBOSE
    KBUILD_VERBOSE = 0
endif

# That's our default target when none is given on the command line
PHONY := _all
_all:

# Cancel implicit rules on top Makefile
$(CURDIR)/Makefile Makefile: ;

PHONY += all
_all: all

srctree := $(CURDIR)
objtree := $(CURDIR)
src = $(srctree)
obj := $(objtree)

VPATH := $(srctree)

export srctree objtree VPATH

HOSTCC       = gcc
HOSTCXX      = g++
HOSTCFLAGS   = -Wall -Wmissing-prototypes -Wstrict-prototypes -O2 -fomit-frame-pointer
HOSTCXXFLAGS = -O2

ifeq ($(KBUILD_VERBOSE),1)
  quiet =
  Q =
else
  quiet=quiet_
  Q = @
endif

export quiet Q KBUILD_VERBOSE

# Look for make include files relative to root of kernel src
MAKEFLAGS += --include-dir=$(srctree)

AS		= $(CROSS_COMPILE)as
LD		= $(CROSS_COMPILE)ld
CC		= $(CROSS_COMPILE)gcc
CPP		= $(CROSS_COMPILE)g++
AR		= $(CROSS_COMPILE)ar
NM		= $(CROSS_COMPILE)nm
STRIP		= $(CROSS_COMPILE)strip
OBJCOPY		= $(CROSS_COMPILE)objcopy
OBJDUMP		= $(CROSS_COMPILE)objdump
AWK		= awk

# include/ directory
USLAMINCLUDE    := -Iinclude \
                   -I$(srctree)/include \
				   -I$(srctree)/include/ros

export VERSION PATCHLEVEL SUBLEVEL
export SSLAMINCLUDE
export CPP AR NM STRIP OBJCOPY OBJDUMP
export MAKE AWK
export HOSTCXX HOSTCXXFLAGS

src-y := src/

all:
	echo $(srctree)
	echo $(objtree)
	
uslam:
	$(Q)$(MAKE) -C $(srctree)/src uslam.o
	
ros_tutorial%:
	$(Q)$(MAKE) -C $(srctree)/ros/tutorial $(patsubst ros_tutorial_%,%, $@).o

ros_tutorial:
	$(Q)$(MAKE) -C $(srctree)/ros/tutorial $@
	
ros_lib%:
	$(Q)$(MAKE) -C $(srctree)/ros $(patsubst ros_lib_%,%, $@)
	
ros_lib:
	$(Q)$(MAKE) -C $(srctree)/ros $@
	
viewer_factory:
	$(Q)$(MAKE) -C $(srctree)/src $@

#include $(srctree)/src/Makefile

PHONY += FORCE
FORCE:

.PHONY: $(PHONY)