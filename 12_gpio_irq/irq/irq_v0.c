#include <linux/module.h>
#include <linux/init.h>

#include <linux/gpio/consumer.h>

#include <linux/interrupt.h>
#include <linux/timer_types.h> 

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MPCoding - LDD");
MODULE_DESCRIPTION("GPIO IRQ Example");

static const char *device_name = "gpio_ctrl";

#define LED_GPIO 21
#define BUTTON_GPIO 20

#define GPIO_OFFSET 512

static int led_gpio = (LED_GPIO + GPIO_OFFSET);
static int button_gpio = (BUTTON_GPIO + GPIO_OFFSET);

static struct gpio_desc *led, *button;

/* Variable contains iqr number */
unsigned int irq_number;

/* debounsing */
#define DEBOUNCE_DELAY 20 // 20ms

static int last_button_state;
static struct timer_list debounce_timer;

/* GPIO ISR */
static irqreturn_t button_isr(int irq, void *dev_id){
    pr_info("%s: Interrupt occoured on GPIO 20\n", device_name);

        last_button_state = gpiod_get_value(button);
    
    mod_timer(&debounce_timer, jiffies + msecs_to_jiffies(DEBOUNCE_DELAY));
    
    return IRQ_HANDLED;
}

static void debounce_timer_callback(struct timer_list *t){
    int state = gpiod_get_value(button);
    pr_info("%s: Valid button press detected\n", device_name);
    gpiod_set_value(led, !gpiod_get_value(led));
}

static int __init my_init(void) {
    int status;

    led = gpio_to_desc(led_gpio);
    if(!led){
    _err("%s: unable gpio_to_desc led_gpio 21\n", device_name);
    turn -1;
    
    
    button = gpio_to_desc(button_gpio);
    !button){
    _err("%s: unable gpio_to_desc button_gpio 20\n", device_name);
    turn -1;
    
    
    status = gpiod_direction_output(led, 0);
    if(status){
        pr_err("%s: Failed to set gpio 20 led direction\n", device_name);
        return -status;
    }
    
    status = gpiod_direction_input(button);
    if(status){
        pr_err("%s: Failed to set gpio 21 button direction\n", device_name);
        return -status;
    }
     
    irq_number = gpiod_to_irq(button);

    status = request_irq(irq_number, button_isr, IRQF_TRIGGER_FALLING, "btn_irq_handler", NULL);
    if(status){
        pr_err("%s: IRQ request failed\n", device_name);
        return -status;
    }
    pr_info("%s: irq_number=%d \n", device_name, irq_number);

    timer_setup(&debounce_timer, debounce_timer_callback, 0);

    pr_info("%s: GPIO request example loaded\n", device_name);

    return 0;
}

static void __exit my_exit(void){
    gpiod_set_value(led, 0);
    free_irq(irq_number, NULL);
    del_timer_sync(&debounce_timer);
    pr_info("%s: Goodbye Kernel\n", device_name);
}

module_init(my_init);
module_exit(my_exit);