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
	{ 0xea82d349, "hrtimer_init" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xc0b7c197, "hrtimer_start_range_ns" },
	{ 0x92997ed8, "_printk" },
	{ 0x102fe6de, "hrtimer_cancel" },
	{ 0x135bb7ec, "hrtimer_forward" },
	{ 0x474e54d2, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6F8FA01984FB3C9764A3010");
