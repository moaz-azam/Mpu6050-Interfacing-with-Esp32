#include "esp_log.h"
#include "driver/i2c.h"

#define MPU6050_ADDR 0x68

static const char* TAG = "MPU6050";

void app_main()
{
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = GPIO_NUM_21,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_io_num = GPIO_NUM_22,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = 100000
    };

    i2c_param_config(I2C_NUM_0, &conf);
    i2c_driver_install(I2C_NUM_0, conf.mode, 0, 0, 0);

    uint8_t data[14];
    esp_err_t ret;

    while (1) {
        ret = i2c_master_read_slave(I2C_NUM_0, MPU6050_ADDR, data, sizeof(data), portMAX_DELAY);
        if (ret != ESP_OK) {
            ESP_LOGE(TAG, "Failed to read from MPU6050, error=%d", ret);
            continue;
        }

        // Parse the data and use it in your application
        int16_t accel_x = (data[0] << 8) | data[1];
        int16_t accel_y = (data[2] << 8) | data[3];
        int16_t accel_z = (data[4] << 8) | data[5];
        int16_t temp = (data[6] << 8) | data[7];
        int16_t gyro_x = (data[8] << 8) | data[9];
        int16_t gyro_y = (data[10] << 8) | data[11];
        int16_t gyro_z = (data[12] << 8) | data[13];

        // Do something with the data
    }
}
