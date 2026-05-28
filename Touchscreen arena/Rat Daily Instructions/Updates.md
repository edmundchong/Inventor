## Pending Updates - Rat Daily Automation 


1. Automatic ephys_mode = false if sleap network is 172 or 403_ephys_notether, and ephys_mode = true is sleap network is 403_ephys_tether 
2. Automatic stickmove_mode = true if animal is on X version of task
3. Set automatic starting parameters for each stage (aka if a rat has to revert to a previous stage, the parameters should automatically revert to default starting parameters on that stage OR revert to the last settings the rat had on that stage) 
3. Default lida_mode = true 
4. Automatically increment warm up trials by 10, to a maximum of 50 if the rat is doing >100 trials 5 days in a row 
5. Automatically increment WM delay periods by 0.1 if R value of performance is 0.4 or above, for 5 days in a row, up to a maximum value of WM = 1.0 and WM = 2.0
6. Automatically change FixationDur_pb to match last sessions PB (rounded up) in stage 4
6. Automatically change cue_D_hi to match last sessions PB (rounded up) in stage 5

### Progression of shaping stages (0 to 7) -> Option D probably the easiest: 

1. **Option A**: Automatically progress to next stage if final criteria for that stage are met 2 days in a row (ie if rat gets a specified percentage of trials correct, and the total number of trials is above 100)
2. **Option B**: Create a STATUS notification at the top of rat-daily, to notify you if a rat is a candidate for progression (aka STATUS = Stay in stage or STATUS = progress to next stage)
3. **Option C**: Create a STATUS notification with an action button (aka STATUS = progress to next stage -> CONFIRM). This will update all the parameters automatically, but must be manually confirmed  
4. **Option D**: When a rat has reached the final param in a shaping stage (ie maximum fixation duration reached, or final cue size reached etc), the stat_value is highlighted green (easier to spot, indicates stage should be progressed)

### Other useful features:

1. **Duration in stage**: Text at the top of rat daily which tells you how many days the animal has been in the current params config
2. **Date selector**: Option to select a range of dates to view results
3. **Animal age OR total training duration (ie days since first session)**: Makes it easier to track when an animal should be implanted (ie if an animal has been training for 1 year, it's probably reaching maximum age for surgery. Easier to see here than in pyrat)
4. **Average performance**: Takes an average of the R values in the last 2 weeks, to give summary overview of that animals recent performance. Quick snapshot view of strong vs weak rats overall 
