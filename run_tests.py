import os
import subprocess
import sys

ROOT_DIR = os.path.dirname(os.path.abspath(__file__))
TEST_DIR = os.path.join(ROOT_DIR, "test")

CXX = "g++"
CXXFLAGS = ["-std=c++17", "-O2", "-Wall"]


def find_tests():
  tests = []
  for root, _, files in os.walk(TEST_DIR):
    for f in files:
      if f.endswith(".test.cpp"):
        tests.append(os.path.join(root, f))
  return tests


def compile_test(test_file):
  exe_file = test_file.replace(".cpp", "")
  cmd = [CXX, test_file, "-o", exe_file] + CXXFLAGS

  result = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
  return result.returncode, exe_file, result.stderr.decode()


def run_test(exe_file, quiet=False):
  if quiet:
    result = subprocess.run(
      [exe_file],
      stdout=subprocess.DEVNULL,
      stderr=subprocess.PIPE
    )
    return result.returncode, "", result.stderr.decode()
  else:
    result = subprocess.run(
      [exe_file],
      stdout=subprocess.PIPE,
      stderr=subprocess.PIPE
    )
  return result.returncode, result.stdout.decode(), result.stderr.decode()


def clean(exe_files):
  for f in exe_files:
    if os.path.exists(f):
      os.remove(f)


def main():
  quiet = "--quiet" in sys.argv or "-q" in sys.argv
  tests = find_tests()

  if not tests:
    print("No tests found.")
    return

  failed = []
  compiled_exes = []

  for test in tests:
    print(f"Running {test} ...")

    # Compile
    code, exe, err = compile_test(test)
    if code != 0:
      print(f"Compile failed: {test}")
      print(err)
      failed.append(test)
      continue

    compiled_exes.append(exe)

    # Run
    code, out, err = run_test(exe, quiet)
    print(out, end="")

    if code != 0:
      print(f"Runtime failed: {test}")
      print(err)
      failed.append(test)
    else:
      print(f"Passed: {test}")

  # Summary
  print("\n====================")
  if not failed:
    print("All tests passed!")
  else:
    print(f"Failed tests ({len(failed)}):")
    for t in failed:
      print(" -", t)

  # Cleanup
  clean(compiled_exes)


if __name__ == "__main__":
  main()