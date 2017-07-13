#!/usr/bin/python
# -*- coding: utf-8 -*-

import http.client
import time

ISOTIMEFORMAT = "%Y-%m-%d %X"
n=0
p=0
f=open(r"http.txt","w+")
while True:
	try:
		timebegin=time.strftime(ISOTIMEFORMAT,time.localtime())
		print(timebegin)
		conn = httplib.HTTPConnection("10.0.2.14",timeout=3)
		print(time.strftime(ISOTIMEFORMAT,time.localtime()))
		conn.request("GET","http://10.0.2.14")
		r = conn.getresponse()
		m=r.read()
		print(m)
		p=p+1
		print("connet"+str(p))
		timestop=time.strftime(ISOTIMEFORMAT,time.localtime())
		print(timestop)
		print("http request ok")
	except:
		n=n+1
		f.write(timebegin+'\n')
		f.write(time.strftime(ISOTIMEFORMAT,time.localtime())+'\n')
		f.write(str(n)+'\n')
		print("cannot connect"+str(n))
	time.sleep(1)
f.close()
