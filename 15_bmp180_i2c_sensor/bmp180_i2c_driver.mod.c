#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x92997ed8, "_printk" },
	{ 0x4df1662e, "i2c_client_get_device_id" },
	{ 0x991b5c57, "i2c_smbus_read_byte_data" },
	{ 0x7c1dcb20, "i2c_register_driver" },
	{ 0x534e9a04, "i2c_get_adapter" },
	{ 0xd8ff692a, "i2c_del_driver" },
	{ 0x1e30f5c4, "i2c_new_client_device" },
	{ 0x4080a4df, "i2c_put_adapter" },
	{ 0x85a4029c, "i2c_unregister_device" },
	{ 0x474e54d2, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:bmp180-a");
MODULE_ALIAS("i2c:bmp180-b");

MODULE_INFO(srcversion, "43374A4B8527AC778ED7A0C");
