#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

static bool param_invbool = false;
module_param(param_invbool, invbool, S_IRUGO);

static int my_invbool_init(void)
{
    pr_info("param_invool \t : %s\n", param_invbool ? "true": "false");
    return 0;
}

static void my_invbool_exit(void)
{
    printk(KERN_INFO"%s: In exit:\n", __func__);
}

module_init(my_invbool_init);
module_exit(my_invbool_exit);
MODULE_AUTHOR("Nexys");
MODULE_LICENSE("GPL");