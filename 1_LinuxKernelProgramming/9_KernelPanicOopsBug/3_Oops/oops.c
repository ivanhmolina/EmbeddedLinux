#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int test_oops_init(void)
{
    pr_info("%s: In init\n", __func__);

    /*Trying to access invalid memory location*/
    *(int *)0x12 = 'a';

    return 0;
}

static void test_oops_exit(void)
{
    pr_info("%s: In exit", __func__);
}

module_init(test_oops_init);
module_exit(test_oops_exit);