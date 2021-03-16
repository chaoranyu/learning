#!/usr/bin/env python3.9

# example 1
class Parent1 :
    def dump(self) :
        print("parent1")

class Parent2 :
    def dump(self) :
        print("parent2")

class Child :
    def dump(self) :
        print("child")

print(Child.__bases__)
Child.__bases__ += (Parent1, Parent2)  # 动态追加了2个父类
print(Child.__bases__)  # 此处打印出的父类信息中，已经包含 Parent1、Parent2
