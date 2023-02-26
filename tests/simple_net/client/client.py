import socket
import sys

from struct import pack
import struct
import ctypes

HOST, PORT = "127.0.0.1", 8080
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.connect((HOST, PORT))

msg = "hello from python! smoke detected on floor 1 room 2"
msg = msg.encode()
messageLen = len(msg)
totalLen = messageLen + 4
id = 1234568

str = struct.pack(f'>qi{messageLen}s', totalLen, id, msg)
print(str)
s.send(str)