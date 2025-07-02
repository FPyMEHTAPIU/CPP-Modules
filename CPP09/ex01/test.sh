#!/bin/bash

PROGRAM="./RPN"

TESTS=(
  "1 2 +|3"
  "1 2 + 2 *|6"
  "4 2 /|2"
  "5 1 2 + 4 * + 3 -|14"
  "3 4 + 2 * 7 /|2"
  "2 3 + 5 *|25"
  "2 3 -|-1"
  "-3 2 *|-6"
  "-3 -2 *|6"
  "9 -9 +|0"
  "9 9 +|18"
  "10 1 +|Error"
  "-10 1 +|Error"
  "a b +|Error"
  "1 2|Error"
  "4 0 /|Error"
  "1 2 + +|Error"
  "9 1 -|8"
  "8 3 -|5"
  "-5 -5 +|-10"
  "7 2 /|3"
  "-8 4 /|-2"
  "2 3 * 4 +|10"
  "1 2 + 3 + 4 +|10"
  "9 2 - 3 - 1 -|3"
  "2 3 + 4 * 5 -|15"
  "5 1 2 + 4 * + 3 -|14"
  "3 3 * 3 /|3"
  "0 1 - 1 -|-2"
  "5 5 - 5 +|5"
  "2 2 + 2 + 2 + 2 +|10"
  "1 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 +|10"
  "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 +|45"
  "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 1 +|46"
  "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 10 +|Error"
  "1 2 + +|Error"
  "1 +|Error"
  "+|Error"
  "|Error"
  "1 2 + 3 /|1"
  "-1 -2 +|-3"
  "-3 -3 +|-6"
  "3 -3 +|0"
  "3 -4 *|-12"
  "3 0 /|Error"
)

pass=0
fail=0

echo "Running tests..."
for test in "${TESTS[@]}"; do
  input="${test%%|*}"
  expected="${test##*|}"

  output=$($PROGRAM "$input" 2>&1 | tr -d '\r' | xargs)

  if [[ "$output" == "$expected" ]]; then
    echo "[PASS] '$input' => $output"
    ((pass++))
  else
    echo "[FAIL] '$input' => got: '$output', expected: '$expected'"
    ((fail++))
  fi
done

echo
echo "Tests passed: $pass"
echo "Tests failed: $fail"

if [ "$fail" -eq 0 ]; then
  exit 0
else
  exit 1
fi
