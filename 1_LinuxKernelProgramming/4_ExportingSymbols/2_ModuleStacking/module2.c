#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nexys");

int myadd(int, int);

int number1 = 2;
int number2 = 5;

static int module2_init(void)
{
    printk(KERN_INFO"%s: In Init\n", __func__);
    printk(KERN_INFO"%s: The addition of %d and %d is %d\n", __func__, number1, number2, myadd(number1, number2));
    return 0;
}

static void module2_exit(void)
{
    printk(KERN_INFO"%s: In Exit\n", __func__);
    return;
}

module_init(module2_init);
module_exit(module2_exit);
