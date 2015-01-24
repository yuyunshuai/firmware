/*
 * Copyright 2013 OpenMote Technologies, S.L.
 */

/**
 *
 * @file       Adxl346.h
 * @author     Pere Tuset-Peiro (peretuset@openmote.com)
 * @version    v0.1
 * @date       May, 2014
 * @brief
 * @ingroup
 *
 */

#ifndef ADXL346_H_
#define ADXL346_H_

#include <stdint.h>

#include "Sensor.h"
#include "Callback.h"

class I2cDriver;
class GpioIn;

class Adxl346: public Sensor
{
public:
    Adxl346(I2cDriver& i2c, GpioIn& gpio);
    bool enable(void);
    bool reset(void);
    bool isPresent(void);
    void setCallback(Callback* callback);
    void clearCallback(void);
    bool readAcceleration(void);
    uint16_t getX(void);
    uint16_t getY(void);
    uint16_t getZ(void);
private:
    I2cDriver& i2c_;
    GpioIn& gpio_;

    uint16_t x_;
    uint16_t y_;
    uint16_t z_;
};

#endif /* ADXL346_H_ */
