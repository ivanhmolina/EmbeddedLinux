/*#include <linux/kernel.h>*/
/*#include <linux/module.h>*/

/*MODULE_LICENSE("GPL");*/

/*static int test_hello_init(void)*/
/*{*/
/*    printk(KERN_INFO, "%s: In init\n", __func__);*/
/*    return 0;*/
/*}*/

/*static void test_hello_exit(void)*/
/*{*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Hello, how are you?\n");
	return 0;
}
