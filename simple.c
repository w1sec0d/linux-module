#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <asm/param.h>
#include <linux/jiffies.h>

static unsigned long init_jiffies;

/* This function is called when the module is loaded. */
static int __init simple_init(void)
{
    init_jiffies = jiffies;
    printk(KERN_INFO "Loading Kernel Module\n");
    printk(KERN_INFO "Golden Prime Ratio: %llu\n", GOLDEN_RATIO_PRIME);
    printk(KERN_INFO "HZ: %u\n", HZ);
    printk(KERN_INFO "Jiffies: %lu\n", jiffies);
    return 0;
}

/* This function is called when the module is removed. */
static void __exit simple_exit(void)
{
    unsigned long result = gcd(3300, 24);
    unsigned long exit_jiffies = jiffies;
    unsigned long elapsed_jiffies = exit_jiffies - init_jiffies;
    unsigned long elapsed_seconds = elapsed_jiffies / HZ;
    printk(KERN_INFO "Removing Kernel Module\n");
    printk(KERN_INFO "GCD (3300, 24): %lu\n", result);
    printk(KERN_INFO "Jiffies: %lu\n", jiffies);
    printk(KERN_INFO "Elapsed Jiffies: %lu\n", elapsed_jiffies);
    printk(KERN_INFO "Elapsed Time: %lu seconds\n", elapsed_seconds);

}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("Juan Madrid | Carlos Ramirez | Cristian Ramirez");
