# Setting Up New Behavioural Rigs

## Computer details 
- Computer Model:
- Set up Akrami Lab account with no password (the username must be **akramilab**, otherwise there'll be errors with bonsai paths)
- Make sure to disable automatic power off in settings
- Pin the following programs to taskbar, after installation
    - On-screen keyboard
    - Bonsai
    - AnyDesk
    - GitHub
    - Notepad++
    - File Explorer

## Step 1: Install new graphics card onto PC (for SLEAP)
- **Component**: MSI GeForce RTX 3050 VENTUS 2X XS 8G OC Gaming Graphics Card - 8GB GDDR6, 1807 MHz, PCI Express Gen 4 x 8, 128-bit, 1x DP v 1.4a, HDMI 2.1 (Supports 4K)
- **Supplier**: Amazon
- **Link**: https://www.amazon.co.uk/MSI-GeForce-VENTUS-Gaming-Graphics/dp/B09Y57F1HL/ref=sr_1_2?crid=3NK47LHCD5K2H&dib=eyJ2IjoiMSJ9.unfiKg5I-c2qR4zqk2W0sSWRVkGetXowW0F4WvpSjLNHAhDcp0GbsBw0we0VKWMuzsszBKpkWFq11VC5gTDXQA_3XPaa-rd-GhDbN6wf3NVONFQANMrn72D8ZJ2LALzFPRsxqwKQQUfskGwwzbWbYVlX22BMTrxC7Rk5x4EKKhM1zN4FofgpL84B3oHs4gykhDSNqWvmZxgaoBEt11aenKw5CqP-ahwbQUHyHadwOSE.BNtm8D6VV0duSwYg_77AiBXlkaIYPbisk6LQq4dlnKc&dib_tag=se&keywords=geforce%2Brtx%2B3050%2Bventus%2B2x&qid=1747138659&sprefix=geforce%2Brtx%2B3050%2Bventus%2B2x%2Caps%2C70&sr=8-2&th=1

### Instructions 
1. Open PC and remove covers
2. Press down on blue lock to release the old graphics card
3. Replace with new graphics card
4. Run PC to make sure the graphics card is recognised in Device Manager (full name of card should be listed)

## Step 2: Install serial port / PS2 connector (for touchscreen)
- **Component**: Adaptateur HP PCIe interne vers 2x ports PS/2, Série DB9
- **Supplier**: Amazon
- **Link**: https://www.amazon.co.uk/dp/B077YLQGGR

### Instructions 
1. Unscrew and remove old metal backing from the connector, and replace with the longer version that fits onto the PC
2. Connect to the PCI port located on the left of the graphics card

## Step 3: Install 4 port PCI express (for cameras)
- **Component**: StarTech.com 4 Port USB A PCIe USB 3.0 Card, **PEXUSB3S44V** (RS 138-3565)
- **Supplier**: RS
- **Link**: https://uk.rs-online.com/web/p/usb-cards/1383565?cm_mmc=UK-PLA-DS3A-_-google-_-CSS_UK_EN_PMAX_LowROAS_L2-_--_-1383565&matchtype=&&gad_source=1&gad_campaignid=22339197244&gbraid=0AAAAADkeWNPdFbAoA3tX9sAl9m-G-bsW3&gclid=CjwKCAjw24vBBhABEiwANFG7y3MChdZIT123CBEqtmVuPkxZq3Q2qDakrEDiBPYrW5Cja-kL7sHb5hoCLDYQAvD_BwE&gclsrc=aw.ds

### Instructions 
1. Insert card to the PCI port located on the right of the graphics card

## Step 4: Install AnyDesk 
- After downloading AnyDesk, you **must install it as a windows service**, otherwise you'll run into remote access issues when the computer restarts
- In the newest version of AnyDesk, "Install AnyDesk" can be found on the home page, as a red news pop up. Follow instructions on the pop up to install
- Set the permissions as "unattended", and set up security so only specific computer IDs can remote access.
- Make sure wake on LAN is enabled
- Set up AnyDesk so you can access it from your desk PC

## Step 5: Set up access to CEPH
- Map network drive -> type in directory for ceph (you can find it on file explorer, on a computer that already has ceph)
- The directory is as follows :

- \\ceph-gw02.hpc.swc.ucl.ac.uk\akrami

## Step 6: Access ceph -> Edmund -> software for 172 rigs
- Copy all of the files in this location, and paste locally to your downloads folder
- Install all of the files individually (use default settings for all the installations)

## Step 7: Install Bonsai packages and extensions

- Open Bonsai in an already running rig -> manage packages
- Install all of the same packages on the new rig you're setting up :
  
    1. Bonsai

    2. Bonsai.Arduino
 
    3. Bonsai.Audio
 
    4. Bonsai.Core
 
    5. Bonsai.Design
 
    6. Bonsai.Design.Visualizers
 
    7. Bonsai.Dsp
 
    8. Bonsai.Dsp.Design
 
    9. Bonsai.Editor
 
    10. Bonsai.Gui
 
    11. Bonsai.Numerics
 
    12. Bonsai.Osc
 
    13. Bonsai.Scripting
 
    14. Bonsai.Scripting.Expressions
 
    15. Bonsai.Scripting.Expressions.Design
 
    16. Bonsai.Scripting.IronPython
 
    17. Bonsai.Scripting.IronPython.Design
 
    18. Bonsai.Shaders
 
    19. Bonsai.Shaders.Design
 
    20. Bonsai.Shaders.Rendering
 
    21. Bonsai.Sleap
 
    22. Bonsai.Sleap.Design
 
    23. Bonsai.StarterPack
 
    24. Bonsai.System
 
    25. Bonsai.System.Design
 
    26. Bonsai.Vision
 
    27. Bonsai.Vision.Design
 
    28. Bonsai.VR
 
    29. Bonsai.Windows.Input
 
    30. IronPython
 
    31. IronPython.StdLib

- Navigate to software for 172 rigs on CEPH, and open the extensions folder. Copy all of the extensions in the folder
- Navigate to folder where Bonsai is installed on the new rig (right click on bonsai icon -> properties -> copy file path in "start in"). In this folder, you will find "Extensions". Paste all of the extensions from the ceph folder here. 

**! Note: When searching for the packages, use the *exact* ID for the package. The search is case sensitive, and will not give you an error if you've made a typo !**

## Step 8: Set up rat launcher 
- Get Edmund to log in to GitHub Desktop and clone the required repos from clamlab into C:Drive (**in the following order**) :

      1. Name of repo : Bonsai (local path destination -> C:\clamlab\bonsai)

      2. Name of repo: rig_params (local path destination -> C:\rig_params)

      3. Name of repo: rat-params (local path destination -> C:\rig_params\rat-params)

      4. Name of repo: SLEAP_networks (local path desination -> C:\clamlab\SLEAP_networks) **!Different to SLEAP repo!**

      5. Name of repo: Milker (local path destination -> C:\clamlab\milker)
  
- Navigate to C:\clamlab\bonsai\ratLauncher\dist
- Pin the icon to the start bar
- In C:Drive, create a "**Data**" folder (this must be its exact name, with cap sensitivity)
- In rig params folder (C:Drive), insert a random rat photo into "rat_photos" (this is to avoid an error later)
- AnyDesk into another rig and also copy over the "pushover" file in the rig params folder onto ceph, and then from there into the new computers rig params folder.
- Once copied to new computer C:Drive, delete the file from ceph

## Step 9: Connect all your hardware and run hardware testers
- Connect the lick, buzzer and valve to the computer
- Upload the .ino sketches (from clamlab/bonsai gitub) to each arduino
- Remember to change the COM ports in the rig params for each piece of hardware, to match the ones listed in the arduino software
- Run hardware tester (under C:\clamlab\bonsai\Touchscreen_pSWM_v02) to check all components work

## Step 10: Connect the touchscreen to the computer 
- Connect the power, HDMI and VGA cable from touchscreen -> PC
- Run nexio tester (C:\clamlab\bonsai\NexioTouch) to check the touchscreen is working and calibrated (touch the inside of the circles to make sure the pointer is accurate)

## Step 11: Set up cameras on bonsai 
- Double click on each of the cameras in hardware tester, and identify which are labelled 0, 1 and 2 on the right panel
- Edit the rig params in notepad++, so that "screencam" and "fixationsidecam" are labelled with the corresponding numbers on bonsai (0, 1 or 2)
- Top cam is different. Go to C:Drive -> rig params -> topcam module (bonsai)
- click on camera capture and change the index number to the corresponding number on the bonsai hardware tester (0,1 or 2)

## Step 12: Run the rat launcher
- Test that everything is working by running the rat launcher and going through all the calibration steps
  1. Check that the buzzers sound
  2. Check that the valve activates
  3. Check that the lick spout responds to touch
  4. Check that the trial commences
