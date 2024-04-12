#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int test_pfloat_init(void)
{
    float f = 2.56;
    printk("%s: In init, value of f is %f\n", __func__, f);

    return 0;
}

static void test_pfloat_exit(void)
{
    printk("%s: In Exit\n", __func__);
}

module_init(test_pfloat_init);
module_exit(test_pfloat_exit);