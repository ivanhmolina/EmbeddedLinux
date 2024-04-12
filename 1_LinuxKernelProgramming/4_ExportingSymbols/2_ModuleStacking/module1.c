#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nexys");

int myadd(int a, int b)
{
    return a + b;
}

static int module1_init(void)
{
    printk(KERN_INFO"%s: In Init\n", __func__);
    return 0;
}

static void module1_exit(void)
{
    printk(KERN_INFO"%s: In Exit\n", __func__);
    return;
}

EXPORT_SYMBOL_GPL(myadd);
module_init(module1_init);
module_exit(module1_exit);
