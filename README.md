This projet is developed during Labs of the subject IoT Architecture

By:
Saif Hlaimi
Under-graduated students, 
Embadded system and IoT Bachelors


Under the supervision of:
Amira Henaien, 
Computer Science, Assistant Professor,
Higher Institute of Computer Science Mahdia(ISIMA),
University of Monastir Tunisia


Title of the project:
Smart Medical Band

Description:
In this project we gonna get the name ,the status of health and values of heart-rate of a patient and send it using peer to peer from an node LoRa to another LoRa node using LoRa techonologie and store this values to realtime Firebase and get the datas from the firebase to the website where the doctor can see the status of the patient and if there's somethings wrong in the health of the patient then the website show some messages to alert the doctor

Objectif:
measure the heart-rate and send it to firebase using LoRa techonologie

List of devices:
2 x esp32 , 2x LoRa SX1278 Ra-02 , MAX30102 , some Cables


Installation and prepartion instrcutions: 
first off , we must connect each LoRa to the esp32 modules by using the cables and here is the installation of each pin:

Lora pins :  esp32 pins 
rst       : 4
dio0      : 17 
ss        : 15
mosi      : 23
miso      : 19
sck       : 18
gnd       : gnd
vcc       : 3volt
then we must connect the MAX30102 to the esp32 that send the data to the LoRa receiver.
After this we must create the webiste and the firebase , i created the website using the html ,css and javascript and vs code as editor. If the firebase and the website are created , then we must upload the code that writed with C in Arduino IDE to the esp32 modules after the verification of installation of all the devices is correct.
finally we test the project and we read the values from the website.
