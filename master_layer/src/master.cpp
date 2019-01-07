#include <ros/ros.h>

#include <gate.h>
#include <single_buoy.h>
#include <torpedo.h>
#include <marker_dropper.h>
#include <octagon.h>
#include <line.h>

#include <straight_server.h>
#include <move_sideward_server.h>
#include <move_forward_server.h>
#include <move_downward_server.h>

#include <actionlib/client/simple_action_client.h>

#include <motion_layer/anglePIDAction.h>
#include <motion_layer/rollPIDAction.h>
#include <motion_layer/pitchPIDAction.h>
#include <motion_layer/forwardPIDAction.h>
#include <motion_layer/sidewardPIDAction.h>
#include <motion_layer/upwardPIDAction.h>

#include <actionlib/client/terminal_state.h>
#include <std_msgs/String.h>
#include <task_handler.h>
#include <boost/thread.hpp>

using namespace std;

void spinThread() {
    ROS_INFO("Spinning");
    ros::spin();
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "master");
    ros::NodeHandle nh;
    ros::Publisher task_pub = nh.advertise<std_msgs::String>("/current_task", 1); 
    ros::Time::init();
    int pub_count = 0;
    std_msgs::String current_task;
    ros::Rate loop_rate(10);
    taskHandler th(15); // time out 15 seconds
    singleBuoy single_buoy;

    boost::thread spin_thread(&spinThread);

    moveSideward move_sideward(0);
    moveStraight move_straight(0);
    moveDownward move_downward(0);

    // Need to program for task failure and what to do when failed to detect something

    /////////////////////////////////////////////

    // ros::Duration(60).sleep();

    /*current_task.data = "red_buoy";
    while (ros::ok() && pub_count <= 5) {
        task_pub.publish(current_task);
        pub_count++;
        loop_rate.sleep();
    }
    pub_count = 0;
    nh.setParam("/current_task", "red_buoy");
    ROS_INFO("Current task: Red Buoy");
    
    single_buoy.setActive(true); // blocking function, will terminalte after completion 
    single_buoy.setActive(false);
    
    ROS_INFO("Completed the first buoy task, Now let's move on to the second");

    ///////////////////////////////////////////////

    current_task.data = "yellow_buoy";
    while (ros::ok() && pub_count <= 5) {
        task_pub.publish(current_task);
        pub_count++;
        loop_rate.sleep();
    }
    pub_count = 0;
    nh.setParam("/current_task", "yellow_buoy");
    ROS_INFO("Current task: Yellow Buoy");

    move_sideward.setThrust(-50);
    move_sideward.setActive(true);
    // ros::Duration(10).sleep();
    
    ROS_INFO("Finding Yellow Buoy....");
    if (!th.isDetected("yellow_buoy", 15)){
        ROS_INFO("Failed to detect yellow buoy");
        move_sideward.setActive(false);
        return 1;
    }
    
    ROS_INFO("Yellow Buoy Detected");
    move_sideward.setActive(false);

    single_buoy.setActive(true);
    single_buoy.setActive(false);

    ROS_INFO("Yellow Buoy done");*/
    
    //////////////////////////////////////////////

    // move_straight.setThrust(-50);
    // move_straight.setActive(true);
    // ros::Duration(7).sleep(); // configurable 
    // move_straight.setActive(false);

    // ROS_INFO("Finding Green Buoy...");
    // move_sideward.setThrust(50);
    // move_sideward.setActive(true); // until the green buoy is detected (for vision node)
    // // ros::Duration(8).sleep(); // configurable

    // if (!th.isDetected("green_buoy", 15)) {
    //     ROS_INFO("Unable to detect green buoy");
    //     move_sideward.setActive(false);
    //     return 1;
    // }

    // ROS_INFO("Green Buoy Detected");        
    // move_sideward.setActive(false);

    // current_task.data = "green_buoy";
    // while (ros::ok() && pub_count <= 5) {
    //     task_pub.publish(current_task);
    //     pub_count++;
    //     loop_rate.sleep();
    // }
    // pub_count = 0;
    // nh.setParam("/current_task", "green_buoy");
    // ROS_INFO("Current task: Green Buoy");

    // single_buoy.setActive(true); // blocking function, will terminalte after completion
    // single_buoy.setActive(false);

    // ROS_INFO("Green Buoy Done");
  
    ////////////////////////////////////////////////

    // ROS_INFO("Gate Task, going down"); // for gazebo only
    // move_downward.setActive(true);
    // ros::Duration(4).sleep();
    // move_downward.setActive(false);
    // ROS_INFO("Gate Task, at the bottom");

    /*ROS_INFO("Finding Gate ...");

    move_sideward.setThrust(50);
    move_sideward.setActive(true); // until gate is detected
    
    ros::Duration(5).sleep(); // time depends, better to have a node telling when the gate is detected

    move_sideward.setActive(false);

    ROS_INFO("Moving Straight");
    move_straight.setThrust(50);
    move_straight.setActive(true);
    
    ros::Duration(5).sleep();

    current_task.data = "gate_front";
    while (ros::ok() && pub_count <= 5) {
        task_pub.publish(current_task);
        pub_count++;
        loop_rate.sleep();
    }
    pub_count = 0;
    nh.setParam("/current_task", "gate_front");
    ROS_INFO("Current task: Front Gate");

    if (!th.isDetected("gate_front", 10)) {
        ROS_INFO("Not able to detect gate");
        move_straight.setActive(false);
        return 1;
    }

    move_straight.setActive(false);

    ROS_INFO("Gate Detected");*/

    // ROS_INFO("Moving straight ended");

    // nh.setParam("/disable_imu", true);

    // current_task.data = "line";
    // while (ros::ok() && pub_count <= 5) {
    //     task_pub.publish(current_task);
    //     pub_count++;
    //     loop_rate.sleep();
    // }
    // pub_count = 0;
    // nh.setParam("/current_task", "line");
    // ROS_INFO("Current task: Line");

    // move_straight.setThrust(50);
    // moove_straight.setActive(true);

    // if (!th.isDetected("line", 10)) {
    //     ROS_INFO("Line not detected before the timeout");
    //     move_straight.setActive(false)
    //     return 1;
    // }

    // move_straight.setActive(false);

    // ROS_INFO("Line Detected");

    // lineTask line;

    // if (!line.setActive(true)) {
    //     ROS_INFO("Line Task Failed");
    //     line.setActive(false);
    //     return 1;
    // }
    // line.setActive(false);

    // ROS_INFO("Completed the Line task");

    // nh.setParam("/disable_imu", false);

    gateTask gate_task;
    if (!gate_task.setActive(true)) {
        ROS_INFO("Gate Task Unsuccessful");
        gate_task.setActive(false);
        return 1;
    }
    gate_task.setActive(false);

    ROS_INFO("Gate Task Completed");

    // ///////////////////////////////////////////////////

    // Gate-Torpedo Transition

    // current_task.data = "green_torpedo";
    // while (ros::ok() && pub_count <= 5) {
    //     task_pub.publish(current_task);
    //     pub_count++;
    //     loop_rate.sleep();
    // }
    // pub_count = 0;
    // nh.setParam("/current_task", "green_torpedo");
    // ROS_INFO("Current task: Green Torpedo");

    // actionlib::SimpleActionClient<motion_layer::anglePIDAction> anglePIDClient("turnPID");
    // motion_layer::anglePIDGoal anglePIDGoal;

    // ROS_INFO("Waiting for anglePID server to start.");
    // anglePIDClient.waitForServer();

    // ROS_INFO("anglePID server started, sending goal.");

    // anglePIDGoal.target_angle = 60;
    // anglePIDClient.sendGoal(anglePIDGoal);

    // th.isAchieved(60, 2, "angle");

    // anglePIDClient.cancelGoal();

    // moveStraight move_straight(50);
    // move_straight.setActive(true);

    // ros::Duration(2).sleep();

    // move_straight.setActive(false);

    // th.isDetected("green_torpedo", 5);

    ///////////////////////////////////////////////////

    // Torpedo torpedo;

    // torpedo.setActive(true);
    // torpedo.setActive(false);

    ////////////////////////////////////////////////////

    // current_task.data = "red_torpedo";
    // while (ros::ok() && pub_count <= 5) {
    //     task_pub.publish(current_task);
    //     pub_count++;
    //     loop_rate.sleep();
    // }
    // pub_count = 0;
    // nh.setParam("/current_task", "red_torpedo");
    // ROS_INFO("Current task: Red Torpedo");

    // moveSideward move_sideward(100);
    // // move_sideward.setThrust(100);
    // move_sideward.setActive(true);

    // th.isDetected("red_torpedo", 5);

    // move_sideward.setActive(false);

    // torpedo.setActive(true);
    // torpedo.setActive(false);

    /////////////////////////////////////////////////////

    // Torpedo-MarkerDropper Transition

    // moveSideward move_sideward(-50);
    // move_sideward.setActive(true);
    // ros::Duration(1).sleep();
    // move_sideward.setActive(false);
    // moveStraight move_straight(-50);
    // move_straight.setActive(true);
    // ros::Duration(1).sleep();
    // move_straight.setActive(false);

    // nh.setParam("/enable_pressure", 1);
    // nh.setParam("/disable_imu", true);

    // current_task.data = "line";
    // while (ros::ok() && pub_count <= 5) {
    //     task_pub.publish(current_task);
    //     pub_count++;
    //     loop_rate.sleep();
    // }
    // pub_count = 0;
    // nh.setParam("/current_task", "line");
    // ROS_INFO("Current task: Line");

    // bool temp = th.isDetected("line", 10);

    // if (!temp) {
    //     ROS_INFO("Line not detected before the timeout");
    //     return 1;
    // }

    // ROS_INFO("Line Detected");

    // lineTask task;

    // temp = task.setActive(true);

    // if (!temp) {
    //     ROS_INFO("Line Task Failed");
    //     return 1;
    // }
    // task.setActive(false);

    // ROS_INFO("Completed the Line task");

    // nh.setParam("/enable_pressure", 1);
    // nh.setParam("/disable_imu", false);
    
    // After finishing torpedo task turn 120 degree anticlockwise and then move straight
    // ROS_INFO("Master layer, anglePID server started, sending goal."); 

    // anglePIDGoal.target_angle = -120;
    // anglePIDClient.sendGoal(anglePIDGoal);

    // th.isAchieved(-120, 2, "angle"); // wait till the bot has rotated 120 degrees

    // anglePIDClient.cancelGoal();

    // moveStraight move_straight(100);
    // move_straight.setActive(true);
    // ros::Duration(6).sleep();
    // move_straight.setActive(false);

    // /////////////////////////////////////////////////////

    // // MarkerDropper
    // current_task.data = "marker_dropper_front";
    // while (ros::ok() && pub_count <= 5) {
    //     task_pub.publish(current_task);
    //     pub_count++;
    //     loop_rate.sleep();
    // }
    // pub_count = 0;
    // nh.setParam("/current_task", "marker_dropper_front");
    // ROS_INFO("Current task: Marker Dropper Front");

    // th.isDetected("marker_dropper_front", 5);

    // actionlib::SimpleActionClient<motion_layer::sidewardPIDAction> sidewardPIDClient("sidewardPID");
    // motion_layer::sidewardPIDGoal sidewardPIDGoal;

    // ROS_INFO("Waiting for anglePID server to start.");
    // sidewardPIDClient.waitForServer();

    // ROS_INFO("anglePID server started, sending goal.");

    // sidewardPIDGoal.target_distance = 0;
    // sidewardPIDClient.sendGoal(sidewardPIDGoal);

    // move_straight.setActive(true);

    // // Until the bin is visible in the front camera

    // sidewardPIDClient.cancelGoal(); // dangerous

    // current_task.data = "marker_dropper_bottom";
    // while (ros::ok() && pub_count <= 5) {
    //     task_pub.publish(current_task);
    //     pub_count++;
    //     loop_rate.sleep();
    // }
    // pub_count = 0;
    // nh.setParam("/current_task", "marker_dropper_bottom");
    // ROS_INFO("Current task: Marker Dropper Bottom");

    // move_straight.setThrust(50);

    // th.isDetected("marker_dropper_bottom", 6);

    // move_straight.setActive(false);

    // MarkerDropper md;
    // md.setActive(true);
    // md.setActive(false);

    // /////////////////////////////////////////////////////

    // // Octagon

    // ROS_INFO("Waiting for anglePID server to start.");
    // anglePIDClient.waitForServer();

    // ROS_INFO("anglePID server started, sending goal.");

    // anglePIDGoal.target_angle = 60;
    // anglePIDClient.sendGoal(anglePIDGoal);

    // th.isAchieved(60, 2, "angle");

    // anglePIDClient.cancelGoal();

    // current_task.data = "octagon";
    // while (ros::ok() && pub_count <= 5) {
    //     task_pub.publish(current_task);
    //     pub_count++;
    //     loop_rate.sleep();
    // }
    // pub_count = 0;
    // nh.setParam("/current_task", "octagon");
    // ROS_INFO("Current task: Octagon");

    // move_straight.setActive(true);

    // th.isDetected("octagon", 10);

    // move_straight.setActive(false);

    // Octagon octagon;
    // octagon.setActive(true);
    // octagon.setActive(false);
    
    /////////////////////////////////////////////////////
   
    nh.setParam("/kill_signal", true);

    spin_thread.join();

    return 0;
}
