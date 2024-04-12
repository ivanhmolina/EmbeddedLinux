#include <linux/module.h>
#include <linux/printk.h>
#include <linux/cpumask.h>

static int __init mod_init(void)
{
    pr_info("%s: number of online cpus is %d\n", __func__, num_online_cpus());
    return 0;
}

static void __exit mod_exit(void)
{
    pr_info("%s: Exiting module\n", __func__);
}

module_init(mod_init);
module_exit(mod_exit);
MODULE_LICENSE("GPL");