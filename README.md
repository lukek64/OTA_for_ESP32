# **How to setup**

1. Download all files.  
2. Replace your *platformio.ini* with the one in the repo.  
3. Change the IP address in *platformio.ini* with your ESP32’s IP address. It can be found on the **upload\_port** line.  
4. Create a new folder within your project named *tools*.   
5. Put *create\_project.py* and *tasks.json* in the *tools* folder you just created.  
6. In your *Documents* folder, create a new folder called *ESP32\_Libraries.* In *ESP32\_Libraries*, create a new folder named *OTAHelper.*  
7. Put the path of the *OTAHelper* in **lib\_deps** in the *platformio.ini* file*.*  
8. Put the following files from the repo in *OTAHelper:*  
   1. *library.json*  
   2. *OTAHelper.cpp*  
   3. *OTAHelper.h*  
9. You finished setting up the OTA\! Now follow the instructions for how to use.

# **How to use**

1. Make sure OTA is fully set up on your computer.  
2. MAKE SURE you are on the sesplearningstudios wifi or this WILL NOT WORK\!  
3. Include the OTA lib in the *main.cpp* file IN YOUR PROJECT by including the following, YOU MUST DO THIS FOR EVERY PROJECT:  
   1. Put \#include \<OTAHelper.h\> in your library section of your code.  
   2. Put setupOTA();  in your void setup().  
   3. Put handleOTA(); in your void loop().  
4. Replace the default *platformio.ini* with the custom one.  
5. If you want to do this faster, run the ESP32 project from the command palette, I will show you how to do this.

   

