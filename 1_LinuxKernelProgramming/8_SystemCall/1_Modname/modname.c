#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

char *modname = __stringify(KBUILD_MODNAME);

static int test_modname_init(void)
{
    printk("%s: In init\n", __func__);
    printk("%s: Module Name:%s Loaded\n", __func__, modname);
    return 0;
}

static void test_modname_exit(void)
{
    printk("%s: In exit\n", __func__);
    printk("%s: Module Name:%s Removed\n", __func__, modname);
}

module_init(test_modname_init);
module_exit(test_modname_exit);