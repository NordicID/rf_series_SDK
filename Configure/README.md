## RF601 Base station ethernet interface

The RF601 base station can communicate with host using built-in ethernet interface

Setting up ethernet module:

-   Install Digi PortAuthority Remote tool  [(download link)](http://applicationserver.nordicid.com/808Web/Tools/40002187_G.exe)
-   Connect RF601 base stations to LAN
-   Run Digi Port Authority - Remote tool
-   Discover devices
-   Select founded device and press Configure...
-   Web page opens (if not open, check your proxy settings)
-   Default username:  **root**  Password:  **dbps**
-   Set Configurations:  
    Serial Ports-->Profile:  **TCP Sockets**  
    Basic serial settings-->  **19200, 8 ,n ,1 ,None**  
    Advanced Serial settings--> Check: "**Send data only under any of the following conditions**"  
    Advanced Serial settings--> Check: "**Send after the following number of idle milliseconds**" Edit:  **5 ms**
-   Press "apply" button after value change.
-   Change "**Port profile settings**" as wanted. (TCP Server settings or TCP Client settings)
-   Change Network settings as wanted. (DHCP is on by default)
-   **Reboot**  device after changes

Default port when eth module works as a TCP Server:  **2101**  
  
Note: Proxy settings, Firewall settings  
  
More information:  [DigiOne module users guide](http://applicationserver.nordicid.com/808Web/Tools/prd_ds_digiconnectfamily_usersguide.pdf)

------------------------------------------------------------------------------

Restoring IP address to correct range

If IP address of Ethernet module is outside of LAN IP-range, web configuration is not possible.

Changing IP address by using  [Digi Device Setup Wizard](http://applicationserver.nordicid.com/808Web/Tools/40002319_K.exe)  program:

-   Connect RF601 base stations to LAN
-   run Digi Device Setup Wizard program and follow instruction
-   after changing correct IP address, web configuration is possible again.

