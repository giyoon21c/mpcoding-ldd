#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/kernel.h>

#define DRIVER_NAME "bmp180_driver"
#define BMP180_CHIP_ID_REG 0xD0
#define BMP180_EXPECTED_ID 0x55

// The 'Probe' function: Called when the device and driver match
static int bmp180_probe(struct i2c_client *client, const struct i2c_device_id *id) {
  s32 ret;

  pr_info("%s: Probing BMP180 at address 0x%x\n", DRIVER_NAME, client->addr);

  // Read the Chip ID to verify hardware
  ret = i2c_smbus_read_byte_data(client, BMP180_CHIP_ID_REG);
  
  if (ret < 0) {
    pr_err("%s: Failed to read from I2C bus\n", DRIVER_NAME);
    return ret;
  }

  if (ret != BMP180_EXPECTED_ID) {
    pr_err("%s: Wrong Chip ID! Expected 0x55, got 0x%x\n", DRIVER_NAME, ret);
    return -ENODEV;
  }

  pr_info("%s: Successfully identified BMP180! Chip ID: 0x%x\n", DRIVER_NAME, ret);
  return 0;
}

// The 'Remove' function: Called when the module is unloaded
static void bmp180_remove(struct i2c_client *client) {
  pr_info("%s: Removing driver for device at 0x%x\n", DRIVER_NAME, client->addr);
}

// Device ID table for the I2C subsystem
static const struct i2c_device_id bmp180_id[] = {
  { "bmp180", 0 },
  { }
};
MODULE_DEVICE_TABLE(i2c, bmp180_id);

// Driver structure
static struct i2c_driver bmp180_driver = {
  .driver = {
    .name = DRIVER_NAME,
    .owner = THIS_MODULE,
  },
  .probe = bmp180_probe,
  .remove = bmp180_remove,
  .id_table = bmp180_id,
};

// This macro replaces module_init and module_exit for I2C drivers
module_i2c_driver(bmp180_driver);

MODULE_AUTHOR("Dumble");
MODULE_DESCRIPTION("BMP180 I2C Kernel Driver");
MODULE_LICENSE("GPL");