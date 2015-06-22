SRCS=startup.c

TARGET=libstartup.a

CC=arm-none-eabi-gcc

CFLAGS = -g -Wall  -mcpu=cortex-m4 -mlittle-endian -mthumb \
	 -nostdlib -ffreestanding

OBJS=$(SRCS:.c=.o)

.PHONY: all clean run

all:	$(TARGET)

$(TARGET):	$(OBJS)
	$(AR) rcs $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
