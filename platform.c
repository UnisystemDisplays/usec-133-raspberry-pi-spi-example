#include "platform.h"
#include <bcm2835.h>

/*
 * platform_init()
 */
uint8_t
platform_init (usec_ctx *ctx)
{
  /* init lib */
  if (bcm2835_init() != 1)
    return USEC_DEV_ERR;

  /* init spi module */
  if (bcm2835_spi_begin() != 1)
    return USEC_DEV_ERR;

  /* init gpio direction */
  bcm2835_gpio_fsel (RDY, BCM2835_GPIO_FSEL_INPT);  /* input */
  bcm2835_gpio_fsel (RST, BCM2835_GPIO_FSEL_OUTP);  /* output */
  bcm2835_gpio_fsel (CS0, BCM2835_GPIO_FSEL_OUTP);  /* output */

  /* set default gpio values */
  bcm2835_gpio_write (RST, HIGH);
  bcm2835_gpio_write (CS0, HIGH);

  /* set spi bit order */
  bcm2835_spi_setBitOrder (BCM2835_SPI_BIT_ORDER_MSBFIRST);

  /* set spi to mode 0 - CPOL = 0, CPHA = 0 */
  bcm2835_spi_setDataMode (BCM2835_SPI_MODE0);

  /* sets the SPI clock divider */
  //bcm2835_spi_setClockDivider (BCM2835_SPI_CLOCK_DIVIDER_16); /* for RPi 3 */
  bcm2835_spi_setClockDivider (BCM2835_SPI_CLOCK_DIVIDER_32); /* for RPi 4 */

  /* init platform specific data - not used for Raspberry Pi */
  ctx->platform = NULL;

  return USEC_DEV_OK;
}

/*
 * platform_deinit()
 */
uint8_t
platform_deinit (usec_ctx *ctx)
{
  bcm2835_spi_end();
  bcm2835_close ();
  ctx->platform = NULL;

  return USEC_DEV_OK;
}

/*
 * platform_delay_ms()
 */
uint8_t
platform_delay_ms (void      *platform,
                   uint16_t   delay_ms)
{
  bcm2835_delay (delay_ms);

  return USEC_DEV_OK;
}

/*
 * platform_hw_reset()
 */
uint8_t
platform_hw_reset (void *platform)
{
  bcm2835_gpio_write (RST, LOW);
  bcm2835_delay (100);
  bcm2835_gpio_write (RST, HIGH);
  bcm2835_delay (200);

  return USEC_DEV_OK;
}

/*
 * platform_spi_write_byte()
 */
uint8_t
platform_spi_write_byte (void    *platform,
                         uint8_t  val)
{
  (void) bcm2835_spi_transfer (val);
  return USEC_DEV_OK;
}

/*
 * platform_spi_write_bytes()
 */
uint8_t
platform_spi_write_bytes (void      *platform,
                          uint8_t   *data,
                          uint32_t   len)
{
  bcm2835_spi_transfern ((char*)data, len);
  return USEC_DEV_OK;
}

/*
 * platform_spi_read_byte()
 */
uint8_t
platform_spi_read_byte (void *platform)
{
  return bcm2835_spi_transfer (0x00);
}

/*
 * platform_spi_cs_high()
 */
uint8_t
platform_spi_cs_high (void     *platform,
                      uint8_t   cs_num)
{
  bcm2835_gpio_write (CS0, HIGH);
  return USEC_DEV_OK;
}

/*
 * platform_spi_cs_low()
 */
uint8_t
platform_spi_cs_low (void     *platform,
                     uint8_t   cs_num)
{
  bcm2835_gpio_write (CS0, LOW);
  return USEC_DEV_OK;
}

/*
 * platform_gpio_read()
 */
uint8_t
platform_gpio_read (void *platform)
{
  return bcm2835_gpio_lev (RDY);
}
