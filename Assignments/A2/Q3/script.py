import os
import subprocess


# algortihm, get the apporiate files to run
def test():
    current_directory = os.getcwd()
    files = os.listdir(current_directory + "/Samples")
    subprocess.run(["make"], shell=True, check=True)
    for i, file in enumerate(files):
        print("Running test " + str(i + 1) + "...")
        with open(current_directory + "/Samples/" + file, "r") as read_file:
            print(read_file.read() + "= ", end="")
        subprocess.run(["./infixeval < Samples/" + file], shell=True, check=True)
        print()


if __name__ == "__main__":
    test()
