CFLAGS  = -g -Wall -Wextra
LDFLAGS = -lm -lbcm2835

eink-demo:
	$(CC) -o eink-demo main.c \
				platform.c \
				usec-133-spi-lib/usec_dev.c \
			        -I./ -Iusec-133-spi-lib \
				$(CFLAGS) $(LDFLAGS)

clean:
	rm -f eink-demo *.o *~
