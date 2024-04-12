#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int test_pmacros_init(void)
{
    pr_emerg("%s: In Init\n", __func__);
	pr_alert("%s: In Init\n", __func__);
	pr_crit("%s: In Init\n", __func__);
	pr_err("%s: In Init\n", __func__);
	pr_notice("%s: In Init\n", __func__);
    pr_info("%s: In Init\n", __func__);

    return 0;
}

static void test_pmacros_exit(void)
{
    pr_warn("%s: In Exit\n", __func__);
}

module_init(test_pmacros_init);
module_exit(test_pmacros_exit);