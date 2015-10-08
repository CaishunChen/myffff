package com.mimimao.eric.fixcomma;

import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.hardware.SensorEventListener;

import org.apache.commons.collections4.queue.CircularFifoQueue;
import com.tendcloud.tenddata.TCAgent;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Timer;
import java.util.TimerTask;

public class MainActivity extends AppCompatActivity implements View.OnClickListener,SensorEventListener {



    private SensorManager senSensorManager;
    private Sensor senAccelerometer;

    private long lastUpdate = 0;
    private float last_x, last_y, last_z;
    private static final int SHAKE_THRESHOLD = 600;

    public  String m_strIP = "192.168.1.107";

    int m_nMaxWaveData = 256;


    private Queue<Byte> m_oWaveBuffers = null;

    protected synchronized void resetWaveBuffer()
    {

        if (null == this.m_oWaveBuffers)
        {
            this.m_oWaveBuffers = new CircularFifoQueue<>(this.m_nMaxWaveData*2);
        }

        int lnDataSize = this.m_nMaxWaveData*2;

        for (int i=0;i<lnDataSize;i++)
        {
            this.m_oWaveBuffers.add((byte)0);
        }
    }

    protected void clearResource()
    {

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

        TCAgent.LOG_ON=true;
        TCAgent.init(this);
        TCAgent.setReportUncaughtExceptions(true);

        findViewById(R.id.Demo).setOnClickListener(this);
        findViewById(R.id.Sensor).setOnClickListener(this);
        findViewById(R.id.Demo20025).setOnClickListener(this);

        senSensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        senAccelerometer = senSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        senSensorManager.registerListener(this, senAccelerometer, SensorManager.SENSOR_DELAY_NORMAL);

        EditText loIp = (EditText) this.findViewById(R.id.IP_Address);
        if (null!=loIp)
        {
            loIp.setText(this.m_strIP);
        }

        this.resetWaveBuffer();

        TimerTaskTest loTask = new TimerTaskTest(this);

        Timer timer = new Timer();

        timer.schedule(loTask,2000,50);
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

    protected  void OnTestSensor()
    {
       FixcommA arefFixCom = new FixcommA();

        try
        {

            Boolean lnRet = arefFixCom.Link(this.m_strIP, 17001);

            if (lnRet)
            {
                ByteBuffer loWaves = ByteBuffer.allocate(40960);
                loWaves.order(ByteOrder.LITTLE_ENDIAN);

                ByteBuffer loVibs = ByteBuffer.allocate(40960);
                loVibs.order(ByteOrder.LITTLE_ENDIAN);


                ArrayList<Byte> loList = null;

                int lnDataSize = 0;

                ByteBuffer loTemp = null;

                float lfMax = 0;

                synchronized(this)
                {

                    try
                    {
                        loList = new ArrayList<>(this.m_oWaveBuffers);
                    }catch (Exception e3)
                    {
                        Log.e("eeeee",e3.getMessage());
                    }


                    lnDataSize = this.m_oWaveBuffers.size();

                    loTemp = ByteBuffer.allocate(loList.size());

                    loTemp.order(ByteOrder.LITTLE_ENDIAN);

                    for (int i=0;i<loList.size();i++)
                    {
                        loTemp.put(loList.get(i));
                    }

                    loTemp.flip();

                }

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

                loVibs.flip();

                arefFixCom.CreateHead(24000);
                arefFixCom.SetItemString(15004, "c");
                arefFixCom.SetItemString(15003, "f");
                arefFixCom.SetItemString(10013, "p");
                arefFixCom.SetItemInt(14019, 0);
                arefFixCom.SetItemInt(14002, 2);
                arefFixCom.SetItemInt(14003, lnDataSize);
                arefFixCom.SetItemInt(10051, 1);
                arefFixCom.SetItemBuf(14012, loVibs.array());
                arefFixCom.SetItemBuf(14001, loTemp.array());
                arefFixCom.SetItemInt(10084, -1);
                arefFixCom.SetItemString(10009, "1900-01-01 17:00:00");
                arefFixCom.SetItemInt(10086, 123);

                if (arefFixCom.More())
                {

                }
                else
                {

                }
            } else
            {

            }
        }catch(Exception e0)
        {
            TCAgent.onError(this,e0);

        }finally
        {
            arefFixCom.Close();
            arefFixCom.DeleteObject();
            arefFixCom = null;
        }


    }

    protected void OnTest20025()
    {
        FixcommA arefFixCom = new FixcommA();

        TextView mTextView = (TextView) this.findViewById(R.id.test);

        Boolean lnRet = arefFixCom.Link(this.m_strIP, 17001);



            arefFixCom.CreateHead(20025);


            while (arefFixCom.More())
            {
                String lstrCompany = arefFixCom.GetItemString(15004);
                String lstrFactory = arefFixCom.GetItemString(15003);
                String lstrPlant = arefFixCom.GetItemString(10013);
                mTextView.setText("Demo succeed more:" + lstrCompany + "|"+lstrFactory+"|"+lstrPlant);
            }

        arefFixCom.Close();
        arefFixCom.DeleteObject();
        arefFixCom = null;
    }

    protected void OnTestDemo()
    {
        TextView mTextView = (TextView) this.findViewById(R.id.test);

        FixcommA arefFixCom = new FixcommA();

        Boolean lnRet = arefFixCom.Link(this.m_strIP, 17001);

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
            arefFixCom.SetItemString(15004, "测试");
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

        arefFixCom.Close();
        arefFixCom.DeleteObject();
        arefFixCom = null;
    }

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



                if (speed > SHAKE_THRESHOLD)
                {

                }

                if (this.m_PushedCount>=5)
                {
                  //  this.OnTestSensor();

                    this.m_PushedCount = 0;

                }else
                {

                }

                short m = (short)(speed*10);
                last_x = x;

                m_PushedCount++;

                ByteBuffer loTemp = ByteBuffer.allocate(2);

                loTemp.order(ByteOrder.LITTLE_ENDIAN);

                loTemp.putShort(m);

                synchronized (this)
                {
                    this.m_oWaveBuffers.add(loTemp.get(0));

                    this.m_oWaveBuffers.add(loTemp.get(1));
                }

                last_y = y;
                last_z = z;
            }
        }
    }

    class TimerTaskTest extends java.util.TimerTask
    {
        MainActivity m_pOuter= null;
        public  TimerTaskTest(MainActivity arefOuter)
        {
            this.m_pOuter = arefOuter;
        }
        public void run()
        {
            try
            {
                this.m_pOuter.OnTestSensor();

            }catch (Exception e)
            {

            }
        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }

    public void onClick(View v)
    {
        EditText loIp = (EditText) this.findViewById(R.id.IP_Address);
        if (null!=loIp)
        {
            this.m_strIP = loIp.getText().toString();
        }
        switch (v.getId()) {
            case R.id.Demo:
                this.OnTestDemo();
                break;
            case R.id.Sensor:
                this.OnTestSensor();
                break;
            case R.id.Demo20025:
                this.OnTest20025();
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
