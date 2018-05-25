/**
 * A example of WakeLock use, the class will wake up the screen on of the mobile after sleep 20 secs
 * and print some logs , then release the WakeLock.
 */

package fenton.wakelock;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends AppCompatActivity {

    private void testWakeLock() {
        new Thread(new Runnable() {

            private void printLog() {
                for (int i=0; i<10; i++) {
                    Log.e("fenton", "hello log " + i);
                    try {
                        Thread.sleep(10);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }

            @Override
            public void run() {
                Log.e("fenton", "ready to acquire wakelock!");
                try {
                    Thread.sleep(20000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                TestWakeLock tw1 = new TestWakeLock(MainActivity.this);
                tw1.acquireWakeLock();
                printLog();
                tw1.releaseWakeLock();
            }
        }).start();
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        testWakeLock();
    }
}
