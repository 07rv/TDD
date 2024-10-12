class StringCalculator {
  add(numbers) {
    if (!numbers) {
      return 0;
    }

    let delimiter = ",";
    let negativeNumbers = [];
    let sum = 0;

    if (numbers.startsWith("//")) {
      const delimiterIndex = numbers.indexOf("\n");
      delimiter = numbers.substring(2, delimiterIndex);
      numbers = numbers.substring(delimiterIndex + 1);
    }

    numbers = numbers.replace(/\n/g, delimiter);

    const tokens = numbers.split(delimiter);
    for (const token of tokens) {
      if (token) {
        const number = parseInt(token);
        if (number < 0) {
          negativeNumbers.push(number);
        } else {
          sum += number;
        }
      }
    }

    if (negativeNumbers.length > 0) {
      throw new Error(
        `negative numbers not allowed ${negativeNumbers.join(" ")}`
      );
    }

    return sum;
  }
}

class TestCalculator {
  checkTest(testName, testStatus) {
    if (testStatus) {
      console.log(`${testName} - Pass`);
    } else {
      console.log(`${testName} - Fail`);
    }
  }

  testAdd() {
    const calculator = new StringCalculator();

    this.checkTest("Test 1: Empty string", calculator.add("") === 0);

    this.checkTest("Test 2: Single number", calculator.add("1") === 1);

    this.checkTest(
      "Test 3: With ',' delimiter",
      calculator.add("2,4,6,1") === 14
    );

    this.checkTest("Test 4: Newline and comma", calculator.add("1\n2,3") === 6);

    this.checkTest(
      "Test 5: Support custom delimiter",
      calculator.add("//;\n1;2;3") === 6
    );

    let test6Passed = false;
    try {
      calculator.add("1,-2,3");
    } catch (ex) {
      test6Passed = ex.message === "negative numbers not allowed -2";
    }
    this.checkTest("Test 6: Negative numbers", test6Passed);

    let test7Passed = false;
    try {
      calculator.add("1,-2,-3");
    } catch (ex) {
      test7Passed = ex.message === "negative numbers not allowed -2 -3";
    }
    this.checkTest("Test 7: Multiple negative numbers", test7Passed);
  }
}

try {
  const test = new TestCalculator();
  test.testAdd();
} catch (e) {
  console.log(e.message);
}
