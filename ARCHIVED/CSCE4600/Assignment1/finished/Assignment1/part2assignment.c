#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>

#define NUM_OF_PERSON   5

/* Example struct we will use. */
typedef struct _birthday {
   int day;
   int month;
   int year;
   struct list_head list;
}birthday;

/* Declare and init the head of the linked list. */
LIST_HEAD(birthday_list);

/* This function is called when the module is loaded. */
int birthdayList_init(void)
{
          printk(KERN_INFO "Loading Module\n");

   /* Allocate 5 birthdays from kernel */
   birthday *person;
   int i = 0;
   for(i = 0; i < NUM_OF_PERSON; i++)
   {
       /* Request malloc to the kernel. */
       person = kmalloc(sizeof(*person), GFP_KERNEL);
       /* Assign value to the struct. */
       person->day = i+1;
       person->month = i+1;
       person->year = i+1;
       /* Init the list within the struct. */
       INIT_LIST_HEAD(&person->list);
       /* Add this struct to the tail of the list. */
       list_add_tail(&person->list, &birthday_list);
   }

   printk(KERN_INFO "Display the list:\n");

   /* Go through the list and print. */
   birthday *ptr;
   list_for_each_entry(ptr, &birthday_list, list)
   {
       printk(KERN_INFO "day: %d, month: %d, year: %d\n", ptr->day, ptr->month, ptr->year);
   }

   printk(KERN_INFO "Display done\n");

          return 0;
}

/* This function is called when the module is removed. */
void birthdayList_exit(void)
{
   printk(KERN_INFO "Removing Module\n");

   /* Go through the list and free the memory. */
   birthday *ptr, *next;
   list_for_each_entry_safe(ptr, next, &birthday_list, list)
   {
       printk(KERN_INFO "Removing - day: %d, month: %d, year: %d\n", ptr->day, ptr->month, ptr->year);
       list_del(&ptr->list);
       kfree(ptr);
   }

   printk(KERN_INFO "Memory free done\n");
}

/* Macros for registering module entry and exit points. */
module_init( birthdayList_init );
module_exit( birthdayList_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("BirthdayList Module");
MODULE_AUTHOR("daveti");
