import socket
import sys

from struct import pack
import struct
import ctypes

HOST, PORT = "127.0.0.1", 8080

def InitConnection():
    
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((HOST, PORT))

    return client

import random

#id is taken from data base where a number (range 1 - 4)
#is represented by a string
#therefore use only an id in this range
def SimulateSensor():

    return random.randint(1,4)

sensorsMap = {    
    2 : "===> python sensor: badge request",
    3 : "===> python sensor: motion detected",
    4 : "===> python sensor: temperatue sensor",
    1 : "===> python sensor: smoke detected on floor 1 room 2"
}

client = InitConnection()

import time

while True:

    id = SimulateSensor()
    msg = sensorsMap[id]
    messageLen = len(msg)
    totalLen = messageLen + 4 #4 bytes for id

    #explenation below
    packedMsg = struct.pack(f'<QI{messageLen}s', totalLen, id, msg.encode())

    client.send(packedMsg)

    time.sleep(2)


# pack data as bytes:
# < - little endian
# Q Unsigned long long
# I Unsigne int
# s char[]
# encode() - creates a bytes array of chars

    
