#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int test_bug_init(void)
{
    pr_info("%s: In init\n", __func__);
    
    BUG();

    return 0;
}

static void test_bug_exit(void)
{
    pr_info("%s: In exit", __func__);
}

module_init(test_bug_init);
module_exit(test_bug_exit);