CFLAGS  = -g -Wall -Wextra -Wno-unused-parameter
LDFLAGS = -lm -lbcm2835

usec-133-raspberry-spi-example:
	$(CC) -o usec-133-raspberry-spi-example main.c \
				platform.c \
				usec-133-spi-lib/usec_dev.c \
			        -I./ -Iusec-133-spi-lib \
				$(CFLAGS) $(LDFLAGS)

clean:
	rm -f usec-133-raspberry-spi-example *.o *~
