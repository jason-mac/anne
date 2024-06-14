"""
Testing script
"""

import os
import subprocess


def test():
    """
    test function
    """
    current_directory = os.getcwd()
    test_files_path = os.path.join(current_directory, "Samples")
    test_files = os.listdir(test_files_path)
    subprocess.run(["make"], shell=True, check=True)
    for i, file in enumerate(test_files):
        print("Running test " + str(i + 1) + "...")
        test_file_path = os.path.join(test_files_path, file)
        try:
            with open(test_file_path, "r", encoding="utf-8") as read_file:
                output = read_file.read().strip()
                print(output, end=" = ")
                result = subprocess.run(
                    ["./infixeval < Samples/" + file],
                    shell=True,
                    check=True,
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True,
                )
                actual_result = result.stdout.strip()
                print(actual_result)
            print()
        except FileNotFoundError:
            print("File not found.")
        except IOError:
            print("Error reading the file")


if __name__ == "__main__":
    test()
