"""
Pulling script
"""

import os
import subprocess


def run():
    """
    run function
    """
    try:
        subprocess.run(["make", "clean"], check=True)
        subprocess.run(["git", "pull"], check=True)
        subprocess.run(["make", "all"], check=True)
    except subprocess.CalledProcessError as e:
        print(f"An error occurred: {e}")


if __name__ == "__main__":
    run()
