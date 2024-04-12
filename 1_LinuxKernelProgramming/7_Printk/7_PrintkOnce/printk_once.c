#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int hello_init(void)
{
    int i;

    for (i = 0; i < 20; i++)
    {
        printk_once(KERN_INFO"%s: Printing %d\n", __func__, i);
    }
    
    /*This will also be printed, since it's line by line*/
    printk_once(KERN_INFO"%s: Printing %d\n", __func__, i);

    return 0;
}

static void hello_exit(void)
{
    pr_info("%s: Done\n", __func__);
}

module_init(hello_init);
module_exit(hello_exit);