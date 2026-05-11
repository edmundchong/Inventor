## Updating Rats in Behavioural Set Up

### Step 1: Retire the old rats if needed 
- First, AnyDesk into the rig that the rat is running on. Remove the rat photo for the retired rat from the rat_photos folder. Make a note of the shift number prefix, and make sure the photo of the rat is backed up on ceph (under Audra/rat photo backup). The prefixes for shifts are as follows:
    - 2_ID = Shift 0
    - 3_ID = Shift 1
    - 4_ID = Shift 2
    - 5_ID = Shift 3

- Go into the rat_params folder, and delete the rat_params for the rat being retired. No need for this to be backed up

### Step 2: Add new rat
- Take a photo of the rat that is being added, or if the rat is microchipped, a JPG of a black background with the rat ID written on it is fine
- Add the photo to the rat photo backup folder on ceph
- AnyDesk into the rig that you want to add the new rat to
- Copy and paste the rat photo from ceph, to the local rat photo folder on the rig computer. Make sure to add the shift number prefix before the rat ID
- Go into the rat params folder on the rig computer.
- Copy the EC00 folder (template), and rename it to your new rats ID
- Go into the rat params editor folder on your local computer, and add the new rats to the config file (note that if the config file lists 'all' rats, then the new rats should be found automatically)
- Push rat params
- Run sparse checkout
