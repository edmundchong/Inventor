## Rat Daily Instructions 

### Setting Up Rat Daily 
1. Create a rat daily environment with conda forge rat-daily 

### Shaping Steps
- The stages a rat goes through when learning the task are as follows:
    1.     0_port :
    2.     1_randomsnout :
    3.     2_fixsnoutonly:
    4.     3_fixshrink :
    5.     4_fixlargecue OR 4x_fixlargecue :
    6.     5_fixcueshrinkstrict OR 5x_fixcueshrinkstrict :
    7.     7_fixdur OR 7x_fixdur :
    8.     10_WM OR 10x_WM :

### Task Variations
- After 3_fixshrink, the task can diverge into two modes:
    1.     4_fixlargecue :
    OR
    1.     4x_fixlargecue :

- The standard version of the task is **4_fixlargecue**. In this version, the stick remains **static**, and the location of the circle moves along the stick. This means for every trial, the stick is in the same location and the location of the circle will change.
- The alternative version of the task is the **4x_fixlargecue**. In this version, the stick **moves**, and the location of the circle also moves along the stick. This means for every trial, both the location of the stick and the circle will change
- If you select to train a rat on the standard version, make sure *stickmove_mode = false*. For the X version of the task, make sure *stickmove_mode = true*.
- If an animal is on the X version of the task, all steps from step 4 to 10 should follow the X naming of the task (ie 4x -> 5x -> 7x -> 10x)

### Progessing Behaviour - An Outline of the Parameters

![Params outline](https://github.com/edmundchong/Inventor/blob/main/Touchscreen%20arena/Rat%20Daily%20Instructions/images/Params_instructions.JPG)
![Params_outline_pt2](

### Troubleshooting
