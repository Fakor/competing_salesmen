import socket
import sys
import os
import json

DEFAULT_HOST = '127.0.0.1'
DEFAULT_PORT = 1024

class Client:
    def __init__(self, host=DEFAULT_HOST, port=DEFAULT_PORT):
        self.host=host
        self.port=port

    def transceive(self, command):
        print(command)
        command = json.dumps(command)
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
            s.connect((self.host, self.port))
            s.send(command.encode())
            data = s.recv(102400)
            data = data.decode("utf-8")
            print("Data received: ", data)
            data = json.loads(data)
            s.close()
        return data

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
