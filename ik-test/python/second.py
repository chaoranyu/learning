#!/usr/bin/python
from scapy.all import *

init_sport=50100
init_dport=80
init_seq=100
m=1

try:
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr1(a)
    b.show();
    #c=IP(dst="10.0.2.112")/TCP(sport=50000, dport=80, flags=0x1, seq=a_seq+1, ack=b.seq+1)
    c=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x4, seq=b.ack, ack=b.seq)
    d=sr1(c)
    d.show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


try:
    init_sport+=100
    init_seq+=100
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr1(a)
    b.show();
    #c=IP(dst="10.0.2.112")/TCP(sport=50000, dport=80, flags=0x1, seq=a_seq+1, ack=b.seq+1)
    c=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x14, seq=b.ack, ack=b.seq)
    d=sr1(c)
    d.show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


try:
    init_sport+=100
    init_seq+=100
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr1(a)
    b.show();
    c=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x1, seq=b.ack, ack=b.seq)
    d=sr1(c)
    d.show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


try:
    init_sport+=100
    init_seq+=100
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr1(a)
    b.show();
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x11, seq=b.ack, ack=b.seq)
    d=sr1(c)
    d.show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


try:
    init_sport+=100
    init_seq+=100
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr1(a)
    b.show();
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x4, seq=b.ack+1, ack=b.seq+1)
    d=sr1(c)
    d.show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


try:
    init_sport+=100
    init_seq+=100
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr1(a)
    b.show();
    c=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x14, seq=b.ack+1, ack=b.seq+1)
    d=sr1(c)
    d.show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


try:
    init_sport+=100
    init_seq+=100
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr1(a)
    b.show();
    c=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x1, seq=b.ack+1, ack=b.seq+1)
    d=sr1(c)
    d.show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


try:
    init_sport+=100
    init_seq+=100
    a=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x2, seq=init_seq)
    b=sr1(a)
    b.show();
    c=IP(dst="10.0.2.112")/TCP(sport=init_sport, dport=init_dport, flags=0x11, seq=b.ack+1, ack=b.seq+1)
    d=sr1(c)
    d.show()
    print "\033[32mok: ", m, "\033[0m\n\n\n"
except:
    print "\033[31merror: ", m, "\033[0m\n\n\n"
m+=1


