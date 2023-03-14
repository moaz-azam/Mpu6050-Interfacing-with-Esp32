# Mpu6050-Interfacing-with-Esp32

To interface MPU6050 with ESP32 using ESP IDF, you can follow these steps:

Connect the MPU6050 sensor to the ESP32 using I2C communication. The SDA and SCL pins of the MPU6050 should be connected to the SDA and SCL pins of the ESP32, respectively. Also, connect the VCC and GND pins of the MPU6050 to the appropriate pins of the ESP32.

Initialize the I2C driver of the ESP32 using the I2C master API provided by the ESP IDF. You can use the i2c_master_init() function to initialize the I2C driver.

Use the I2C master API to read the data from the MPU6050 sensor. You can use the i2c_master_read() function to read the data from the sensor.

Parse the data read from the MPU6050 sensor and use it in your application.
