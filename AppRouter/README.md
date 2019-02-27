## RF6xxAppRouter

The RF6xx Application Router is a PC Windows application which routes hand
terminal messages to the specified host application. Also it handles several functions
that system integrator doesn’t have to implement in the host application.

The RF6xxAppRouter helps system developers who don’t want to use PLServer in
their business application. Usually, it is quite hard programming job for the non
PLServer developer to implement roaming, resend handling, crc checking and other
functionalities that AppRouter (PLServer) already has.

In some cases, there is need to use separate host applications but still use same base
stations. The RF6xxAppRouter generates main menu of available host applications in
to the hand terminal screen. The user of the hand terminal can select host application
from the menu. The Application Router and the remote host applications are
connected together using TCP/IP connection.

### Version History

##### Version 3.0.0
- Change Registry storing address from HKEY_LOCAL_MACHINE to HKEY_CURRENT_USER