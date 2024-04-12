#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int hello_init(void)
{
    printk(KERN_INFO KERN_CONT"%s: Hello ", __func__);
    printk(KERN_INFO KERN_CONT"World\n");

    return 0;
}

static void hello_exit(void)
{
    pr_info("%s: Done\n", __func__);
}

module_init(hello_init);
module_exit(hello_exit);