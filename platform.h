#ifndef __PLATFORM_H_
#define __PLATFORM_H_

#include <stdint.h>
#include <stddef.h>
#include "usec_dev.h"

#define RST                  17
#define RDY                  24
#define CS0                  8

uint8_t
platform_init                (usec_ctx  *ctx);

uint8_t
platform_deinit              (usec_ctx  *ctx);

uint8_t
platform_delay_ms            (void      *platform,
                              uint16_t   delay_ms);

uint8_t
platform_hw_reset            (void      *platform);

uint8_t
platform_spi_write_byte      (void      *platform,
                              uint8_t    val);

uint8_t
platform_spi_write_bytes     (void      *platform,
                              uint8_t   *data,
                              uint32_t   len);

uint8_t
platform_spi_read_byte       (void      *platform);

uint8_t
platform_spi_cs_high         (void      *platform,
                              uint8_t    cs_num);

uint8_t
platform_spi_cs_low          (void      *platform,
                              uint8_t    cs_num);

uint8_t
platform_gpio_read           (void      *platform);

#endif /* __PLATFORM_H_ */
