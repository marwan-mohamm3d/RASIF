package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.telephony.SmsManager;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.Switch;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void OnC(View v)
    {
        Log.d("s","function runed0");
        String n = "";
        Switch motorS = (Switch) findViewById(R.id.motor);
       Switch v1 = (Switch) findViewById(R.id.V1);
       Switch v2 = (Switch) findViewById(R.id.V2);
       Switch v3 = (Switch) findViewById(R.id.V3);
       EditText num = (EditText) findViewById(R.id.Number);

            n = n + ((motorS.isChecked()) ? "1":"0");
            n = n + ((v1.isChecked()) ? "1":"0");
            n = n + ((v2.isChecked()) ? "1":"0");
            n = n + ((v3.isChecked()) ? "1":"0");

       Log.d("ting",n);
        SmsManager man = SmsManager.getDefault();
        String number = (String) num.getText().toString();
        man.sendTextMessage(number,null,n,null,null);
    }
}