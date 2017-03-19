#### self implement of nonblocking dns query based on muduo 

* use udp to communicate with local dns server 
* support nonblocking dns query
* use time wheel to deal with expired data 

> this is the play toy I made to make deeper understand of dns protocol 

### warning
this project may only support Ubuntu or other systems that install dnsmasq. as showed below, this is the netstat print out of my pc:

```
 netstat -apn | grep 53

tcp        0      0 127.0.1.1:53            0.0.0.0:*               LISTEN      1390/dnsmasq    
udp        0      0 127.0.1.1:53            0.0.0.0:*                           1390/dnsmasq    
```
