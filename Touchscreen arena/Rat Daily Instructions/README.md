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

### Task Variations - 10_WM and 10x_WM
- After 3_fixshrink, the task can diverge into two modes:
    1.     4_fixlargecue (continuing then to 10_WM)
    OR
    1.     4x_fixlargecue (continuing then to 10x_WM)

- The standard version of the task is **10_WM**. In this version, the stick remains **static**, and the location of the circle moves along the stick. This means for every trial, the stick is in the same location and the location of the circle will change.
- The alternative version of the task is the **10x_WM**. In this version, the stick **moves**, and the location of the circle also moves along the stick. This means for every trial, both the location of the stick and the circle will change
- If you select to train a rat on the standard version, make sure *stickmove_mode = false*. For the X version of the task, make sure *stickmove_mode = true*.
- If an animal is on the X version of the task, all steps from step 4 to 10 should follow the X naming of the task (ie 4x -> 5x -> 7x -> 10x)

### Progessing Behaviour - An Outline of the Parameters
- Progression through the stages is not automatic, and has to be updated regularly. The images below describe the general functions of the parameters, which can be modified using the rat params GUI.
- After making changes, the parameters should be pushed to GitHub and then pulled on the secret 172 computer

![Params outline](https://github.com/edmundchong/Inventor/blob/main/Touchscreen%20arena/Rat%20Daily%20Instructions/images/Params_instructions.JPG)
![Params_outline_pt2](https://github.com/edmundchong/Inventor/blob/main/Touchscreen%20arena/Rat%20Daily%20Instructions/images/params_instructions_2.JPG)

### Troubleshooting
1. Results graphs are not showing up in rat daily
   - Check the data exists on the local rig computer for that animal. If there is a results folder, check inside that it is not empty. If it is empty, the data did not get recorded for that day
   - If the data exists locally, check that it has been copied to ceph. Common issues it is not in ceph: 1. Ceph has been logged out or 2. Robocopy got interrupted. In either case, make sure ceph is logged back in and re-run robocopy
   - The data has not been processed yet. If the above issues have been addressed, check with Edmund to make sure data is being processed. 
    -  
