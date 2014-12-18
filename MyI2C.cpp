#include "MyI2C.h"
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>          //O_RDWR
#include <stdio.h>          //perror

namespace TRexLib{
    

    ssize_t (* pi_i2c_write)(int, const void *, size_t) = write;
    ssize_t (* pi_i2c_read)(int, void *, size_t) = read;

    MyI2C::MyI2C(const char * device, int i2caddress):I2C(device, i2caddress)
    {
        openBus();
        acquireBus(i2caddress);
    }

            /*
             * Write data to an I2C slave device.
             *
             * @address the I2C slave device address (not actually used but kept for compatibility with mbed functions)
             * @data buffer containing the bytes that should be written to the slave
             * @length number of bytes in the buffer to write
             *
             * @return 0 on failure
             */
    int MyI2C::write(int address, char * data, int length)
    {
        return pi_i2c_write(this->handle,data,length);
        
    }

            /*
             * Read data from an I2C slave device.
             *
             * @address the I2C slave device address (not actually used but kept for compatibility with mbed functions)
             * @data buffer to store the byte values received from the device
             * @length number of bytes to read from the device (should be at least size of data buffer)
             *
             * @return 0 on failure
             */
    int MyI2C::read(int address, char * data, int length)
    {
        return pi_i2c_read(this->handle,data,length);
        
    }
            /*
             * Open the I2C bus device so the read and write functions can be used.
             *
             * @return a non-negative integer if the open action was succesful
             */
    int MyI2C::openBus(void)
    {
        this->handle = open(this->device, O_RDWR);
        return handle;
    }

            /*
             * Set the slave device address and thereby acquire the bus.
             *
             * @i2caddress the I2C slave device address
             *
             * @return a non-negative integer if the aquire action was succesful
             */
    int MyI2C::acquireBus(int i2caddress)
    {
        return ioctl(this->handle,I2C_SLAVE,i2caddress);
    }
}