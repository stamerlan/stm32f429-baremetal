SRCS=start.c main.c

LD_SCRIPT=stm32f429.ld
LIBS = startup
TARGET=baremetal

CFLAGS = -g -Wall  -mcpu=cortex-m4 -mlittle-endian -mthumb \
	 -nostdlib -ffreestanding
LDFLAGS =

CFLAGS += $(addprefix -Ilibs/, $(LIBS))
LDFLAGS += $(addprefix -Llibs/, $(LIBS))
LDFLAGS += $(addprefix -l, $(LIBS))

CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
LD=arm-none-eabi-ld

OBJS=$(SRCS:.c=.o)
LIBRARIES = $(foreach lib, $(LIBS), libs/$(lib)/lib$(lib).a)

.PHONY: all clean run

all:	$(TARGET).bin

$(LIBRARIES):
	$(MAKE) -C $(dir $@)

$(TARGET).bin:	$(OBJS) $(LIBRARIES)
	$(LD) -T$(LD_SCRIPT) $(LDFLAGS) $(OBJS) -o $(TARGET).elf 
	$(OBJCOPY) -O ihex $(TARGET).elf $(TARGET).hex
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin

run:	$(TARGET).bin
	st-flash write $(TARGET).bin 0x8000000

clean:
	rm -f $(OBJS) $(TARGET).hex $(TARGET).bin $(TARGET).elf
	$(foreach lib, $(LIBRARIES), $(MAKE) -C $(dir $(lib)) clean; )
