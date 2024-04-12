#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int hello_init(void)
{
    char buffer[] = "Hello World. Linux is the best OS";
    print_hex_dump( 
                    KERN_ALERT, 
                    "print_hex_dump: ", 
                    DUMP_PREFIX_OFFSET, /*DUMP_PREFIX_ADDRESS, DUMP_PREFIX_NONE*/
                    16, 
                    1, 
                    buffer, 
                    sizeof(buffer), 
                    1
                );

    print_hex_dump_bytes(
                        "print_hex_dump_bytes: ", 
                        DUMP_PREFIX_ADDRESS, 
                        buffer, 
                        sizeof(buffer)
                    );

    return 0;
}

static void hello_exit(void)
{
    pr_info("%s: Done\n", __func__);
}

module_init(hello_init);
module_exit(hello_exit);