
#include <stdlib.h>
#include "spi_bus.h"

struct SPI_BUS_S
{

};

SPI_BUS_T SpiBusNew(void)
{
    SPI_BUS_T newBus = malloc(sizeof(struct SPI_BUS_S));
    return newBus;
}
