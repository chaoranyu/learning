#!/usr/bin/python
from scapy.all import *

init_sport=50100
init_dport=80
init_seq=100
m=1

try:
    a=IP(dst="10.0.5.80")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr1(a)
    b.show();

    #c=IP(dst="10.0.5.80")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=b.ack-1)
    c=IP(dst="10.0.5.80")/TCP(sport=init_sport+100, dport=init_dport, flags=0x2, seq=b.ack+1000)
    d=sr1(c)
    d.show();

    e=IP(dst="10.0.5.80")/TCP(sport=init_sport, dport=init_dport, flags=0x14, seq=d.ack, ack=d.seq)
    f=sr1(e)
    f.show();

    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1
