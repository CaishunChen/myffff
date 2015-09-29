package com.mimimao.eric.fixcomma;

import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.hardware.SensorEventListener;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class MainActivity extends AppCompatActivity implements View.OnClickListener,SensorEventListener {

    FixcommA arefFixCom = new FixcommA();

    private SensorManager senSensorManager;
    private Sensor senAccelerometer;

    private long lastUpdate = 0;
    private float last_x, last_y, last_z;
    private static final int SHAKE_THRESHOLD = 600;



    protected void clearResource()
    {
        this.arefFixCom.Close();

        this.arefFixCom.DeleteObject();
    }

    @Override
    protected void onDestroy()
    {
        super.onDestroy();

        this.clearResource();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        findViewById(R.id.Demo).setOnClickListener(this);
        findViewById(R.id.Sensor).setOnClickListener(this);

        senSensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        senAccelerometer = senSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        senSensorManager.registerListener(this, senAccelerometer, SensorManager.SENSOR_DELAY_NORMAL);

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    protected void OnTestSensor() {
        TextView mTextView = (TextView) this.findViewById(R.id.test);

        Boolean lnRet = arefFixCom.Link("192.168.1.107", 17001);

        if (lnRet)
        {
            ByteBuffer loWaves = ByteBuffer.allocate(40960);
            loWaves.order(ByteOrder.LITTLE_ENDIAN);

            ByteBuffer loVibs = ByteBuffer.allocate(40960);
            loVibs.order(ByteOrder.LITTLE_ENDIAN);

            for (int i=0;i<2;i++)
            {
                S_VibCharValue loValue = new S_VibCharValue();
                loValue._fCharAll = 12.34f;
                loValue._fCharHalf = 0;
                loValue._fPhaseHalf = 0;

                loValue._fCharOne = 0;
                loValue._fPhaseOne = 0;

                loValue._fCharTwo =0;
                loValue._fPhaseTwo = 0;

                loValue._fCharThree =0;
                loValue._fPhaseThree = 0;
                loValue._iRev = 1000;
                loValue._fGap = 0;
                loValue._iSmpFreq = 1024;
                loValue._iSmpNum = m_nMaxWaveData;


                loVibs.put(loValue.getBytes());
            }

            arefFixCom.CreateHead(24000);
            arefFixCom.SetItemString(15004, "c");
            arefFixCom.SetItemString(15003, "f");
            arefFixCom.SetItemString(10013, "p");
            arefFixCom.SetItemInt(14019, 0);
            arefFixCom.SetItemInt(14002, 2);
            arefFixCom.SetItemInt(14003, this.m_oWaves.array().length);
            arefFixCom.SetItemInt(10051, 1);
            arefFixCom.SetItemBuf(14012, loVibs.array());
            arefFixCom.SetItemBuf(14001, this.m_oWaves.array());
            arefFixCom.SetItemInt(10084, -1);
            arefFixCom.SetItemString(10009, "1900-01-01 17:00:00");
            arefFixCom.SetItemInt(10086, 123);

            if (arefFixCom.More())
            {
                mTextView.setText("Sensor succeed more");
            }
            else
            {
                mTextView.setText("Sensor failed more");
            }
        } else {
            mTextView.setText("Sensor false");
        }
    }

    protected void OnTestDemo()
    {
        TextView mTextView = (TextView) this.findViewById(R.id.test);

        Boolean lnRet = arefFixCom.Link("192.168.1.107", 17001);

        if (lnRet)
        {
            ByteBuffer loWaves = ByteBuffer.allocate(40960);
            loWaves.order(ByteOrder.LITTLE_ENDIAN);

            ByteBuffer loVibs = ByteBuffer.allocate(40960);
            loVibs.order(ByteOrder.LITTLE_ENDIAN);

            for (int i=0;i<2;i++)
            {
                S_VibCharValue loValue = new S_VibCharValue();
                loValue._fCharAll = 12.34f;
                loValue._fCharHalf = 0;
                loValue._fPhaseHalf = 0;

                loValue._fCharOne = 0;
                loValue._fPhaseOne = 0;

                loValue._fCharTwo =0;
                loValue._fPhaseTwo = 0;

                loValue._fCharThree =0;
                loValue._fPhaseThree = 0;
                loValue._iRev = 1000;
                loValue._fGap = 0;
                loValue._iSmpFreq = 1024;
                loValue._iSmpNum = m_nMaxWaveData;

                for (int j=0;j<loValue._iSmpNum;j++)
                {
                    short lnData = 100;

                    loWaves.putShort(lnData);
                }
                loVibs.put(loValue.getBytes());
            }

            arefFixCom.CreateHead(24000);
            arefFixCom.SetItemString(15004, "c");
            arefFixCom.SetItemString(15003, "f");
            arefFixCom.SetItemString(10013, "p");
            arefFixCom.SetItemInt(14019, 0);
            arefFixCom.SetItemInt(14002, 2);
            arefFixCom.SetItemInt(14003, loWaves.array().length);
            arefFixCom.SetItemInt(10051, 1);
            arefFixCom.SetItemBuf(14012, loVibs.array());
            arefFixCom.SetItemBuf(14001, loWaves.array());
            arefFixCom.SetItemInt(10084, -1);
            arefFixCom.SetItemString(10009, "1900-01-01 17:00:00");
            arefFixCom.SetItemInt(10086, 123);

            if (arefFixCom.More())
            {
                mTextView.setText("Demo succeed more");
            }
            else
            {
                mTextView.setText("Demo failed more");
            }
        } else {
            mTextView.setText("Demo false");
        }
    }

    int m_nMaxWaveData = 512;

    ByteBuffer m_oWaves = null;

    int m_PushedCount = 0;

    @Override
    public void onSensorChanged(SensorEvent sensorEvent)
    {
        Sensor mySensor = sensorEvent.sensor;

        if (mySensor.getType() == Sensor.TYPE_ACCELEROMETER) {
            float x = sensorEvent.values[0];
            float y = sensorEvent.values[1];
            float z = sensorEvent.values[2];

            long curTime = System.currentTimeMillis();

            if ((curTime - lastUpdate) > 1)
            {
                long diffTime = (curTime - lastUpdate);
                lastUpdate = curTime;

                float speed = Math.abs(x + y + z - last_x - last_y - last_z)/ diffTime * 10000;

                if (speed > SHAKE_THRESHOLD) {

                }

                if (this.m_oWaves!=null && this.m_PushedCount>=30)
                {
                   this.OnTestSensor();
                    this.m_oWaves.clear();
                    this.m_PushedCount = 0;
                }else
                {

                }

                if (this.m_oWaves == null  )
                {
                    this.m_oWaves = ByteBuffer.allocate(this.m_nMaxWaveData);

                    this.m_oWaves.order(ByteOrder.LITTLE_ENDIAN);
                }


                short m = (short)(last_x*10);
                last_x = x;

                this.m_oWaves.putShort(m);
                m_PushedCount++;
           //     this.OnTestSensor();
                last_y = y;
                last_z = z;
            }
        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }

    public void onClick(View v)
    {
        switch (v.getId()) {
            case R.id.Demo:
                this.OnTestDemo();
                break;
            case R.id.Sensor:
                this.OnTestSensor();
                break;
            default:
                break;
        }
    }

    protected void onPause()
    {
        super.onPause();
        this.clearResource();
        senSensorManager.unregisterListener(this);
    }

    protected void onResume() {
        super.onResume();
        senSensorManager.registerListener(this, senAccelerometer, SensorManager.SENSOR_DELAY_NORMAL);
    }
}
