/*See /linux-6.7.4/include/linux/kern_levels.h to see log levels*/

#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
    /*Warning conditions log level*/
    printk("\001""4""%s: In init\n", __func__);
    return 0;
}

static void test_hello_exit(void)
{
    /*Critical conditions log level*/
    printk("\001""2""%s: In exit\n", __func__); 
}

module_init(test_hello_init);
module_exit(test_hello_exit);