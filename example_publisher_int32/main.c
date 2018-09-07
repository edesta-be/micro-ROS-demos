#include <rclc/rclc.h>
#include <std_msgs/msg/int32.h>

#include <stdio.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    rclc_init(0, NULL);
    rclc_node_t* node     = rclc_create_node("publisher_node", "");
    rclc_publisher_t* publisher = rclc_create_publisher(node, RCLC_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), "publisher_example", 1);

    std_msgs__msg__Int32 msg;
    msg.data = -1;

    while (rclc_ok())
    {
        printf("Sending: '%i'\n", msg.data++);       
        rclc_publish(publisher, (const void*)&msg);
        rclc_spin_node_once(node, 500);
    }
    rclc_destroy_publisher(publisher);
    rclc_destroy_node(node);
    return 0;
}