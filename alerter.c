#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

// Stub function to simulate network alert based on temperature in Celsius
int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f Celsius.\n", celcius);
    // Simulate a failure if the temperature is above a certain threshold
    if (celcius > 250) {
        return 500; // Simulate a failure response
    }
    return 200; // Simulate a success response
}

// Function to convert Fahrenheit to Celsius and check alert status
void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // Count failures (currently this line does not increment the count)
        alertFailureCount += 1; // Increment failure count if alert failed
    }
}

void testAlertFailures() {
    alertFailureCount = 0; // Reset before testing

    // Test cases
    alertInCelcius(400.5); // This should trigger a failure (above 250 Celsius)
    assert(alertFailureCount == 1); // Expect 1 failure

    alertInCelcius(303.6); // This should also trigger a failure (above 250 Celsius)
    assert(alertFailureCount == 2); // Expect 2 failures

    alertInCelcius(200); // This should not trigger a failure (below 250 Celsius)
    assert(alertFailureCount == 2); // Expect still 2 failures

    printf("All tests passed successfully!\n");
}

int main() {
    testAlertFailures(); // Run the test cases
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
