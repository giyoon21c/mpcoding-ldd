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
	{ 0xf9a482f9, "msleep" },
	{ 0xa0c562db, "gpio_to_desc" },
	{ 0xcf6b2d6, "gpiod_get_raw_value" },
	{ 0xf4d3665c, "gpiod_set_raw_value" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x7d896ede, "gpiod_direction_output_raw" },
	{ 0xfe990052, "gpio_free" },
	{ 0x3bdfd684, "gpiod_direction_input" },
	{ 0x9c62fdb0, "gpiod_to_irq" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x474e54d2, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "22A03CC151D57D5A2415E85");
