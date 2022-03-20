#encoding=utf-8
import os
import sys
import shutil

def mv_large(root):
    root_dirs = os.listdir(root)
    for entry in root_dirs:
        path = os.path.join(root, entry)
        if os.path.isdir(path):
            size = -1
            max_nm = ""
            tmp = os.listdir(path)
            for t in tmp:
                p = os.path.join(path, t)
                if os.path.isfile(p) and os.path.getsize(p) > size:
                    size = os.path.getsize(p)
                    max_nm = p
            if max_nm:
                try:
                    shutil.move(max_nm, root)
                except e:
                    print(e)
                
            shutil.rmtree(path)

def main():
    root = sys.argv[1]
    print("Root directory is %s" % root)
    mv_large(root)

if __name__ == '__main__':
    main()


