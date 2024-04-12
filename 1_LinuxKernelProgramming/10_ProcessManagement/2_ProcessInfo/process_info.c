#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");

char buffer[256];
char * get_task_state(long state)
{
    switch (state)
    {
    case TASK_RUNNING:
        sprintf(buffer, "TASK_RUNNING\n");
        break;
    case TASK_INTERRUPTIBLE:
        sprintf(buffer, "TASK_INTERRUPTIBLE\n");
        break;
    case TASK_UNINTERRUPTIBLE:
        sprintf(buffer, "TASK_UNINTERRUPTIBLE\n");
        break;
    case __TASK_STOPPED:
        sprintf(buffer, "__TASK_STOPPED\n");
        break;
    case __TASK_TRACED:
        sprintf(buffer, "__TASK_TRACED\n");
        break;
    default:
        sprintf(buffer, "Unknown Type:%ld\n", state);
    }

    return buffer;
}

static int process_info_init(void)
{
    struct task_struct *task_list;
    unsigned int process_count = 0;

    /* define for_each_process(p) \
     * for (p = &init_task ; (p = next_task(p)) != &init_task;)
    */

    for_each_process(task_list)
    {
        pr_info("Process: %s\t\t PID: [%d]\t State: %s\n", 
                task_list->comm, task_list->pid, 
                get_task_state(task_list->__state));
        
        process_count++;
    }

    pr_info("%s: Number of processes:%u\n", __func__, process_count);
    
    return 0;
}

static void process_info_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(process_info_init);
module_exit(process_info_exit);