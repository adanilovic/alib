#!/usr/bin/env python

import os
import errno
import subprocess
import argparse

def print_fail_banner():

    print '---------------------------'
    print '----------Failure----------'
    print '---------------------------'

def print_success_banner():

    print '---------------------------'
    print '----------Success----------'
    print '---------------------------'

def main():

    parser = argparse.ArgumentParser()
    parser.add_argument('--build-type', help='Specify Built Type',
                        action='store', default='Debug', choices=['Release',
                                                                  'Debug'])
    parser.add_argument('--unit-tests', help='Build all code for unit tests',
                        action='store_true')
    parser.add_argument('--graph-depend', help='Generate graph of dependencies',
                        action='store_true', default='False')
    args = parser.parse_args()

    try:
        os.makedirs('build')
    except OSError:
        if not os.path.isdir('build'):
            raise

    os.chdir('build')

    graph_depend = ''
    if args.graph_depend == True:
        graph_depend = '--graphviz=alib.graph'

    ret = subprocess.call(['cmake', graph_depend,
                           '-DUNIT_TESTS=' + str(args.unit_tests),
                           '-DBUILD_TYPE=' + str(args.build_type),
                           '-DGRAPH_DEPENDENCIES=' + str(args.graph_depend),
                           '../'])
    if ret != 0:
        print_fail_banner()
    else:
        print_success_banner()

    ret = subprocess.call(['make', 'VERBOSE=1'])
    if ret != 0:
        print_fail_banner()
    else:
        print_success_banner()

if __name__ == '__main__':
    main()
