#!/usr/bin/env python3.6

# Example 1
print([x**3 for x in range(100,200) if (x%2)==1])

# Example 2
print(','.join([str(x**3) for x in range(100,200) if (x%2)==1]))

# Example 3
from scapy.all import *
from scapy.sendrecv import *

# 传统的 ping 扫描，基于 ICMP 协议
ans,unans = sr(IP(dst="172.16.2.1-15")/ICMP(), timeout=1)
# 局域网扫描，基于 ARP 协议
ans,unans = srp(Ether(dst="ff:ff:ff:ff:ff:ff")/ARP(pdst="172.16.2.0/28"), timeout=1)
