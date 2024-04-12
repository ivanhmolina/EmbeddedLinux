#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int test_pmacros_init(void)
{
    printk(KERN_DEBUG"%s: In Init\n", __func__);
    pr_debug("%s: In Init 2\n", __func__);

    return 0;
}

static void test_pmacros_exit(void)
{
    pr_warn("%s: In Exit\n", __func__);
    pr_debug("%s: In Exit 2\n", __func__);
}

module_init(test_pmacros_init);
module_exit(test_pmacros_exit);