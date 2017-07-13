#!/usr/bin/python
from scapy.all import *

init_sport=50100
init_dport=80
init_seq=100
m=1

try:
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr(a)
    b[0].show();
    #c=IP(dst="10.0.2.112")/TCP(sport=50000, dport=80, flags=0x1, seq=a_seq+1, ack=b[0].seq+1)
    c=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x4, seq=b[0].ack, ack=b[0].seq)
    d=sr(c)
    d[0].show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


try:
    init_sport+=100
    init_seq+=100
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr(a)
    b[0].show();
    #c=IP(dst="10.0.2.112")/TCP(sport=50000, dport=80, flags=0x1, seq=a_seq+1, ack=b[0].seq+1)
    c=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x14, seq=b[0].ack, ack=b[0].seq)
    d=sr(c)
    d[0].show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


try:
    init_sport+=100
    init_seq+=100
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr(a)
    b[0].show();
    c=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x1, seq=b[0].ack, ack=b[0].seq)
    d=sr(c)
    d[0].show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


try:
    init_sport+=100
    init_seq+=100
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr(a)
    b[0].show();
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x11, seq=b[0].ack, ack=b[0].seq)
    d=sr(c)
    d[0].show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


try:
    init_sport+=100
    init_seq+=100
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr(a)
    b[0].show();
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x4, seq=b[0].ack+1, ack=b[0].seq+1)
    d=sr(c)
    d[0].show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


try:
    init_sport+=100
    init_seq+=100
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr(a)
    b[0].show();
    c=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x14, seq=b[0].ack+1, ack=b[0].seq+1)
    d=sr(c)
    d[0].show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


try:
    init_sport+=100
    init_seq+=100
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr(a)
    b[0].show();
    c=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x1, seq=b[0].ack+1, ack=b[0].seq+1)
    d=sr(c)
    d[0].show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


try:
    init_sport+=100
    init_seq+=100
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr(a)
    b[0].show();
    c=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x11, seq=b[0].ack+1, ack=b[0].seq+1)
    d=sr(c)
    d[0].show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


