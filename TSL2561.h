#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

void initTSL2561();
float getVisibleLight();
float getInfraredLight();
float getFullSpectrumLight();
