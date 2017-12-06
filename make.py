#!/usr/bin/env python

import os
import errno
import subprocess
import argparse

def print_fail_banner():

    print "---------------------------"
    print "----------Failure----------"
    print "---------------------------"

def print_success_banner():

    print "---------------------------"
    print "----------Success----------"
    print "---------------------------"

def main():

    parser = argparse.ArgumentParser()
    parser.add_argument("--unit-tests", help="Build all code for unit tests",
                        action="store_true")
    args = parser.parse_args()

    try:
        os.makedirs('build')
    except OSError:
        if not os.path.isdir('build'):
            raise

    os.chdir('build')
    ret = subprocess.call(['cmake', '-DUNIT_TESTS=' + str(args.unit_tests), '../'])
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
