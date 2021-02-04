#!/bin/python3
import urllib.request
import sys


def progress(block, blockSize, totalSize):
    print("%u%%" % (block * blockSize * 100 / totalSize))


def download(url, path):
    #try:
    urllib.request.urlretrieve(url, path, progress)
    #except :
    #    print("download fail")
    print("dowload %s to %s success!!!" % (url, path))

def main():
    download(sys.argv[1], sys.argv[2])

if __name__ == "__main__":
    main()