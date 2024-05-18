# testing friendsbook app
import os
import subprocess


def run_command():
    current_directory = os.getcwd()
    subprocess.run(["make clean"], cwd=current_directory, shell=True)


run_command()
