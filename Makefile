SRCS=start.c main.c

LD_SCRIPT=stm32f429.ld

TARGET=baremetal

CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
LD=arm-none-eabi-ld

#CFLAGS= -g3 -Wall -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork \
#	-mfloat-abi=hard -mfpu=fpv4-sp-d16 -nostdlib -ffreestanding
CFLAGS = -g -Wall  -mcpu=cortex-m4 -mlittle-endian -mthumb \
	 -nostdlib -ffreestanding

OBJS=$(SRCS:.c=.o)

.PHONY: all clean run

all:	$(TARGET).bin

$(TARGET).bin:	$(OBJS)
	$(LD) -T$(LD_SCRIPT) $(OBJS) -o $(TARGET).elf
	$(OBJCOPY) -O ihex $(TARGET).elf $(TARGET).hex
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin

run:	$(TARGET).bin
	st-flash write $(TARGET).bin 0x8000000

clean:
	rm -f $(OBJS) $(TARGET).hex $(TARGET).bin $(TARGET).elf
