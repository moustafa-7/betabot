# Betabot Moving in Square

- [Betabot Moving in Square](#betabot-moving-in-square)
  - [Project Description](#project-description)
  - [GUIDE](#guide)
  - [After you implement the pkg state your reflection below](#after-you-implement-the-pkg-state-your-reflection-below)
    - [How did you plan the task?](#how-did-you-plan-the-task)
    - [What ROS REPs did you used?](#what-ros-reps-did-you-used)
    - [How we could increase the overall performance?](#how-we-could-increase-the-overall-performance)
    - [List the most time consuming problems you faced](#list-the-most-time-consuming-problems-you-faced)
  - [Demo](#demo)
  - [Screenshot](#screenshot)
      - [NAME:](#Moustafa Elsayed)
      - [ID:](#id)

## Project Description 

Create a ROS package with custom service/action c++/python to move the betabot in gazebo, the movement
triggered will have to be a square, like in the image below:
Betabot movement Use the data passed to this topic /move_betabot_in_square_custom to change the way
betabot moves. Depending on the side value, the service must move the robot in a square
movement based on the side given. Also, the robot must repeat the shape as many times as
indicated in the repetitions variable of the message. Finally, it must return True if everything
went OK in the success variable.


## GUIDE

1. Create a new launch file, called start_betabot_move_custom_service_server.launch,
that launches the new betabot_move_custom_service_server.py file.
2. Test that when calling this new /move_betabot_in_square_custom service, betabot
moves accordingly. This means, the square is performed taking into account the side
and repetitions variables.
3. Create a new service client that calls the service /move_betabot_in_square_custom,
and makes betabot moves in a small square twice and in a bigger square once.
It will be called betabot_move_custom_service_client.py. The launch that starts it will
be called call_betabot_move_in_square_custom_service_server.launch.
4. Refer to this tutorial for more help.
The BetabotCustomServiceMessage.srv will be something like this:

```sh
float64 side # The distance of each side of the square
int32 repetitions # The number of times the betabot robot has to execute the square
movement when the service is called
---
bool success # Did it achieve it?
```

>NOTE: The side variable doesn’t represent the real distance along each size of the square.It’s just a variable that will be used to change the size of the square. The bigger the size variable is, the bigger the square performed by the robot will be. You can use any robot pkg.

>To make you project standout try another shape and to use filtered `odemtry` data.

---

## After you implement the pkg state your reflection below

### How did you plan the task?

- Ask the user for the number of repetitions and sides.
- loop 4*repetitions side. in each loop I check how far I moved and I compare it the length of the side
  - if it is almost equal it is time to rotate 90 degrees (in radians)
- Rotate 90 degrees and if so then stop rotating and move forward.

### What ROS REPs did you used?

-  ave used the naming conventions in the variables.
- I have used the conventional file sturcture.

### How we could increase the overall performance?

- use Actions instead of service

### List the most time consuming problems you faced

- Just didn’t know that angles are from -pi to pi not from 0 to pi

---

## Demo
Add unlisted youtube/drive video

[Demo](https://youtu.be/SQG1vZMbusE)

## Screenshot

[image]()![image-20200506212517727](/home/mostafa-7/.config/Typora/typora-user-images/image-20200506212517727.png)

![image-20200506212640288](/home/mostafa-7/.config/Typora/typora-user-images/image-20200506212640288.png)

---

#### NAME: Moustafa Elsayed
#### ID: 201600848

---
