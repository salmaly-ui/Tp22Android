package com.example.jnibridge;

import android.os.Bundle;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
    }

    // Déclaration des méthodes natives
    public native String getWelcomeMessage();
    public native int calculateProduct(int a, int b);
    public native String transformText(String input);
    public native int sumIntegerArray(int[] numbers);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView resultView = findViewById(R.id.sample_text);

        // Tester les fonctions natives
        String welcome = getWelcomeMessage();
        int product = calculateProduct(7, 8);
        String transformed = transformText("JNI Native Demo");
        int[] values = {2, 4, 6, 8, 10};
        int total = sumIntegerArray(values);

        String output = welcome + "\n\n" +
                "Product (7 x 8) = " + product + "\n\n" +
                "Transformed: " + transformed + "\n\n" +
                "Sum of array: " + total;

        resultView.setText(output);
    }
}