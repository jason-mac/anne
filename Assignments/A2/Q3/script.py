import os
import subprocess


def test():
    current_directory = os.getcwd()
    files = os.listdir(current_directory + "/Samples")
    subprocess.run(["make"], shell=True, check=True)
    for i, file in enumerate(files):
        print("Running test " + str(i + 1) + "...")
        with open(current_directory + "/Samples/" + file, "r") as read_file:
            output = read_file.read()
            output += "= "
            print(output, end="")
            subprocess.run(["./infixeval < Samples/" + file], shell=True, check=True)
        print()


if __name__ == "__main__":
    test()
