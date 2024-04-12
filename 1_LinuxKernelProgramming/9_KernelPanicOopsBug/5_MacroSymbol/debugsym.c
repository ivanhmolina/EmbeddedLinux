#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int test_debugsym_init(void)
{
#ifdef DEBUG
    pr_info("%s: In init\n", __func__);
#endif
    return 0;
}

static void test_debugsym_exit(void)
{
#ifdef DEBUG
    pr_info("%s: In exit", __func__);
#endif
}

module_init(test_debugsym_init);
module_exit(test_debugsym_exit);