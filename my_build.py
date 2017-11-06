#!/usr/bin/env python

import os
import errno
import subprocess

def print_fail_banner():

    print "---------------------------"
    print "----------Failure----------"
    print "---------------------------"

def print_success_banner():

    print "---------------------------"
    print "----------Success----------"
    print "---------------------------"

def main():
    try:
        os.makedirs('build')
    except OSError:
        if not os.path.isdir('build'):
            raise

    os.chdir('build')
    ret = subprocess.call(['cmake', '../'])
    if ret != 0:
        print_fail_banner()
    else:
        print_success_banner()

    ret = subprocess.call(['make', 'VERBOSE=1'])
    if ret != 0:
        print_fail_banner()
    else:
        print_success_banner()

if __name__ == "__main__":
    main()
