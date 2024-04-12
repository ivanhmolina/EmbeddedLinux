#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int dumpstack_init(void)
{
    pr_info("%s: In init: dump_stack: \n", __func__);
    dump_stack();
    
    pr_info("dump_stack after\n");
    return 0;
}

static void dumpstack_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(dumpstack_init);
module_exit(dumpstack_exit);