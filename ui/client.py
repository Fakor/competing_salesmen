import socket
import sys
import os
import json

HOST = '127.0.0.1'
PORT = 1024

def main():
    while True:
        command = input('Enter command: ')
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((HOST, PORT))
            s.send(command.encode())
            data = s.recv(1024)
            data = data.decode("utf-8")
            data = json.loads(data)
            print(data)
            s.close()

def exit_program():
    sys.exit()

if __name__ == "__main__":
    main()