#!/usr/bin/env python3

"""
Quick and dirty unit testing script for competitive programs

Expected directory structure (to be run from within the problem's directory):
your_problem.txt  <- tests
your_problem.cpp  <- source code
your_problem      <- binary
"""

import argparse
import subprocess
import os
import glob

test_file_delim = "---"
test_file_answer_delim = ">"
test_case_delimiter = "==========="
# test_case_delimiter = "\n===========\n"


def infer_target():
    """Infer the make target (problem name) when omitted.

    Rules:
      1. If exactly one .cpp file exists, use its basename (minus extension).
      2. If multiple .cpp files and <dirname>.cpp exists, use <dirname>.
      3. Otherwise abort and require an explicit target (avoids wrong subtask builds).
    """
    cwd = os.getcwd()
    dirname = os.path.basename(cwd)
    cpp_files = sorted(glob.glob("*.cpp"))
    if not cpp_files:
        raise FileNotFoundError("No .cpp files found. Supply target explicitly.")
    if len(cpp_files) == 1:
        return os.path.splitext(cpp_files[0])[0]
    # multiple
    if f"{dirname}.cpp" in cpp_files:
        return dirname
    raise RuntimeError(
        "Multiple .cpp files found: "
        + ", ".join(cpp_files)
        + ". Specify target explicitly (e.g. ./test.py <name>)."
    )


def determine_test_file(target: str, explicit: str | None) -> str:
    """Determine which test file to use.

    If explicit provided (with or without .txt) and exists, use it.
    Otherwise test file is <base>.txt where base = target up to first underscore.
    """
    if explicit:
        candidate = explicit if explicit.endswith(".txt") else explicit + ".txt"
        if os.path.exists(candidate):
            return candidate
        raise FileNotFoundError(f"Specified test file '{candidate}' not found.")

    base = target.split("_")[0]
    candidate = base + ".txt"
    if os.path.exists(candidate):
        return candidate

    # final fallback: directory name if different
    dirname = os.path.basename(os.getcwd())
    alt = dirname + ".txt"
    if dirname != base and os.path.exists(alt):
        return alt
    raise FileNotFoundError(f"Could not find test file '{candidate}'.")


def parse_test_file(test_filename: str):
    test_cases = []
    input_buf = ""
    output_buf = ""
    is_input = True
    with open(test_filename, "r") as f1:
        for raw_line in f1.readlines():
            line = raw_line.strip()
            if line == test_file_delim:
                test_cases.append((input_buf, output_buf))
                input_buf = ""
                output_buf = ""
                is_input = True
            elif line == test_file_answer_delim:
                is_input = False
            else:
                if is_input:
                    input_buf += line + "\n"
                else:
                    output_buf += line + "\n"
    if input_buf:
        test_cases.append((input_buf, output_buf))
    return test_cases


def run_tests(target: str, test_cases):
    for test_case in test_cases:
        result = subprocess.run(
            f"./{target}",
            input=test_case[0],
            capture_output=True,
            text=True,
        )

        print(f"{test_case_delimiter}")
        print(f"\033[1mInput:\033[0m\n{test_case[0]}")

        if result.stdout.strip() == test_case[1].strip():
            print("\033[92mPASSED\033[0m")
        else:
            print("\033[91mFAILED\033[0m")
            print(
                # f"\033[1mOutput:\033[0m\n{result.stdout.strip()}\n\033[1mExpected:\033[0m\n{test_case[1].strip()}\n"
                f"\033[1mOutput:\033[0m\n{result.stdout.strip()}\n\033[1mExpected:\033[0m\n{test_case[1].strip()}"
            )
            if result.stderr.strip():
                print(f"\033[1mDebug:\033[0m\n{result.stderr.strip()}")
            # break

    print(test_case_delimiter)


def main():
    parser = argparse.ArgumentParser(
        description="unit tester for competitive programming"
    )
    parser.add_argument(
        "target",
        nargs="?",
        help="cpp program (omit to auto-detect)",
    )
    parser.add_argument(
        "-t",
        "--test-file",
        help="override test file (defaults to <target base>.txt)",
    )
    args = parser.parse_args()

    try:
        if args.target:
            # Allow forms like a, a.cpp, ./a.cpp, path/to/a.cpp
            supplied = os.path.basename(args.target)
            if supplied.endswith(".cpp"):
                supplied = os.path.splitext(supplied)[0]
            target = supplied
        else:
            target = infer_target()
    except Exception as e:
        print(f"[error] {e}")
        return

    try:
        test_filename = determine_test_file(target, args.test_file)
    except Exception as e:
        print(f"[error] {e}")
        return

    print(f"[info] Target: {target}")
    print(f"[info] Test file: {test_filename}")

    # compile cpp program
    result = subprocess.run(["make", target])
    if result.returncode != 0:
        print("[error] build failed")
        return

    # parse test file and run
    test_cases = parse_test_file(test_filename)
    run_tests(target, test_cases)


if __name__ == "__main__":
    main()
