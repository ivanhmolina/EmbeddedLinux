#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

static int hello_init(void)
{
    int i;

    for(i=0; i<20; i++)
    {
        /* $cat /proc/sys/kernel/printk_ratelimit_burst */
        if(printk_ratelimit())  
        {
            pr_info("%s: Printing %d\n", __func__, i+1);
        }
        else
        {
            /* $cat /proc/sys/kernel/printk_ratelimit */
            pr_info("%s: Sleeping for 5 seconds\n", __func__);
            msleep(5000);
            i--;
        }
    }

    return 0;
}

static void hello_exit(void)
{
    pr_info("%s: Done\n", __func__);
}

module_init(hello_init);
module_exit(hello_exit);
