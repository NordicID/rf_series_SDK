## ActiveX Control (PLServer.ocx)
- for host application development
- for registering PLServer.ocx, see PLServer registration.pdf 

### Version History
##### Version 7.1.4
- Change Registry storing address from HKEY_LOCAL_MACHINE to HKEY_CURRENT_USER

##### Version 7.1.2
- Fixed ClearSendBuffer bug where FRAME_SEND flag was set.
- Optimized Mutex Lock and Unlock usage
- Fixed logging messages (Resend:COM..)

##### Version 7.1.1
- Fixed StopServer bug. Application may crash when closing client connections

##### Version 7.0.9
- Fixed bug: RouteToApp Mutex stays lock and newer unlocked is certain situations
- Optmimized speed for remote host connections
- Optimized Mutex Lock and Unlock usage

##### Ver 7.0.7
- Fixed: Double message filter. Filter based on different CRC and timespan did not work correctly.
- Added Log information about BS IP address when “Resend” happens. This helps to find badly behave base stations from site.
- Added automatic reconnecting to remote host if no answer within 10 sec. (used mainly at RF6xxAppRouter program).

##### Ver 7.0.2
- Added rule for preventing double messages
